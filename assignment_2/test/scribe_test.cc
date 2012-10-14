#include "gtest/gtest.h"
#include <fstream>
#include "scribe.h"

TEST(Scribe, FauxTest) {
  EXPECT_EQ(1, 1);
}

TEST(Scribe, OpenExistingFile) {
	std::ofstream test_file ("test_file.txt");
	if(test_file.is_open()) {
		test_file << "Test line.\n";
		test_file << "And another.";
	} else std::cout << "Unable to create test file";
	test_file.close();

	Scribe myEditor = Scribe();
	myEditor.open_file("test_file.txt");

	EXPECT_EQ("Test line.\nAnd another.\n", myEditor.get_file_contents());
}

TEST(Scribe, MarkStateOfBuffer) {
	std::ofstream test_file ("test_file.txt");
	if(test_file.is_open()) {
		test_file << "Test line.\n";
		test_file << "And another.";
	} else std::cout << "Unable to create test file";
	test_file.close();

	Scribe myEditor = Scribe("test_file.txt");

	myEditor.mark();
	myEditor.add_line("Some more text");

	EXPECT_EQ("Test line.\nAnd another.\nSome more text\n", myEditor.get_file_contents());

	myEditor.undo();

	EXPECT_EQ("Test line.\nAnd another.\n", myEditor.get_file_contents());
}

TEST(Scribe, UndoNothing) {
	std::ofstream test_file ("test_file.txt");
	if(test_file.is_open()) {
		test_file << "Test line.\n";
		test_file << "And another.";
	} else std::cout << "Unable to create test file";
	test_file.close();

	Scribe myEditor = Scribe("test_file.txt");

	myEditor.mark();

	EXPECT_EQ("Test line.\nAnd another.\nSome more text\n", myEditor.get_file_contents());

	myEditor.undo();

	EXPECT_EQ("Test line.\nAnd another.\nSome more text\n", myEditor.get_file_contents());
}