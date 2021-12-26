//Лабараторная работа №6. Задание 2. Выполнено: Багровец Е. С.
//В тексте каждую букву заменить ее номером в алфавите.
#include<iostream>
#include"strFunctions.h"
using namespace std;

int input() {
	int x;
	while (true)
	{
		cin >> x;
		if (!std::cin.fail())
			return x;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Enter correct value!";
	}
}

char* correctInput(char* str) {
	while (true)
	{
		cin.getline(str, 20);
		int rightValue = 0 , size = strlen(str);
		for (int i = 0; i < size; i++)
		{
			if ((str[i] > 64 && str[i] < 81) || (str[i] > 96 && str[i] < 123) || str[i] == ' ')
				continue;
			else
				rightValue++;
		}
		if (rightValue == 0)
			return str;

		cout << "Enter correct text" << endl;
	}
}
		

int main() {
	char* str = new char[20];

	cout << "Enter letter in your line" << endl;
	
	correctInput(str);
	
	translateToDigits(str);

	return 0;
}