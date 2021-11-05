#include "pch.h"
#include "dllFunc.h"
#include<iostream>

int __stdcall Input() {
	int x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail())
			return x;
		std::cin.clear();
		std::cin.ignore(320000 , '\n');
	}
}

int __stdcall MultiplyOfElements(int *array, int size, int endSize)
{
	if (size == endSize)
		return array[endSize];
	
	return array[size] * MultiplyOfElements(array, size - 1, endSize);
}
