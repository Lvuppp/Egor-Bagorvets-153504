#include "pch.h"
#include"Functions.h"


TEST(TestCase6, Test1) {
	EXPECT_EQ(recursiveSum(1,10), 46);
	EXPECT_TRUE(true);
}
TEST(TestCase6, Test2) {
	EXPECT_EQ(recursiveSum(10,20), 48);
	EXPECT_TRUE(true);
}
TEST(TestCase6, Test3) {
	EXPECT_EQ(recursiveSum(20,30), 50);
	EXPECT_TRUE(true);
}
TEST(TestCase6, Test4) {
	EXPECT_EQ(recursiveSum(30,40), 52);
	EXPECT_TRUE(true);
}
TEST(TestCase6, Test5) {
	EXPECT_EQ(recursiveSum(1,100), 496);
	EXPECT_TRUE(true);
}
TEST(TestCase6, Test6) {
	EXPECT_EQ(recursiveSum(1,2), 3);
	EXPECT_TRUE(true);
}
TEST(TestCase6, Test7) {
	EXPECT_EQ(recursiveSum(2147483647, 2147483647), 7);
	EXPECT_TRUE(true);
}


TEST(TestCase7, Test1) {
	EXPECT_EQ(recurse(1234, 1234 % (long long)pow(10, 4),(long long)pow(10,4)),736);
	EXPECT_TRUE(true);
}
TEST(TestCase7, Test2) {
	EXPECT_EQ(recurse(2323, 99999999999 % (long long)pow(10, 8), (long long)pow(10, 8)), 39087387);
	EXPECT_TRUE(true);
}
TEST(TestCase7, Test3) {
	EXPECT_EQ(recurse(4, 99999 % (long long)pow(10, 9), (long long)pow(10, 9)), 494777344);
	EXPECT_TRUE(true);
}
TEST(TestCase7, Test4) {
	EXPECT_EQ(recurse(888, 888 % (long long)pow(10, 8), (long long)pow(10, 8)), 91255296);
	EXPECT_TRUE(true);
}


TEST(TestCase8, Test1) {
	EXPECT_EQ(recursiveSum(7), 21);
	EXPECT_TRUE(true);
}
TEST(TestCase8, Test2) {
	EXPECT_EQ(recursiveSum(1), 1);
	EXPECT_TRUE(true);
}
TEST(TestCase8, Test3) {
	EXPECT_EQ(recursiveSum(777), 201537);
	EXPECT_TRUE(true);
}
TEST(TestCase8, Test4) {
	EXPECT_EQ(recursiveSum(11111), 41158121);
	EXPECT_TRUE(true);
}
TEST(TestCase8, Test5) {
	EXPECT_EQ(recursiveSum(1234), 507828);
	EXPECT_TRUE(true);
}
TEST(TestCase8, Test6) {
	EXPECT_EQ(recursiveSum(1234), 507828);
	EXPECT_TRUE(true);
}