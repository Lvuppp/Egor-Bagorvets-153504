//Лабараторная работа №5. Задание 7. Выполнено: Багровец Е. С.
//Рекурсивная функция задана следующим образом :
#include<iostream>
#include"Functions.h"

long long recurse(long long x, long long y, long long n,int a) {
	if (y == 0) 
		return 1;
	if (y % 2 == 1) 
		return x * recurse(x * x % n, y / 2, n) % n;
	return 
		recurse(x * x % n, y / 2, n);
}


int main() {
	unsigned long long n = input(-1, 10e19), k = input(-1, 10e19), t = input(-1, 10), x = 0, m = 0;
	int caseNumber = 1;
	while (n != 0 && k != 0 && t != 0) {

		m = pow(10, t);
		unsigned long long l = k % m;

		x = recurse(l, n, m);
		std::cout << "Case #" << caseNumber++ << ": " << x << std::endl;

		n = input(-1, 10e19);
		k = input(-1, 10e19);
		t = input(-1, 10);
		x = 0;
	}
	return 0;
}