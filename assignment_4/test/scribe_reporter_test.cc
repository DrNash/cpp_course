#include "gtest/gtest.h"
#include <scribe_reporter.h>

TEST(ScribeReporter, ReportOnEmptyScribe) {
	ScribeReporter myReporter = ScribeReporter("");

	EXPECT_EQ(0, myReporter.total_words());
	EXPECT_EQ(0, myReporter.occurences_of_word("yoyo"));
}

TEST(ScribeReporter, ReportOnWordCount) {
	ScribeReporter myReporter = ScribeReporter("one two three");
	EXPECT_EQ(3, myReporter.total_words());

	ScribeReporter myReporter2 = ScribeReporter("one one one");
	EXPECT_EQ(3, myReporter2.total_words());
}

TEST(ScribeReporter, ReportOnSpecificWordCounts) {
	ScribeReporter myReporter = ScribeReporter("one two two three three three");

	EXPECT_EQ(1, myReporter.occurences_of_word("one"));
	EXPECT_EQ(2, myReporter.occurences_of_word("two"));
	EXPECT_EQ(3, myReporter.occurences_of_word("three"));
}

TEST(ScribeReporter, PrintHeader) {
	ScribeReporter myReporter = ScribeReporter("one");
	EXPECT_EQ("Words          Count          Stars (each worth 1)"
		"          \n", myReporter.header());
}

TEST(ScribeReporter, PrintingWordsAndCounts) {
	ScribeReporter myReporter = ScribeReporter("one two two three three three");

	EXPECT_EQ("one            1              *"
			  "                             \n"
			  "three          3              ***"
			  "                           \n"
			  "two            2              **"
			  "                            \n", 
			  myReporter.formatted_words_counts_and_stars());	
}

TEST(ScribeReporter, StarsScaledByMax) {
	ScribeReporter myReporter = ScribeReporter("one two two three three three");

	EXPECT_EQ("*", myReporter.stars_for_word("one"));
	EXPECT_EQ("**", myReporter.stars_for_word("two"));
	EXPECT_EQ("***", myReporter.stars_for_word("three"));

	ScribeReporter myLargerReporter = ScribeReporter(
		"a a a a a a a a a a a a a a a a a a a a a a a a a a "
		"a a a a a a a a b b b b b b b c c c c c c c c c c c ");
	// 34 a's 7 b's 11 c's

	EXPECT_EQ("*****************", myLargerReporter.stars_for_word("a"));
	EXPECT_EQ("***", myLargerReporter.stars_for_word("b"));
	EXPECT_EQ("*****", myLargerReporter.stars_for_word("c"));
}

TEST(ScribeReporter, GetScaleFactor) {
	ScribeReporter myLargerReporter = ScribeReporter(
		"a a a a a a a a a a a a a a a a a a a a a a a a a a "
		"a a a a a a a a b b b b b b b c c c c c c c c c c c ");
	// 34 a's 7 b's 11 c's

	EXPECT_EQ(2, myLargerReporter.get_scale());
}