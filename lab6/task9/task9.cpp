#include<iostream>
#include<string>
#include"../strFunctions/strFunctions.h"
using namespace std;

int main() {
	string line = input(0, 101);
	cout << numberSum(line);

	return 0;
}