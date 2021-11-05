#include <iostream>
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
		std::cout << "Enter correct value" << std::endl;
	}
}
double** RotateMinElement(double** array,int minRowIndex,int minLineIndex, int N, int M) {
	for (int i = minLineIndex; i > 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			double temp = array[i][j];
			array[i][j] = array[i - 1][j];
			array[i - 1][j] = temp;
		}
	}
	for (int j = minRowIndex; j > 0; j--)
	{
		for (int i = 0; i < M; i++)
		{
			double temp = array[i][j];
			array[i][j] = array[i][j - 1];
			array[i][j - 1] = temp;
		}
	}
	return array;
}
int main() {
	std::cout << "Enter N and M(size of matrix) : " << std::endl;
	int N = Input(), M = Input(), minRowIndex = 0, minLineIndex = 0;

	double** array = new double* [N];

	for (int i = 0; i < N; i++)
	{
		array[i] = new double[M];
	}

	std::cout << "Enter Matrix: " << std::endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array[i][j] = Input();
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (array[minLineIndex][minRowIndex] > array[i][j])
			{
				minLineIndex = i;
				minRowIndex = j;
			}
		}
	}
	std::cout << "\n";

	RotateMinElement(array,minRowIndex,minLineIndex,N,M);

	for (int i = 0; i < N; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < M; j++)
		{
			std::cout << std::setw(3) << array[i][j] << " ";
		}
	}
	for (int i = 0; i < N; i++)
	{
		delete[] array[i];
	}

	delete[] array;

	return 0;
}