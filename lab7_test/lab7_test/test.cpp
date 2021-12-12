#include "pch.h"
#include"Functions.h"
TEST(TestCaseName1, TestName1) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(TestCaseName1, TestName2) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(TestCaseName1, TestName3) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);	
}
TEST(TestCaseName1, TestName4) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName2, TestName1) {
  EXPECT_EQ(17, convertToDecimalFromReverse("010001",2));
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName2) {
  EXPECT_EQ(1, convertToDecimalFromReverse("1", 2));
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName3) {
  EXPECT_EQ(0, convertToDecimalFromReverse("11111111", 2));
  EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName4) {
  EXPECT_EQ(362, convertToDecimalFromReverse("101101010",2));
  EXPECT_TRUE(true);
}

TEST(TestCaseName3, TestName1) {
  EXPECT_EQ("+01111011", binarySum('+', "010001", '+', "01101010", 2));
  EXPECT_TRUE(true);
}	
TEST(TestCaseName3, TestName2) {
  EXPECT_EQ("+01101010", binarySum('+', "0", '+', "01101010", 2));
  EXPECT_TRUE(true);
}
TEST(TestCaseName3, TestName3) {
  EXPECT_EQ("+1000000", binarySum('+', "0001", '+', "0111111", 2));
  EXPECT_TRUE(true);
}
TEST(TestCaseName3, TestName4) {
  EXPECT_EQ("+0", binarySum('+', "0", '+', "0", 2));
  EXPECT_TRUE(true);
}

TEST(TestCaseName4, TestName1) {
  EXPECT_EQ("+aaa", binarySum('+', "aaa", '+', "000", 13));
  EXPECT_TRUE(true);
}	
TEST(TestCaseName4, TestName2) {
  EXPECT_EQ("+999", binarySum('+', "aaa", '-', "111", 13));
  EXPECT_TRUE(true);
}
TEST(TestCaseName4, TestName3) {
  EXPECT_EQ("-999", binarySum('-', "aaa", '+', "111", 13));
  EXPECT_TRUE(true);
}
TEST(TestCaseName4, TestName4) {
  EXPECT_EQ("+0", binarySum('+', "0", '+', "0", 13));
  EXPECT_TRUE(true);
}

TEST(TestCaseName5, TestName1) {
  EXPECT_EQ("MCMXCXXXXV", convertToRomanian(1945));
  EXPECT_TRUE(true);
}
TEST(TestCaseName5, TestName2) {
  EXPECT_EQ("MMCCII", convertToRomanian(2202));
  EXPECT_TRUE(true);
}
TEST(TestCaseName5, TestName3) {
  EXPECT_EQ("MCCCXCXXXXV", convertToRomanian(1345));
  EXPECT_TRUE(true);
}
TEST(TestCaseName5, TestName4) {
  EXPECT_EQ("CCXXIII", convertToRomanian(223));
  EXPECT_TRUE(true);
}

TEST(TestCaseName6, TestName1) {
  EXPECT_EQ(0, amountIntrestingNumbers(1));
  EXPECT_TRUE(true);
}	
TEST(TestCaseName6, TestName2) {
  EXPECT_EQ(1, amountIntrestingNumbers(9));
  EXPECT_TRUE(true);
}
TEST(TestCaseName6, TestName3) {
  EXPECT_EQ(3, amountIntrestingNumbers(34));
  EXPECT_TRUE(true);
}
TEST(TestCaseName6, TestName4) {
  EXPECT_EQ(88005553, amountIntrestingNumbers(880055535));
  EXPECT_TRUE(true);
}

TEST(TestCaseName7, TestName1) {
  EXPECT_EQ(true, multiplieBySeven(7));
  EXPECT_TRUE(true);
}	
TEST(TestCaseName7, TestName2) {
  EXPECT_EQ(true, multiplieByTwentyNune(29));
  EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName3) {
  EXPECT_EQ(true, multiplieByBigValue(149));
  EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName4) {
  EXPECT_EQ(true, multiplieBySeven(21));
  EXPECT_TRUE(true);
}	
TEST(TestCaseName7, TestName5) {
  EXPECT_EQ(true, multiplieByTwentyNune(58));
  EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName6) {
  EXPECT_EQ(true, multiplieByBigValue(298));
  EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName7) {
  EXPECT_EQ(false, multiplieBySeven(1));
  EXPECT_TRUE(true);
}	
TEST(TestCaseName7, TestName8) {
  EXPECT_EQ(false, multiplieByTwentyNune(3));
  EXPECT_TRUE(true);
}
TEST(TestCaseName7, TestName9) {
  EXPECT_EQ(false, multiplieByBigValue(5));
  EXPECT_TRUE(true);
}

TEST(TestCaseName8, TestName1) {
  EXPECT_EQ(1, getMaxBinaryNumber(1));
  EXPECT_TRUE(true);
}	
TEST(TestCaseName8, TestName2) {
  EXPECT_EQ(1100, getMaxBinaryNumber(10));
  EXPECT_TRUE(true);
}
TEST(TestCaseName8, TestName3) {
  EXPECT_EQ(10, getMaxBinaryNumber(2));
  EXPECT_TRUE(true);
}

//TEST(TestCaseName9, TestName1) {
//  EXPECT_EQ("21", getMaxBinaryNumber(7));
//  EXPECT_TRUE(true);
//}	
//TEST(TestCaseName9, TestName2) {
//  EXPECT_EQ("211", getMaxBinaryNumber(22));
//  EXPECT_TRUE(true);
//}
//TEST(TestCaseName9, TestName3) {
//  EXPECT_EQ("3123", getMaxBinaryNumber(99));
//  EXPECT_TRUE(true);
//}
//TEST(TestCaseName9, TestName4) {
//  EXPECT_EQ("12113", getMaxBinaryNumber(150));
//  EXPECT_TRUE(true);
//}
