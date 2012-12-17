#include "gtest/gtest.h"
#include "mail_system/mail_server.h"

TEST(MailServer, GetMailForUserWithNoMail) {
	MailServer m_serv;

	std::vector<Message> returned_messages = m_serv.get_mail("ryan");

	// using 0Lu just so compiler stops complaining about comparison
	EXPECT_EQ(0Lu, returned_messages.size());
}

TEST(MailServer, AddMailToServer) {
	MailServer m_serv;

	std::vector<std::string> to_vec;
	to_vec.push_back("ryan");

	Message message(to_vec, "a subject");
	EXPECT_TRUE(m_serv.add_message(message.get_to()[0], message));
}

TEST(MailServer, AddMailAndConfirm) {
	MailServer m_serv;

	std::vector<std::string> to_vec;
	to_vec.push_back("ryan");

	Message message(to_vec, "a subject");
	EXPECT_TRUE(m_serv.add_message(message.get_to()[0], message));

	std::vector<Message> ryans_messages = m_serv.get_mail("ryan");

	EXPECT_EQ(ryans_messages[0].get_subject(), "a subject");
}