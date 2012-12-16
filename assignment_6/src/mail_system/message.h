#include <string>

class Message {
private:
	std::string subject;
	std::string body;
	std::vector<std::string> to;
	std::string from;

public:
	// Constructors
	Message(std::vector<std::string>, std::string);

	std::string get_subject();
	std::string get_body();
	std::vector<std::string> get_to();
	std::string get_from();

	void set_subject(std::string);
	void set_body(std::string);
	void set_to(std::vector<std::string>);
	void set_from(std::string);
	void add_to(std::string);

	std::string view();
};