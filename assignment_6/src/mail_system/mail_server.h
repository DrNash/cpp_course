#include <map>
#include <vector>
#include "message.h"

class MailServer {
private:
	std::map<std::string, std::vector<Message> > messages;

	// Private undefined copy constructor to prevent copies
	MailServer(const MailServer&);
	
public:
	// Default c'tor
	MailServer();
	std::vector<Message> get_mail(std::string);
	bool add_message(std::string, Message);
};