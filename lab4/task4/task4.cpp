#include<iostream>

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

int main() {
	std::cout << "Enter N and M size of matrix" << std::endl;

	int N = Input(), M = Input(), localMinimusNumber = 0;
	int** array = new int* [N];
	
	for (int i = 0; i < N; i++)
	{
		array[i] = new int[M];
	}

	std::cout << "Enter numbers in matrix" << std::endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array[i][j] = Input();
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M ; j++)
		{
			if (N == 1 &&  M == 1)
			{
				localMinimusNumber++;
			}
			else if (N == 1)
			{
				if (array[i][abs(j - 1)] > array[i][j])
				{
					localMinimusNumber++;
				}
			}
			else if(M == 1)
			{
				if (array[abs(i - 1)][j] > array[i][j])
				{
					localMinimusNumber++;
				}
			}
			else if ((i == N - 1 && j == M - 1) || (i == 0 && j == 0) || (i == 0 && j == M - 1) || (i == N - 1 && j == 0))
			{
				if (array[abs(i-1)][j] > array[i][j] && array[i][abs(j-1)] > array[i][j])
				{
					localMinimusNumber++;
				}
			}
			else if ((i == N - 1 || i == 0) && j != 0 && j != M - 1)
			{
				if (array[i][j-1]>array[i][j] && array[i][j + 1] > array[i][j] && array[abs(i-1)][j] > array[i][j])
				{
					localMinimusNumber++;
				}
			}
			else if ((j == M - 1 || j == 0) && i != 0 && i != N - 1)
			{
				if (array[i-1][j] > array[i][j] && array[i+1][j] > array[i][j] && array[i][abs(j-1)])
				{
					localMinimusNumber++;
				}
			}
			else
			{	
				if (array[i - 1][j] > array[i][j] && array[i + 1][j] > array[i][j] && array[i][j - 1] > array[i][j] && array[i][j + 1] > array[i][j])
				{
					localMinimusNumber++;
				}
			}
		}
	}

	std::cout << "Number of local minimus is: " << localMinimusNumber;

	for (int i = 0; i < N; i++)
	{
		delete[] array[i];
	}

	delete[] array;

	return 0;
}