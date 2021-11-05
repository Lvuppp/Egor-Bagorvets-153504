#include <iostream>

void PrintArray(int** array, int N, int M) {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << "\n";
	}

}
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
	std::cout << "Enter size of magic square: " << std::endl;
	int size = Input();
	int** magic = new int* [size];
	for (int i = 0; i < size; i++)
	{
		magic[i] = new int[size];
	}
	int start = size / 2, max = size * size, row, col, next_row, next_col, num;;
	
	magic[0][start] = 1;

	for (num = 2, row = 0, col = start; num <= max; num++) {

		if ((col + 1) > (size - 1)) 
			next_col = 0;
		else 
			next_col = col + 1;
		
		if ((row - 1) < 0) 
			next_row = size - 1;
		else 
			next_row = row - 1;

		if (magic[next_row][next_col] > 0) {
			if ((row + 1) > (size - 1)) 
				next_row = 0;
			else {
				next_row = row + 1;
				next_col = col;
			}
		}
		row = next_row;
		col = next_col;
		magic[row][col] = num;

	}

	PrintArray(magic, size, size);
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			std::cout << magic[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < size; i++)
	{
		delete[] magic[i];
	}
	delete[] magic;

	return 0;
}