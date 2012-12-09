class Message {
private:
	std::string subject;
	std::string body;
	std::string to[];
	std::string from;

public:
	std::string get_subject();
	std::string get_body();
	std::string get_to();
	std::string get_from();

	void set_subject(std::string);
	void set_body(std::string);
	void set_to(std::string[]);
	void set_from(std::string);
	void add_to(std::string);

	std::string view();
};