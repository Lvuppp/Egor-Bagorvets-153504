//Лабараторная работа №5. Задание 7. Выполнено: Багровец Е. С.
//Рекурсивная функция задана следующим образом :
#include<iostream>
#include"Functions.h"
int main() {
	long long  k = input(-1, 10e19), n = input(-1, 10e19), t = input(-1, 10);
	int caseNumber = 1;
	while (n != 0 && k != 0 && t != 0) {
		std::cout << "Case #" << caseNumber++ << ": " << recursResult(k,n,t) << std::endl;

		n = input(-1, 10e19);
		k = input(-1, 10e19);
		t = input(-1, 10);
	}
	return 0;
}