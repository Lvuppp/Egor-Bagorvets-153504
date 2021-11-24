//Лабараторная работа №5. Задание 2. Выполнено: Багровец Е. С.
//Для заданного одномерного массива B из N элементов найти произведение
//множителей, вычисляемых по формуле.Рекурсивную функцию применять
//каждый раз отдельно для каждой из половин массива.Рекурсивные вызовы
//заканчивать, когда останется только один элемент.
#include<iostream>
#include<Windows.h>
int main() {
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");

	typedef int(*input)();
	input Input;
	Input = (input)GetProcAddress(load, "input");

	typedef int(*multiplyOfElements)(int*, int, int);
	multiplyOfElements MultiplyOfElements;
	MultiplyOfElements = (multiplyOfElements)GetProcAddress(load, "multiplyOfElements");

	std::cout << "Enter size of array: " << std::endl;
	int size = Input();
	int* array = new int[size];

	std::cout << "Enter elements of array: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		array[i] = Input();
	}
	
	int elementsMultiply = MultiplyOfElements(array, size-1, size / 2) * MultiplyOfElements(array, size/2-1, 0);
	std::cout << elementsMultiply;
	
	FreeLibrary(load);
}