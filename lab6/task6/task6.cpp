#include<iostream>
#include<string>
#include"..//strFunctions/strFunctions.cpp"
using namespace std;


int main() {
	std::string word = input(0,15);
	
	cout << getRepeat(word);

	return 0;
}