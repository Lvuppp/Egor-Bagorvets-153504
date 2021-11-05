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

int main() {
	const int N = 5, M = 5;
	int array[N][M];
	int negativeNumberSum = 0, column = 0, maxColummn;

	std::cout << "Enter Matrix: " << std::endl;
	
	for (int i = 0; i < N; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < M; j++)
		{
			std::cin >> array[i][j];
		}
	}

	maxColummn = std::min(N, M);

	for (int i = 0; i < N; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < M; j++)
		{
			std::cout << std::setw(3) << array[i][j] << " ";
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1 - i; j++)
		{
			if (array[i][j] < 0)
				negativeNumberSum++;
		}
	}

	std::cout << "\n" << negativeNumberSum << " negative numbers";

	return 0;
}