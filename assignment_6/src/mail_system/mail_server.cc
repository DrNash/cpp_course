#include "mail_server.h"

MailServer::MailServer() {
}

std::vector<Message> MailServer::get_mail(std::string user) {
	std::vector<Message> user_messages;
	user_messages = messages[user];
	return user_messages;
}

bool MailServer::add_message(std::string user, Message msg) {
	messages[user].push_back(msg);
	return true;
}