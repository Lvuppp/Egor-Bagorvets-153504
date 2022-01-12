///Лабараторная работа №7. Задание 5. Выполнено: Багровец Е. С.
//Перевести число из арабской системы записи чисел в римскую.
#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;


int main() {
	cout << convertToRomanian(inputInt(0, 4000));//ввод и конвертация числа 
}