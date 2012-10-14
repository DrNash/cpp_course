class Scribe {
private:
	std::vector<std::string> editor_buffer;
	std::vector<std::string> undo_buffer;

public:
	Scribe() {}
	Scribe(std::string);
	void open_file(std::string filename);
	void mark();
	void undo();
	std::string get_file_contents();
	void add_line(std::string line);
};