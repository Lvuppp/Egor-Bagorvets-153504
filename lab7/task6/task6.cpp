#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;


int main() {

	int counter = inputInt(0, 1001);

	while (counter != 0) 
	{
		int number = inputInt(0, 10e9 + 1);
		
		std::cout << amountIntrestingNumbers(number) << '\n';

		--counter;
	}
}