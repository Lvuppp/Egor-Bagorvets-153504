#include "pch.h"
#include "framework.h"
#include<iostream>
#include "Functions.h"
#include<iomanip>

long long inputInt() {
	long long x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail())
			return x;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter correct value" << std::endl;
	}
}
double inputDouble() {
	double x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail())
			return x;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter correct value" << std::endl;
	}
}

long long input(long long lowerValue, long long highValue) {
	long long x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail() && x > lowerValue && x < highValue)
			return x;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter correct value" << std::endl;
	}
}

int** input(int** array, int size, int typeOfMatrix) {
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


int** createArray(int columnSize, int lineSize) {
	int** array = new int* [columnSize];

	for (int i = 0; i < columnSize; i++)
	{
		array[i] = new int[lineSize];
	}
	return array;
}
int** createArray(int size) {
	int** array = new int* [size];

	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}
	return array;
}
int** updateArray(int size, int typeOfMatrix) {
	
	int** array = createArray(size);
	std::cout << "Array created, input numbers in array ... " << std::endl;

	array = input(array, size, typeOfMatrix);

	return array;
}

void printArray(int** array, int size) {
	std::cout << '\n';
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << std::setw(5) << array[i][j];
		}
		std::cout << std::endl;
	}
}
void printArray(int** array, int columnSize, int lineSize) {
	std::cout << '\n';
	for (int i = 0; i < columnSize; i++)
	{
		for (int j = 0; j < lineSize; j++)
		{
			std::cout << std::setw(5) << array[i][j];
		}
		std::cout << std::endl;
	}
}void printArray(double** array, int columnSize, int lineSize) {
	std::cout << '\n';
	for (int i = 0; i < columnSize; i++)
	{
		for (int j = 0; j < lineSize; j++)
		{
			std::cout << std::setw(5) << array[i][j];
		}
		std::cout << std::endl;
	}
}

int getPerimeter(int** array, int size) {
	int perimeterSum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
				perimeterSum += array[i][j];
		}
	}
	return perimeterSum;
}

void fillArray(double** array, int columnSize, int lineSize) {
	for (int i = 0; i < columnSize; i++)
	{
		for (int j = 0; j < lineSize; j++)
		{
			array[i][j] = inputDouble();
		}
	}
}
void fillArray(int** array, int columnSize, int lineSize) {
	for (int i = 0; i < columnSize; i++)
	{
		for (int j = 0; j < lineSize; j++)
		{
			array[i][j] = inputInt();
		}
	}
}

void findZero(int columnSize, int lineSize, double** array)
{
	int countOfZero = 0;
	for (int i = 0; i < columnSize; i++)
	{
		for (int j = 0; j < lineSize; j++)
		{
			if (array[i][j] == 0)
			{
				std::cout << "Index of 0 is: " << i << ", " << j << std::endl;
				countOfZero++;
			}
		}
	}
	std::cout << "Amout of zero is: " << countOfZero << std::endl;

}
void reverseArray(int columnSize,int linesize,double** array) {
	for (int i = 0; i < columnSize/2; i++)
	{
		for (int j = 0; j < linesize; j++)
		{
			double temp = array[i][j];
			array[i][j] = array[columnSize - i - 1][linesize - j - 1];
			array[columnSize - i - 1][linesize - j - 1] = temp;
		}
	}
	if (columnSize % 2 == 1) {
		for (int i = 0; i < linesize/2; i++)
		{
			double temp = array[columnSize / 2][i];
			array[columnSize/2][i] = array[columnSize / 2][linesize - i - 1];
			array[columnSize /2][linesize - i - 1] = temp;
		}
	}
}

void printArray(int* array, int size) {

	std::cout << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(5) << array[i];
	}
}

void updateArray(int** array, int columnSize, int lineSize) {
	int size = 0;
	int* updateArray = new int[size];
	for (int i = 0; i < std::min(columnSize, lineSize); i++)
	{
		if (std::abs(array[i][i]) % 2 == 0)
		{
			int* oldArray = updateArray;
			size++;
			updateArray = new int[size];
			for (int j = 0; j < size - 1; j++)
			{
				updateArray[j] = oldArray[j];
			}

			delete[] oldArray;
			updateArray[size - 1] = array[i][i];

		}
	}

	printArray(updateArray, size);
}
void updateArrayTask5(int** array, int columnSize, int lineSize) {
	int size = 0;
	int* updateArray = new int[size];
	for (int j = 0; j < lineSize; j+=2)
	{
		for (int i = 0; i < columnSize; i++)
		{
			if (std::abs(array[i][j]) % 2 == 1)
			{
				int* oldArray = updateArray;
				size++;
				updateArray = new int[size];

				for (int i = 0; i < size-1; i++)
				{
					updateArray[i] = oldArray[i];
				}
				delete[] oldArray;
				updateArray[size - 1] = array[i][j];
			}	
		}
	}

	printArray(updateArray, size);
}

void deleteMatrix(int** array, int columnSize) {
	for (int i = 0; i < columnSize; i++)
	{
		delete[] array[i];
	}
	delete[] array;

}
long long recurse(long long x, long long y, long long n) {
	if (y == 0)
		return 1;
	if (y % 2 == 1)
		return x * recurse(x * x % n, y / 2, n) % n;
	return recurse(x * x % n, y / 2, n);
}
long long recursResult(long long k, long long n, long long t) {
	long long m = pow(10, t), l = k % m;
	return recurse(l, n, m);
}

long long recursiveFunction(int n) {
	if (n % 10 > 0)
		return n % 10;
	else if (n == 0)
		return 0;
	else
		return recursiveFunction(n / 10);
}

long long recursiveSum(long long p, long long q) {
	int recursiveSum = 0;
	for (long long i = p; i <= q; i++)
	{
		recursiveSum += recursiveFunction(i);
	}
	return recursiveSum;
}

long long recursiveSum(int number) {
	int sum = 0;
	for (int i = 1; i <= number; i++) {
		sum += recursiveFunctionTask8(i);
	}
	return sum;
}
long long recursiveFunctionTask8(int a) {
	if (a % 2 == 1)
		return a;
	else
		return recursiveFunctionTask8(a / 2);
}