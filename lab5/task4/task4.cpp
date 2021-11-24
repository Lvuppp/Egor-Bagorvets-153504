//Лабараторная работа №5. Задание 4. Выполнено: Багровец Е. С.
//Создать двумерный динамический массив вещественных чисел.Определить,
//встречаются ли среди них элементы с нулевым значением.Если встречаются такие
//элементы, то определить их индексы и общее количество.Переставить элементы этого
//массива в обратном порядке и вывести на экран.
#include<iostream>
#include<iomanip>
#include"Functions.h"
int main() {

	std::cout << "Enter size of array: " << std::endl;
	int columnSize = input(0, 2147483646), lineSize = input(0, 2147483646);

	double** array = new double* [columnSize];

	for (int i = 0; i < columnSize; i++)
	{
		array[i] = new double[lineSize];
	}

	fillArray(array, columnSize, lineSize);

	findZero(columnSize, lineSize, array);

	reverseArray(columnSize, lineSize, array);
	printArray(array, columnSize, lineSize);
	for (int i = 0; i < columnSize; i++)
	{
		delete[] array[i];
	}

	delete[] array;
}
