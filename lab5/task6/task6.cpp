//Лабараторная работа №5. Задание 6. Выполнено: Багровец Е. С.
//Определим следующую рекурсивную функцию F(n) :

#include<iostream>
#include"Functions.h"



int main() {
	std::cout << "Enter lower border and higher border of array: " << std::endl;
	int p = input(0, 2147483648),q = input(p - 1, 2147483648);
	
	while (p > 0 && q > 0)
	{
		std::cout << recursiveSum(p, q) << std::endl;
		
		p = inputInt();
		q = inputInt();
	}
	return 0;
}