#include "gtest/gtest.h"
#include <fstream>
#include "scribe.h"

bool create_test_file_with_text(std::string filename, std::string file_contents) {
	std::ofstream test_file (filename.c_str());
	if(test_file.is_open()) {
		test_file << file_contents;
	} else { 
		std::cout << "Unable to create test file";
		return false;
	}
	test_file.close();
	return true;
}

TEST(Scribe, OpenExistingFile) {
	create_test_file_with_text("test/test_file.txt", "Test line.\nAnd another.");

	Scribe myEditor = Scribe();
	myEditor.open_file("test/test_file.txt");

	EXPECT_EQ("Test line.\nAnd another.\n", myEditor.get_file_contents());
}

TEST(Scribe, MarkAndUndo) {
	create_test_file_with_text("test/test_file.txt", "Test line.\nAnd another.");

	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.mark();
	myEditor.add_line("Some more text");

	EXPECT_EQ("Test line.\nAnd another.\nSome more text\n", myEditor.get_file_contents());

	myEditor.undo();

	EXPECT_EQ("Test line.\nAnd another.\n", myEditor.get_file_contents());
}

TEST(Scribe, UndoNothing) {
	create_test_file_with_text("test/test_file.txt", "Test line.\nAnd another.");

	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.mark();

	EXPECT_EQ("Test line.\nAnd another.\n", myEditor.get_file_contents());

	myEditor.undo();

	EXPECT_EQ("Test line.\nAnd another.\n", myEditor.get_file_contents());
}

TEST(Scribe, MarkTwice) {
	create_test_file_with_text("test/test_file.txt", "Test line.\nAnd another.");

	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.mark();
	myEditor.add_line("Some more text");
	myEditor.mark();
	myEditor.add_line("Even moooooore");

	EXPECT_EQ("Test line.\nAnd another.\nSome more text\nEven moooooore\n", myEditor.get_file_contents());

	myEditor.undo();

	EXPECT_EQ("Test line.\nAnd another.\nSome more text\n", myEditor.get_file_contents());
}

TEST(Scribe, MarkPortion) {
	create_test_file_with_text("test/test_file.txt", "In lorem Ipsum das doo faux fum.");

	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.mark_portion("lorem", "faux");
	EXPECT_EQ("lorem Ipsum das doo faux", myEditor.retrieve_portion());
}

TEST(Scribe, MarkPortionAcrossLines) {
	create_test_file_with_text("test/test_file.txt", "In lorem\nIpsum doo das\nfaux fum.");

	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.mark_portion("lorem", "faux");
	EXPECT_EQ("lorem\nIpsum doo das\nfaux", myEditor.retrieve_portion());

}

TEST(Scribe, InsertMarkedPortion) {
	create_test_file_with_text("test/test_file.txt", "In lorem\nIpsum doo das\nfaux fum.");

	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.mark_portion("lorem", "faux");
	myEditor.insert("faux fum.");

	EXPECT_EQ("In lorem\nIpsum doo das\nfaux fum.lorem\nIpsum doo das\nfaux\n", myEditor.get_file_contents());
}

TEST(Scribe, InsertInMiddle) {
	create_test_file_with_text("test/test_file.txt", 
		"In lorem\n"
		"Ipsum doo das\n"
		"faux fum.");

	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.mark_portion("In", "lorem");
	myEditor.insert("do");

	EXPECT_EQ("In lorem\nIpsum doIn loremo das\nfaux fum.\n", myEditor.get_file_contents());
}

TEST(Scribe, DeletePhrase) {
	create_test_file_with_text("test/test_file.txt", 
		"In lorem\n"
		"Ipsum doo das\n"
		"In lorem\n"
		"In lorem In loremfaux fum.");
	
	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.delete_phrase("In lorem");

	EXPECT_EQ("\nIpsum doo das\n\n faux fum.\n", myEditor.get_file_contents());

}

TEST(Scribe, SubstitutePhrase) {
	create_test_file_with_text("test/test_file.txt", 
		"In lorem\n"
		"Ipsum doo das\n"
		"In lorem\n"
		"In lorem In loremfaux fum.");
	
	Scribe myEditor = Scribe("test/test_file.txt");
	myEditor.substitute_phrase("In lorem", "donkey");

	EXPECT_EQ("donkey\nIpsum doo das\ndonkey\ndonkey donkeyfaux fum.\n", myEditor.get_file_contents());
}