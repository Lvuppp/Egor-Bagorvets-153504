#include<iostream>
#include<string>
using namespace std;
void correctValue() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

short inputInt(short minValue, short maxValue) {
	float x;
	while (true)
	{
		cin >> x;
		if (!cin.fail() && x > minValue && x < maxValue) {
			correctValue();
			return x;
		}
		correctValue();
		cout << "Enter correct value! " << endl;
	}
}
double inputDoub(int minValue, int maxValue) {
	double x;
	while (true)
	{
		cin >> x;
		if (!cin.fail() && x > minValue && x < maxValue) {
			correctValue();
			return x;
		}
		correctValue();
		cout << "Enter correct value! " << endl;
	}
}

char inputChar() {
	char x;
	while (true)
	{
		cin >> x;
		if (tolower(x) == 'm' || tolower(x) == 'f')
			return x;
		correctValue();
		cout << "Enter correct value! " << endl;
	}
}

string inputStr(int minValue, int maxValue) {
	string x;
	while (true)
	{
		cin >> x;
		if (x.length() > minValue && x.length() < maxValue)
			return x;
		cout << "Enter correct value! " << endl;
		correctValue();
		
	}
}

char* inputCharStr(int maxValue) {
	char* n = (char*)calloc(100,sizeof(char));
	while (true)
	{
		std::cin.getline(n, 100);
		if (!std::cin.fail() && strlen(n) < maxValue)
			return n;
		n = (char*)calloc(100, sizeof(char));
		cout << "Enter correct value! " << endl;
	}
}

void strToChar(char str[], char* strChar) {
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = strChar[i];
	}
}