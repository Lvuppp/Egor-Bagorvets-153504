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
	std::cout << "Enter size of matrix N and M: " << std::endl;
	int N = Input(), M = Input();

	int** array = new int*[N];
	for (int i = 0; i < N; i++)
	{
		array[i] = new int[M];
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
		std::cout << "\n";
		for (int j = 0; j < M; j++)
		{
			if (i == 0 && j != 0)
			{
				array[i][j] = std::max(array[i][j], array[i][j-1]);
			}
			else
			{
				if (j == 0 && i != 0)
					array[i][j] = std::max(array[i][j], array[i - 1][j]);
				else if(j != 0 && i != 0)
					array[i][j] = std::max(array[i][j], std::max(array[i - 1][j], array[i][j - 1]));
			}
			std::cout << array[i][j] << " ";
		}
	}

	for (int i = 0; i < N; i++)
	{
		delete[] array[i];
	}
	
	delete[] array;

	return 0;
}