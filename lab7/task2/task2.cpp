#include<iostream>
#include"Functions.h"

using namespace std;

string inputString() {
	string number;

	while (true)
	{
		cin >> number;
		if (number.length() < 33 && checkNumber(number, 2))
			return number;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter correct value! " << endl;
	}
}

int main() {
	
	cout << "Enter number in reverse code: " << endl;
	string number = inputString();

	std::cout << convertToDecimalFromReverse(number,2);

	return 0;
}