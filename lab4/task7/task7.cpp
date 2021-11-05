#include <iostream>

int Input(int size) {
	int x;

	while (true)
	{
		std::cin >> x;

		if (!std::cin.fail() && x < size && x >= 0)
			return x;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter correct value" << std::endl;
	}
}

int main() {
	int index;
	std::cout << "Enter number: " << std::endl;

	std::string number;
	std::cin >> number;

	int* arrayNumber = new int[number.size()];

	for (int i = 0; i < number.size(); i++)
	{
		arrayNumber[i] = number[i]-48;
	}
	std::cout << "Amount numbers: " << number.size();
	while (true)
	{
		std::cout << "Enter index of digit " << std::endl;
		index = Input(number.size());
		std::cout << "digit: " << arrayNumber[number.size() - index - 1];
	}


	delete[] arrayNumber;
	
	return 0;
}