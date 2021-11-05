// Functions.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include<iostream>
#include "Functions.h"
#include<iomanip>
int Input() {
	int x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail())
			return x;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
int** Input(int** array, int size, int typeOfMatrix) {
	if (typeOfMatrix == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i < 6)
					array[i][j] = 3 * i * (j - 3);
				else
					array[i][j] = 2 * i * (j - 2);
			}
		}
	}
	if (typeOfMatrix == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i > 7)
					array[i][j] = 4 * i * (j - 5);
				else
					array[i][j] = 5 * i * (j - 4);
			}
		}
	}
	return array;
}

int** CreateArray(int size, int typeOfMatrix) {
	int** array = new int* [size];

	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}
	std::cout << "Array created, input numbers in array ... " << std::endl;

	array = Input(array, size, typeOfMatrix);

	return array;
}

void PrintArray(int** array, int size) {
	std::cout << '\n';
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout <<std::setw(5) << array[i][j];
		}
		std::cout << std::endl;
	}
}

int GetPerimeter(int** array, int size) {
	int perimeterSum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(i == 0 || i == size - 1 || j == 0 ||  j == size-1)
				perimeterSum += array[i][j];
		}
	}
	return perimeterSum;
}