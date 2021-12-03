#include "pch.h"
#include"strFunctions.h"

TEST(TestCaseName, TestName1) {
  EXPECT_EQ(80, maxCount("11111111111111111111111111111111111111111111111111111111111111111111111111111111"));
  EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName2) {
  EXPECT_EQ(0, maxCount(""));
  EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName3) {
  EXPECT_EQ(9, maxCount("0010010010001000000000"));
  EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName4) {
  EXPECT_EQ(3, maxCount("010101011000111010101001"));
  EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName5) {
  EXPECT_EQ(1, maxCount("0"));
  EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName6) {
	EXPECT_EQ(1, maxCount("01"));
	EXPECT_TRUE(true);
}

TEST(TestCaseName2, TestName1) {
  EXPECT_EQ(1,1);
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName2) {
  EXPECT_EQ(0, maxCount(""));
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName3) {
  EXPECT_EQ(9, maxCount("0010010010001000000000"));
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName4) {
  EXPECT_EQ(3, maxCount("010101011000111010101001"));
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName5) {
  EXPECT_EQ(1, maxCount("0"));
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName6) {
	EXPECT_EQ(1, maxCount("01"));
	EXPECT_TRUE(true);
}

TEST(TestCaseName4, TestName1) {
  EXPECT_EQ(createNewText("Too swift for Theex, too quick for Gallow,\nToo strong for young Prince Joseph to follow."),"Tu svift for Ziks, tu kvik for Galov,\nTu strong for ung Prinse Josef to folov.");
  EXPECT_TRUE(true);
}
TEST(TestCaseName4, TestName2) {
  EXPECT_EQ(createNewText("skxkkk"), "sksk");
  EXPECT_TRUE(true);
}
TEST(TestCaseName4, TestName3) {
  EXPECT_EQ(createNewText("fffffff"),"f");
  EXPECT_TRUE(true);
}

TEST(TestCaseName5, TestName1) {
	EXPECT_EQ(findWordAmount(14,1000,"cup","russia"), 752);
	EXPECT_TRUE(true);
}
TEST(TestCaseName5, TestName2) {
	EXPECT_EQ(findWordAmount(7,123,"russia","codecup"), 0);
	EXPECT_TRUE(true);
}
TEST(TestCaseName5, TestName3) {
	EXPECT_EQ(findWordAmount(7,15,"codec","decup"), 1);
	EXPECT_TRUE(true);
}

TEST(TestCaseName6, TestName1) {
	EXPECT_EQ(getRepeat("oslo"), 12);
	EXPECT_TRUE(true);
}
TEST(TestCaseName6, TestName2) {
	EXPECT_EQ(getRepeat("osla"), 24);
	EXPECT_TRUE(true);
}
TEST(TestCaseName6, TestName3) {
	EXPECT_EQ(getRepeat(""), 0);
	EXPECT_TRUE(true);
}
TEST(TestCaseName6, TestName4) {
	EXPECT_EQ(getRepeat("asdfg"), 120);
	EXPECT_TRUE(true);
}
TEST(TestCaseName6, TestName5) {
	EXPECT_EQ(getRepeat("oooo"), 1);
	EXPECT_TRUE(true);
}

TEST(TestCaseName7, TestName1) {
	EXPECT_EQ(maxPolinndromLine("aboba"), 4);
	EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName2) {
	EXPECT_EQ(maxPolinndromLine("aba"), 2);
	EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName3) {
	EXPECT_EQ(maxPolinndromLine("asdfg"), 5);
	EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName4) {
	EXPECT_EQ(maxPolinndromLine(""), -1);
	EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName5) {
	EXPECT_EQ(maxPolinndromLine("abba"), 3);
	EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName6) {
	EXPECT_EQ(maxPolinndromLine("aa"), 1);
	EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName7) {
	EXPECT_EQ(maxPolinndromLine("a"), 1);
	EXPECT_TRUE(true);
}

TEST(TestCaseName8, TestName1) {
	EXPECT_EQ(canMakeWord("abcdef","cdedcb"), 'Y');
	EXPECT_TRUE(true);
}
TEST(TestCaseName8, TestName2) {
	EXPECT_EQ(canMakeWord("aaa", "aaaaa"), 'Y');
	EXPECT_TRUE(true);
}
TEST(TestCaseName8, TestName3) {
	EXPECT_EQ(canMakeWord("aab", "baaa"), 'N');
	EXPECT_TRUE(true);
}
TEST(TestCaseName8, TestName4) {
	EXPECT_EQ(canMakeWord("ab", "b"), 'Y');
	EXPECT_TRUE(true);
}
TEST(TestCaseName8, TestName5) {
	EXPECT_EQ(canMakeWord("abcdef", "abcdef"), 'Y');
	EXPECT_TRUE(true);
}
TEST(TestCaseName8, TestName6) {
	EXPECT_EQ(canMakeWord("ba", "baa"), 'N');
	EXPECT_TRUE(true);
}

TEST(TestCaseName9, TestName1) {
	EXPECT_EQ(numberSum("1234e1sdnfksd123-1f2f20e4"), 212464);
	EXPECT_TRUE(true);
}
TEST(TestCaseName9, TestName2) {
	EXPECT_EQ(numberSum("1"), 1);
	EXPECT_TRUE(true);
}
TEST(TestCaseName9, TestName3) {
	EXPECT_EQ(numberSum(""), 0);
	EXPECT_TRUE(true);
}
TEST(TestCaseName9, TestName4) {
	EXPECT_EQ(numberSum("1234"), 1234);
	EXPECT_TRUE(true);
}

