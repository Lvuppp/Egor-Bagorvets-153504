#include<iostream>
#include"dllFunc.cpp"

int main() {
	int size = Input();
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = Input();
	}
	int elementsMultiply = MultiplyOfElements(array, size-1, size / 2) * MultiplyOfElements(array, size/2-1, 0);
	std::cout << elementsMultiply;
}