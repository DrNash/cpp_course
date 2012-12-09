#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

class ScribeReporter {
public:
	// Default c'tor
	ScribeReporter();
	// C'tor from string
	ScribeReporter(std::string);
	void load_scribe_buffer(std::string);
	int total_words();
	int occurences_of_word(std::string);
	std::string formatted_words_counts_and_stars();
	std::string stars_for_word(std::string); 
	std::string header();
	int get_scale();

private:
	std::string body;
	std::map<std::string,int> word_map;
	int word_count, max_word;
	void chomp(std::string&);
};