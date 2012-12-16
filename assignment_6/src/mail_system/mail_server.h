#include <map>
#include <vector>
#include "message.h"

class MailServer {
private:
	std::map<std::string, Message> messages;

public:
	std::vector<Message> get_mail(std::string);
	bool add_message(std::string, Message);
};