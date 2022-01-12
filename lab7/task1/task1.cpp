////Лабараторная работа №7. Задание 1. Выполнено: Багровец Е. С.
//Необходимо разработать программу для перевода чисел из
//одной системы счисления в другую.Выполнить два варианта решения
//задачи : без использования массивов и с помощью массивов.
#include<iostream>
#include<string>
#include"Functions.h"
using namespace std;

int main() {
	string numberInOtherSystem, numberInAnotherSystem;
	int valueOfOtherSystem,valueOfAnotherSystem;

	cout << "Enter name of system(max is 18)" << endl;
	cin >> valueOfOtherSystem; // ввод первой системы
	cout << "Enter name of system(max is 18)" << endl;
	cin >> valueOfAnotherSystem;// ввод второй системы
	 
	cout << "Enter number(max size of elements in number is 10): " << endl;

	convertFromDecimal(convertToDecimal(enterNumber(numberInOtherSystem, valueOfOtherSystem), valueOfOtherSystem),valueOfAnotherSystem, numberInAnotherSystem);// использууем функции перевода из одной системы в другую
	
	cout << numberInAnotherSystem;

	

	return 0;
}