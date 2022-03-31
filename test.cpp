#include "gtest/gtest.h"

#include "challenge.h"

TEST(UnitTests, defaultParamTest) {
	Challenge challenge;

	ASSERT_EQ(challenge.doSomethingWithInt(), 21);
	ASSERT_NE(challenge.doSomethingWithInt(), 20);
}