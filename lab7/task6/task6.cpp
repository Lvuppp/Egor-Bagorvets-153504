///Лабараторная работа №7. Задание 6. Выполнено: Багровец Е. С.
//Постчиатать количество чисел x, таких что 1 < x < n и x - интересное.
#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;


int main() {

	int counter = inputInt(0, 1001);//ввод количества итераций

	while (counter != 0) 
	{
		int number = inputInt(0, 10e9 + 1);
		
		std::cout << amountIntrestingNumbers(number) << '\n';

		--counter;			
	}
}