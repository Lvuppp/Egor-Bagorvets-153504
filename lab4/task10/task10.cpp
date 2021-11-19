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


void printArray(int size, int** array)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << std::setw(3) << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void deleteArray(int** array, int size) {
	for (int i = 0; i < size; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}
void editTerrace(int** array, int startIndexI, int endIndexI, int startIndexJ, int endIndexJ, int editIndexI, int editIndexJ) {
	for (int i = startIndexI; i <= endIndexI; i++)
	{
		for (int j = startIndexJ; j < endIndexJ; j++)
		{
			if (array[i][j] != 0)
				array[i + editIndexI][j + editIndexJ] = array[i][j];
		}
	}
}

int** createUnevenSquare(int size, int startValue) {

	int updateSize = size + (size / 2) * 2;

	int** array = (int**)malloc(updateSize * sizeof(int*));

	for (int i = 0; i < updateSize; i++)
		array[i] = (int*)malloc(updateSize * sizeof(int));


	for (int i = 0; i < updateSize; i++)
		for (int j = 0; j < updateSize; j++)
			array[i][j] = 0;



	int y = updateSize / 2, y_copy;
	int x = 0, x_copy;

	int start = 1, end = size;

	for (int i = 0; i < size; i++)
	{
		y_copy = y; x_copy = x;

		for (int j = start; j <= end; j++) {
			array[y--][x++] = startValue;
			startValue++;
		}

		start += size; end += size;
		y = y_copy + 1; x = x_copy + 1;
	}

	int terraceSize = size / 2;

	editTerrace(array, terraceSize + 1, terraceSize + size - 2, 0, terraceSize, 0, size);
	editTerrace(array, terraceSize + 1, terraceSize + size - 2, terraceSize + size - 1, updateSize, 0, -size);
	editTerrace(array, 0, terraceSize, terraceSize + 1, terraceSize + size - 1, size, 0);
	editTerrace(array, terraceSize + size, updateSize - 1, terraceSize + 1, terraceSize + size - 1, -size, 0);

	y = 0, x = 0;
	for (int i = terraceSize; i < (updateSize - terraceSize); i++)
	{
		for (int j = terraceSize; j < updateSize - terraceSize; j++)
			array[y][x++] = array[i][j];

		y++;
		x = 0;
	}
	return array;
}
void createSecondEvenSquare(int size) {
	int** firstArray = createUnevenSquare(size / 2, 1);
	int** fourthArray = createUnevenSquare(size / 2, size * size / 4 + 1);
	int** secondArray = createUnevenSquare(size / 2, size * size / 2 + 1);
	int** thirdArray = createUnevenSquare(size / 2, 3 * size * size / 4 + 1);
	int** endArray = new int* [size];

	for (int i = 0; i < size; i++)
	{
		endArray[i] = new int[size];
	}
	int line = (size - 2) / 4 - 1;

	if (line > 0) {
		while (line > 0) {
			for (int i = 0; i < size / 2; i++) {
				int tmp = firstArray[i][size / 2 - line];
				firstArray[i][size / 2 - line] = thirdArray[i][size / 2 - line];
				thirdArray[i][size / 2 - line] = tmp;

				tmp = secondArray[i][line - 1];
				secondArray[i][line - 1] = fourthArray[i][line - 1];
				fourthArray[i][line - 1] = tmp;
			}

			--line;
		}
	}

	for (int i = 0; i < size / 2; ++i) {
		for (int j = 0; j < size / 2; ++j) {
			endArray[i][j] = firstArray[i][j];
			endArray[i][j + size / 2] = secondArray[i][j];
			endArray[i + size / 2][j] = thirdArray[i][j];
			endArray[i + size / 2][j + size / 2] = fourthArray[i][j];
		}
	}

	printArray(size, endArray);



	deleteArray(firstArray, size / 2);
	deleteArray(secondArray, size / 2);
	deleteArray(thirdArray, size / 2);;
	deleteArray(fourthArray, size / 2);

}
void createEvenSquare(int size) {
	int** firstArray = new int* [size];
	int** secondArray = new int* [size];

	int count = 1;

	for (int i = 0; i < size; i++)
	{
		firstArray[i] = new int[size];
		secondArray[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			firstArray[i][j] = count;
			secondArray[size - i - 1][size - j - 1] = count;
			count++;
		}
	}
	int cornerIndexI, cornerIndexJ;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cornerIndexI = i;
			cornerIndexJ = j;
			while (cornerIndexI > 3)
				cornerIndexI -= 4;

			while (cornerIndexJ > 3)
				cornerIndexJ -= 4;
			if ((cornerIndexI == cornerIndexJ) || (cornerIndexI + cornerIndexJ == 3))
				firstArray[i][j] = secondArray[i][j];
		}
	}

	printArray(size, firstArray);

	deleteArray(firstArray, size);
	deleteArray(secondArray, size);
}


int main() {
	int size = Input();


	int** array = new int* [size];

	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}

	if (size % 2 == 1)
	{
		array = createUnevenSquare(size, 1);
		printArray(size, array);
	}
	else if (size % 4 == 0)
	{
		createEvenSquare(size);
	}
	else if (size % 2 == 0)
	{
		createSecondEvenSquare(size);
	}
	else
	{
		std::cout << "Sorry I cant do this:(" << std::endl;
	}

	deleteArray(array, size);
	return 0;
}