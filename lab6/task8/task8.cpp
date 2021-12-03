#include<string>
#include<iostream>
#include"strFunctions.h"
using namespace std;

int main() {
	int count = inputInt(0, 501);
	
	while (count > 0)
	{
		string firstWord = input(0, 501), secondWord = input(0, 2 * firstWord.length());
		cout << canMakeWord(firstWord, secondWord) << endl;
		--count;
		
	}
	return 0;
}