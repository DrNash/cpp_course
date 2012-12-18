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

	EXPECT_EQ("a subject", ryans_messages[0].get_subject());
}

TEST(MailServer, MailForSeveralUsers) {
	MailServer m_serv;
	std::vector<std::string> to_vec;
	to_vec.push_back("ryan");

	Message msg1(to_vec, "msg 1 subject");
	EXPECT_TRUE(m_serv.add_message(msg1.get_to()[0], msg1));

	to_vec.push_back("kristine");
	Message msg2(to_vec, "msg 2 subject");

	EXPECT_TRUE(m_serv.add_message(msg2.get_to()[0], msg2));
	EXPECT_TRUE(m_serv.add_message(msg2.get_to()[1], msg2));

	std::vector<Message> ryans_messages = m_serv.get_mail("ryan");
	std::vector<Message> kristines_messages = m_serv.get_mail("kristine");

	EXPECT_EQ("msg 1 subject", ryans_messages[0].get_subject());
	EXPECT_EQ("msg 2 subject", ryans_messages[1].get_subject());
	EXPECT_EQ("msg 2 subject", kristines_messages[0].get_subject());
}

TEST(MailServer, DeleteMessage) {
	MailServer m_serv;
	std::vector<std::string> to_vec;
	to_vec.push_back("ryan");

	Message msg1(to_vec, "msg 1 subject");
	EXPECT_TRUE(m_serv.add_message(msg1.get_to()[0], msg1));

	to_vec.push_back("kristine");
	Message msg2(to_vec, "msg 2 subject");

	EXPECT_TRUE(m_serv.add_message(msg2.get_to()[0], msg2));
	EXPECT_TRUE(m_serv.add_message(msg2.get_to()[1], msg2));

	std::vector<Message> ryans_messages = m_serv.get_mail("ryan");
	std::vector<Message> kristines_messages = m_serv.get_mail("kristine");

	EXPECT_EQ(2Lu, ryans_messages.size());
	EXPECT_EQ(1Lu, kristines_messages.size());

	// m_serv.delete_message(ryans_messages[0].msg_key());

	// EXPECT_EQ(1Lu, ryans_messages.size());
}