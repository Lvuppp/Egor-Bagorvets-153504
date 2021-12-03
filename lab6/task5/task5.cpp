#include<iostream>
#include<string>
#include"strFunctions.h"
using namespace std;

int main() {
	int counter = inputInt(0, 101);
	while (counter > 0)
	{
		int L = inputInt(0, 10e9 + 1), m = inputInt(0, 10e4 + 1);
		myClass::String s1, s2;
		std::cin.ignore(32767, '\n');
		s1.getLine();
		s2.getLine();

		cout << findWordAmount(L, m, s1, s2);
		--counter;
	}
}