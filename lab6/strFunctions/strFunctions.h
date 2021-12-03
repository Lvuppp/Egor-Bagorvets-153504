#pragma once
#include"string"
std::string input(int minValue, int maxValue);
void getTextInLowerRegister(std::string text);
int inputInt(int minValue, int maxValue);
int numberSum(std::string line);
bool makeWord(std::string firstWord, std::string secondWord, int index);
char canMakeWord(std::string firstWord, std::string secondWord);
long long factorial(int a);
bool isLetterReapiting(const char& letter, std::string wordWithoutReapiting);
int getRepeat(std::string word);
bool isPolindrom(std::string word);
int maxPolinndromLine(std::string word);
void getStr(std::string& text,const int& maxValue);
int findWordAmount(const int& L, const int& m, const std::string s1, const std::string s2);
int maxCount(char* str);
void translateToDigits(char* str);
std::string createNewText(std::string text);
void addSymbol(const std::string& text, char sign, const int& index, std::string& updateText);