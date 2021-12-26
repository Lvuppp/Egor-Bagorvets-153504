////Лабараторная работа №7. Задание 3. Выполнено: Багровец Е. С.
//
//Найдите сумму двоичных чисел, заданных в естественной форме.
//Сложение выполните в обратном коде.Ответ выразите в дополнительном
//коде.
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