//Лабараторная работа №5. Задание 1. Выполнено: Багровец Е. С.
//Сформировать два двумерных динамических массива - матрицы A и B
//размерностью n на n.Размерность массивов(n = 10) ввести с клавиатуры.Значения
//элементов определить согласно выражениям:

#include"Functions.h"
#include <iostream>
#include<iomanip>
int main()
{
	std::cout << "Enter size of arrays: " << std::endl;
	int size = inputInt();
	int** firstArray = updateArray(size, 1);
	printArray(firstArray, size);
	int** secondArray = updateArray(size, 2);
	printArray(secondArray, size);
	std::cout << "Perimetr of first matrix is : " << getPerimeter(firstArray, size);
	std::cout <<"; perimetr of second matrix is : " << getPerimeter(secondArray, size);

	return 0;
}
