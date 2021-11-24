//Лабараторная работа №5. Задание 6. Выполнено: Багровец Е. С.
//Определим следующую рекурсивную функцию F(n) :

#include<iostream>
#include"Functions.h"



int main() {
	std::cout << "Enter higher border and lower border of array: " << std::endl;
	int q = input(0, 2147483648),p = input(0, q);
	
	while (p > 0 && q > 0)
	{
		std::cout << recursiveSum(p, q) << std::endl;
		
		p = input();
		q = input();
	}
	return 0;
}