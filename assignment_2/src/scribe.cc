#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	undo_buffer = std::vector<std::string>(editor_buffer);
}

void Scribe::undo() {
	editor_buffer.clear();
	editor_buffer = std::vector<std::string>(undo_buffer);
}

void Scribe::add_line(std::string line) {
	editor_buffer.push_back(line +"\n");
}

std::string Scribe::get_file_contents() {
	std::string collapsed_vector;

	std::vector<std::string>::iterator it;
	it = editor_buffer.begin();

	for(; it < editor_buffer.end(); ++it) {
		collapsed_vector += *it;
	}

	return collapsed_vector;
}