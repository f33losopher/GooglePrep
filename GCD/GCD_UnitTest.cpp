/*
 * GCD_UnitTest.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: Felix
 */

#include "GCD.h"
#include "gtest/gtest.h"

using namespace GCD;

TEST(GCD, gcd) {
	EXPECT_EQ(5, gcd(15,20));
	EXPECT_EQ(9, gcd(18,27));
}

TEST(GCD, otherGcd) {
	EXPECT_EQ(5, gcd(15,20));
	EXPECT_EQ(9, gcd(18,27));
}

TEST(GCD, LCM) {
	EXPECT_EQ(150, LCM(50,75));
}
