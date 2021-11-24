////Лабараторная работа №5. Задание 8. Выполнено: Багровец Е. С.
//Пусть f(n) - наибольший нечетный делитель натурального числа n.По заданному
//натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).
#include<iostream>
#include"Functions.h"

int main() {
	std::cout << "Enter number: " << std::endl;
	int number = input(0, 2147483647);
	std::cout << recursiveSum(number);
	return 0;
}	
