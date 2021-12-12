#include<iostream>
#include<string>
#include<iomanip>
#include"Functions.h"

using namespace std;


int main() {
	int number = inputInt(0,INT_MAX);

	cout << boolalpha << multiplieBySeven(number) << " " << multiplieByTwentyNune(number) << " " << multiplieByBigValue(number) << endl;
	return 0;
}