#include "scribe_reporter.h"

ScribeReporter::ScribeReporter() {
	word_count = 0;
	max_word = 0;
}

ScribeReporter::ScribeReporter(std::string text) {
	load_scribe_buffer(text);
}

void ScribeReporter::load_scribe_buffer(std::string text) {
	body = text;
	word_count = 0;
	max_word = 0;

	std::stringstream ss(body);
    std::string item;
    
    std::pair<std::map<std::string,int>::iterator,bool> success;

    while(std::getline(ss, item, ' ')) {
    	chomp(item);
 
 		if(item.empty()) continue;
    	success = word_map.insert(std::pair<std::string,int>(item, 1));
    	if(success.second == false) {
    		word_map[item] = word_map[item] + 1;
    	}
    	if(word_map[item] > max_word)
    		max_word = word_map[item];

    	word_count += 1;
    }
}
int ScribeReporter::total_words() {
    return word_count;
}

int ScribeReporter::occurences_of_word(std::string word) {
	return word_map[word];
}

std::string ScribeReporter::formatted_words_counts_and_stars() {
	std::map<std::string,int>::iterator it;
	std::ostringstream output;  

	for(it = word_map.begin(); it != word_map.end(); ++it) {
		output.width(15);
		output << std::left << (*it).first;
		output.width(15);
		output << std::left << (*it).second;
		output.width(30);
		output << std::left << stars_for_word((*it).first) << "\n";
	}
	return output.str();
}

std::string ScribeReporter::stars_for_word(std::string word) {
	std::string stars;

	int scale = max_word / 15;
	if(scale == 0) scale = 1;

	for(int i = 0; i < (occurences_of_word(word)/scale); ++i)
		stars += "*";

	return stars;
}

std::string ScribeReporter::header() {
	std::ostringstream star_string;
	star_string << "Stars (each worth " << get_scale() << ")";
	std::ostringstream output;
	output.width(15);
	output << std::left << "Words";
	output.width(15);
	output << std::left << "Count";
	output.width(30);
	output << std::left << star_string.str();
	output << "\n";

	return output.str();
}

int ScribeReporter::get_scale() {
	if(max_word < 15)
		return 1; 
	else
		return max_word / 15;
}

void ScribeReporter::chomp(std::string &word) {
	std::string whitespaces = (" \t\f\v\n\r");
    size_t found;

    found=word.find_last_not_of(whitespaces);
	if (found!=std::string::npos)
		word.erase(found+1);
	else
		word.clear();

	found=word.find_first_not_of(whitespaces);
	if (found!=std::string::npos)
		word.erase(0, found);
	else
		word.clear();

	 found=word.find_first_of(whitespaces);
	 while (found!=std::string::npos) {
	 	word[found]='_';
	    found=word.find_first_of(whitespaces,found+1);
	 }
}