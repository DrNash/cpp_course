
#include "scribe.h"

Scribe::Scribe(std::string filename) {
	open_file(filename);
}

void Scribe::open_file(std::string filename) {
	std::string buffer;
	std::ifstream file (filename.c_str());
	if(file.is_open()) {
		while (file.good()) {
			getline(file, buffer);
				add_line(buffer);
		}
		file.close();
	} else std::cout << "Unable to open file " + filename;
}

void Scribe::mark() {
	undo_buffer.clear();
	undo_buffer = text_container (editor_buffer);
}

void Scribe::undo() {
	editor_buffer.clear();
	editor_buffer = text_container (undo_buffer);
}

void Scribe::add_line(std::string line) {
	editor_buffer.push_back(line +"\n");
}

void Scribe::mark_portion(std::string start, std::string end) {
	text_container::iterator it;
	std::string buffer;
	clipping.clear();

	for(it = editor_buffer.begin(); it != editor_buffer.end(); ++it) {
		size_t start_pos = (*it).find(start);
		if(start_pos != std::string::npos) {
			buffer += (*it).substr(start_pos);
			size_t end_pos = buffer.find(end);
			if(end_pos != std::string::npos) {
				clipping = buffer.substr(0, end_pos + end.length());
				return;
			} else {
				clipping += buffer;
				text_container::iterator it2;
				for(it2 = ++it; it2 != editor_buffer.end(); ++it2) {
					end_pos = (*it2).find(end);
					if(end_pos != std::string::npos) {
						clipping += (*it2).substr(0,end_pos + end.length());
					} else {
						clipping += *it2; 
					}
				}
				--it;
			}
		}
	}
}

void Scribe::insert(std::string insert_str) {
	if(clipping.length() > 0) {
		text_container::iterator it;
		for(it = editor_buffer.begin(); it != editor_buffer.end(); ++it) {
			size_t start_pos = (*it).find(insert_str);
			if(start_pos != std::string::npos) {
				(*it).insert(start_pos + insert_str.length(), clipping);

				// assuming first occurence only
				return;
			}
		}
	}
}

void Scribe::delete_phrase(std::string dead_words) {
	text_container::iterator it;
	for(it = editor_buffer.begin(); it != editor_buffer.end(); ++it) {
		size_t start_pos = (*it).find(dead_words);
		while(start_pos != std::string::npos) {
			(*it).erase(start_pos, dead_words.length());
			start_pos = (*it).find(dead_words);
		}
	}
}

void Scribe::substitute_phrase(std::string dead_phrase, std::string new_phrase) {
	text_container::iterator it;
	for(it = editor_buffer.begin(); it != editor_buffer.end(); ++it) {
		size_t start_pos = (*it).find(dead_phrase);
		while(start_pos != std::string::npos) {
			(*it).replace(start_pos, dead_phrase.length(), new_phrase);
			start_pos = (*it).find(dead_phrase, start_pos + new_phrase.length());
		}
	}
}

std::string Scribe::retrieve_portion() {
	return clipping;
}

std::string Scribe::get_file_contents() {
	std::string collapsed_text;

	text_container::iterator it;
	it = editor_buffer.begin();

	for(; it != editor_buffer.end(); ++it) {
		collapsed_text += *it;
	}

	return collapsed_text;
}