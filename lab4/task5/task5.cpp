#include<iostream>
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

int main() {
	std::cout << "Enter N and M size of matrix" << std::endl;
	int N = Input(), M = Input();

	double** array = new double* [N];
	double** updateArray = new double* [N];

	for (int i = 0; i < N; i++)
	{
		array[i] = new double[M];	
		updateArray[i] = new double[M];
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
		std::cout << std::endl;
		for (int j = 0; j < M; j++)
		{
			std::cout<< std::setw(7) << array[i][j] << " ";
		}
	}

	std::cout << "\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (N == 1 && M == 1)
			{
				updateArray[i][j]= array[i][j];
			}
			else if (N == 1)
			{
				if (j == 0 || j == M - 1)
					updateArray[i][j] = array[i][abs(j - 1)];
				else
					updateArray[i][j] = (array[i][j - 1] + array[i][j + 1]) / 2;
			}
			else if (M == 1 )
			{
				if (i == 0 || i == N - 1)
					updateArray[i][j] = array[abs(i-1)][j];
				else
					updateArray[i][j] = (array[i-1][j] + array[i+1][j]) / 2;
			}
			else if ((i == N - 1 && j == M - 1) || (i == 0 && j == 0) || (i == 0 && j == M-1) || (i == N - 1 && j == 0))
			{
				updateArray[i][j] = (array[i][abs(j - 1)] + array[abs(i - 1)][j]+array[abs(i-1)][abs(j-1)]) / 3;
			}
			else if ((i == N - 1 || i == 0) && j != 0 && j != M - 1)
			{
				updateArray[i][j] = (array[i][j - 1] + array[i][j + 1] + array[abs(i - 1)][j] + array[abs(i - 1)][j - 1] + array[abs(i - 1)][j + 1]) / 5;
			}
			else if ((j == M - 1 || j == 0) && i != 0 && i != N - 1)
			{
				updateArray[i][j] = (array[i - 1][j] + array[i + 1][j] + array[i][abs(j - 1)] + array[i - 1][abs(j - 1)] + array[i + 1][abs(j - 1)]) / 5;
			}
			else
			{		
				updateArray[i][j] = (array[i][j - 1] + array[i][j + 1] + array[i - 1][j] + array[i + 1][j] + array[i - 1][j - 1] + array[i + 1][j + 1] + array[i - 1][j + 1] + array[i + 1][j - 1]) / 8;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < M; j++)
		{
			std::cout << std::setw(7) << std::setprecision(3) << updateArray[i][j] << " ";
		}
	}

	for (int i = 0; i < N; i++)
	{
		delete[] updateArray[i];
		delete[] array[i];
	}
	delete[] array;
	delete[] updateArray;

	return 0;
}