//Лабараторная работа №5. Задание 3. Выполнено: Багровец Е. С.
//Дан двумерный динамический массив целых чисел А размерностью n  k .
//Размерность массива(n = 5, k = 6) ввести с клавиатуры.Значения элементов массива
//ввести с клавиатуры.Создать динамический массив из элементов, расположенных на
//главной диагонали матрицы и имеющих четное значение.Вычислить произведение
//элементов динамического массива.
#include"Functions.h"
#include<iostream>
#include<iomanip>


int main()
{
	std::cout << "Enter size of array: " << std::endl;
	int columnSize = inputInt(), lineSize = inputInt();
	int** array = createArray(columnSize, lineSize);

	fillArray(array, columnSize, lineSize);
	printArray(array, columnSize, lineSize);

	updateArray(array, columnSize, lineSize);

	deleteMatrix(array, columnSize);

	return 0;
}
