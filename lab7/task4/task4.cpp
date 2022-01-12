///Лабараторная работа №7. Задание 4. Выполнено: Багровец Е. С.
//
//Осуществить сложение и вычитание чисел в заданной системе
//счисления.В другую систему счисления не переводить.В системах
//счисления больших десятичной использовать буквы по аналогии с
//шестнадцатеричной системой.Разработать функции для выполнения
//операции сложения и функции для выполнения операции вычитания.
//Предусмотреть ввод положительных и отрицательных чисел.
#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;

int main() {
	char signOfFirstNumber, signOfSecondNumber;
	string firstNumber, secondNumber;
	int valueOfSystem;
	cout << "Enter system" << endl;
	cin >> valueOfSystem;// вводим систему счисления
	cout << "Enter sign of first number" << endl;
	cin >> signOfFirstNumber;
	cout << "Enter first numbers in "<< valueOfSystem << " system" << endl;
	enterNumber(firstNumber, valueOfSystem);
	cout << "Enter sign of second number" << endl;
	cin >> signOfSecondNumber;
	cout << "Enter second numbers in " << valueOfSystem << " system" << endl;
	enterNumber(secondNumber, valueOfSystem);

	cout << "Sum is :" << binarySum(signOfFirstNumber,firstNumber,signOfSecondNumber,secondNumber,valueOfSystem) << endl;//cкладываем числа в n-ой системе
	cout << "Dif is :" << binaryDif(signOfFirstNumber, firstNumber, signOfSecondNumber, secondNumber, valueOfSystem) << endl;//отнимаем числа в n-ой системе

	return 0;
}