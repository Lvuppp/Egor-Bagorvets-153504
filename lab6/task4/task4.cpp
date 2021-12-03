#include<iostream>
#include<string>
#include"../strFunctions/strFunctions.h"

using namespace std;



int main() {
	string text, updateText;
	getStr(text,100);
	cout << createNewText(text);
}