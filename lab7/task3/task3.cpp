#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;

int main() {
	string firstNumber = convertInReverseCode(inputInt()), secondNumber = convertInReverseCode(inputInt());
	cout << firstNumber << " " << secondNumber << endl;
	cout << binarySum('+' , firstNumber, '+', secondNumber, 2);
	return 0;
}