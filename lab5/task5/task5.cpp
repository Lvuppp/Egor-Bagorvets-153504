//Лабараторная работа №5. Задание 5. Выполнено: Багровец Е. С.
//Дан двумерный динамический массив целых чисел.Значения элементов данного
//массива ввести с клавиатуры.Создать динамический массив из элементов,
//расположенных в четных столбцах данного массива и имеющих нечетное значение.
//Вычислить среднее арифметическое элементов динамического массива.
//Вывести результат на экран.
#include<iostream>
#include"Functions.h"
int main() {
	std::cout << "Enter size of array: " << std::endl;
	int columnSize = inputInt(), lineSize = inputInt(), column = 0, line = 0;

	int** array = createArray(columnSize, lineSize);
	std::cout << "Fill array" << std::endl;
	fillArray(array, columnSize, lineSize);

	updateArrayTask5(array, columnSize, lineSize);
	deleteMatrix(array, columnSize);
	
	return 0;
}