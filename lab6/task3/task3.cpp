#include<iostream>
#include<string>
#include<regex>
#include<Windows.h>
using namespace std;

void checkGender(const string& text,const int& position) {
	if (text[position] == 'а' || text[position] == 'я' || text[position] == 'ь')
	{
		cout << " - слово женского рода" << endl;
	}
	else if (text[position] == 'о' || text[position] == 'е')
	{
		cout << " - слово среднего рода" << endl;
	}
	else
	{
		cout << " - слово мужского рода" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string text;
	getline(cin, text);

	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];
		if (text[i] == ' ' && text[i] != 0)
			checkGender(text, i - 1);
		if (i == text.length() - 1)
			checkGender(text, i);
	}

	return 0;
}