#include<iostream>
#include<string>
#include"Functions.h"
using namespace std;

int main() {
	string numberInOtherSystem, numberInAnotherSystem;
	int valueOfOtherSystem,valueOfAnotherSystem;

	cout << "Enter name of system(max is 18)" << endl;
	cin >> valueOfOtherSystem;
	cout << "Enter name of system(max is 18)" << endl;
	cin >> valueOfAnotherSystem;

	cout << "Enter number(max size of elements in number is 10): " << endl;

	convertFromDecimal(convertToDecimal(enterNumber(numberInOtherSystem, valueOfOtherSystem), valueOfOtherSystem),valueOfAnotherSystem, numberInAnotherSystem);
	
	cout << numberInAnotherSystem;

	return 0;
}