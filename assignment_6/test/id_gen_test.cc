#include "gtest/gtest.h"
#include "mail_system/id_gen.h"

TEST(IDGen, GenerateID) {
	IDGen::clear();
	long id = IDGen::get_id();

	EXPECT_EQ(0L, id);

	long next_id = IDGen::get_id();
	EXPECT_EQ(1L, id);
}