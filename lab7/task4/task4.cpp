#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;

int main() {
	char signOfFirstNumber, signOfSecondNumber;
	string firstNumber, secondNumber;
	int valueOfSystem;
	cout << "Enter system" << endl;
	cin >> valueOfSystem;
	cout << "Enter sign of first number" << endl;
	cin >> signOfFirstNumber;
	cout << "Enter first numbers in "<< valueOfSystem << " system" << endl;
	enterNumber(firstNumber, valueOfSystem);
	cout << "Enter sign of second number" << endl;
	cin >> signOfSecondNumber;
	cout << "Enter second numbers in " << valueOfSystem << " system" << endl;
	enterNumber(secondNumber, valueOfSystem);

	cout << "Sum is :" << binarySum(signOfFirstNumber,firstNumber,signOfSecondNumber,secondNumber,valueOfSystem) << endl;
	cout << "Dif is :" << binaryDif(signOfFirstNumber, firstNumber, signOfSecondNumber, secondNumber, valueOfSystem) << endl;

	return 0;
}