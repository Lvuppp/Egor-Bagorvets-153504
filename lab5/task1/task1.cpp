#include"\VisualStudioProjects\Lab5\Functions\Functions.cpp"
#include <iostream>
int main()
{
	int size = Input();
	int** firstArray = CreateArray(size, 1);
	PrintArray(firstArray, size);
	int** secondArray = CreateArray(size, 2);
	PrintArray(secondArray, size);
	std::cout << GetPerimeter(firstArray, size) << std::setw(5) << GetPerimeter(secondArray, size);

}
