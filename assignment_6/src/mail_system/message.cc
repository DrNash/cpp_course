#include "message.h"

Message::Mesage(std::vector<std::string> p_to, std::string p_subject) {
	to = p_to;
	subject = p_subject;
}

std::vector<std::string>Message::get_to() {
	return to;
}