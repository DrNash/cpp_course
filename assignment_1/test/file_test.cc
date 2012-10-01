#include "gtest/gtest.h"
#include "file.h"


// Helpers
void validateVectorEquality(std::vector<std::string> expected, std::vector<std::string> given) {
	std::vector<std::string>::iterator expectIt;
	std::vector<std::string>::iterator giveIt;


	giveIt = given.begin();
	for(expectIt = expected.begin(); expectIt < expected.end(); expectIt++) {
		EXPECT_EQ(*expectIt, *giveIt);
		giveIt++;
	}
}

TEST(File, TypedefTest) {
	std::vector<std::string> expectedVector;
	expectedVector.push_back("a_test_string");

	File realFile;
	realFile.push_back("a_test_string");

	validateVectorEquality(expectedVector, realFile);
}

TEST(File, ReadIntoFile) {
	File someFile;
	std::ifstream file_stream ("file_test.cc");
}