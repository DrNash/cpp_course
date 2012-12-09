#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include "scribe_reporter.h"

class Scribe {
	typedef std::vector<std::string> text_container;
private:
	text_container editor_buffer;
	text_container undo_buffer;
	std::string clipping;

public:
	Scribe() {}
	Scribe(std::string);
	void open_file(std::string filename);
	void mark();
	void undo();
	void mark_portion(std::string, std::string);
	void insert(std::string);
	void delete_phrase(std::string);
	void substitute_phrase(std::string, std::string);

	void show_word_stats();
	std::string retrieve_portion();
	std::string get_file_contents();
	void add_line(std::string line);
};