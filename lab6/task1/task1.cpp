//Лабараторная работа №6. Задание 1. Выполнено: Багровец Е. С.
//В строке, состоящей из групп нулей и единиц, подсчитать
//количество символов в самой длинной группе.
#include<iostream>
#include"strFunctions.h"
using namespace std;

bool isNumbersRight(const char* str) {
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '0' || str[i] == '1')
			continue;
		else
			return false;
	}
	return true;
}

int main() {
	const int SIZE = 80;
	char str[SIZE];

	while (true)
	{
		cin.getline(str, 80);
		if (isNumbersRight(str))
			break;
		cin.ignore(32764, '\n');
		cout << "Enter correct value" << endl;
	}

	cout << maxCount(str);

	return 0;
}