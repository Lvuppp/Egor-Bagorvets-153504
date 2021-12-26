//Лабараторная работа №6. Задание 9. Выполнено: Багровец Е. С.
//
//В заданной строке, состоящей из букв, цифр и прочих символов, найдите
//сумму всех чисел.
#include<iostream>
#include<string>
#include<iomanip>
#include"../strFunctions/strFunctions.h"
using namespace std;

int main() {
	string line = input(0, 101);
	cout<< setprecision(7) << numberSum(line);

	return 0;
}