#include "../people/directory.h"
#include "mail_server.h"
#include <vector>

class MailClient {
private:
	User user;
	MailServer server;
	std::vector<Message> inbox;
	std::vector<Message> outbox;

public:
	Message new_message();
	bool send_message(Message);
	std::vector<Message> get_mail();
	bool delete_message(Message);
	Message edit_message(Message);
};