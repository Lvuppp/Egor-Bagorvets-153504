#include"Functions.h"
#include<iostream>
#include<string>
int inputInt() {

	double x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail())
			return (int)x;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter corect value" << std::endl;
	}
}

int inputInt(int minValue, int maxValue) {

	double x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail() && x <maxValue && x > minValue)
			return (int)x;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter corect value" << std::endl;
	}
}

std::string enterNumber(std::string &numberInOtherSystem, int valueOfOtherSystem) {

	while (true)
	{
		std::cin >> numberInOtherSystem;
		if (checkNumber(numberInOtherSystem, valueOfOtherSystem))
			return numberInOtherSystem;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter corect value" << std::endl;
	}
}

bool checkNumber(std::string str, int valueOfOtherSystem) {
	for (int i = 0; i < str.length(); i++)
	{
		if (!(findValue((char)tolower(str[i]), valueOfOtherSystem)+1))
			return false;
	}
	return true;
}

char findValue(int digit, int maxKey) {
	int key[18]{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	char value[18]{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h' };
	for (int i = 0; i < maxKey; i++)
	{
		if (key[i] == digit)
			return value[i];
	}
	return 0;
}


int findValue(char digit, int maxKey) {
	char key[18]{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h' };
	int value[18]{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	for (int i = 0; i < maxKey; i++)
	{
		if (key[i] == digit )
			return i;
	}
	return -1;
}

int convertToDecimal(std::string str, int valueOfOtherSystem) {
	int number = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		number += (findValue((char)(tolower(str[i])), valueOfOtherSystem)) * pow(valueOfOtherSystem, str.length() - 1 - i);
	}
	return number;
}

void convertFromDecimal(int number, int valueOfOtherSystem, std::string& numberInAnotherSystem) {
	while (number != 0)
	{
		numberInAnotherSystem.push_back(findValue(number % valueOfOtherSystem, valueOfOtherSystem));
		number /= valueOfOtherSystem;
	}
	reverseStr(numberInAnotherSystem);
}


int convertToDecimalFromReverse(std::string str, int valueOfOtherSystem) {
	int number = 1;

	convertBinariesInReverseCode(str); //перевод в обратный код
	if (str.length() == 1)
		return str[0] - 47;

	if (str[0] == '1') //удал€ем знаковый элемент еслии он отрицательный, иначе он не сыграет роли
	{
		str.erase(0, 1);
		number *= -1;
	}
	number *= convertToDecimal(str, 2);

	return number;
}

std::string transformNumber(std::string str) {
	std::string newStr;
	addZeroes(str, newStr);
	for (int i = 0; i < str.length(); i++)
	{
		newStr.push_back(str[i]);
	}
	return newStr;
}

void addZeroes(std::string &str, std::string &newStr) {
	if ((int)log2(str.length()) != log2(str.length()))
	{
		for (int i = 0; i < pow(2, (int)log2(str.length()) + 1) - str.length() ; i++)
		{
			newStr.push_back('0');
		}
	}
}

std::string convertInReverseCode(int num) {
	std::string number;
	convertFromDecimal(num, 2, number);
	convertBinariesInReverseCode(number);
	return number;
}

void convertBinariesInReverseCode(std::string &str){		
	str = transformNumber(str);
	if (str[0] == '1') {

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '1')
				str[i] = '0';
			else
				str[i] = '1';
		}

	}
}

void updateStr(std::string& firstNumber, std::string& secondNumber) {
	if (firstNumber.length() > secondNumber.length())
		for (int i = secondNumber.length(); i < firstNumber.length(); i++)
		{
			secondNumber.push_back('0');
		}
	else if (firstNumber.length() < secondNumber.length())
		for (int i = firstNumber.length(); i < secondNumber.length(); i++)
		{
			firstNumber.push_back('0');
		}
	
}

std::string getBinarySum(std::string firstNumber, std::string secondNumber, int valueOfSystem) {
	std::string sumNumber;
	int tmp = 0;
	
	for (int i = 0; i < firstNumber.length(); i++)
	{
		if (findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp < valueOfSystem)
		{
			sumNumber.push_back(findValue((findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp), valueOfSystem));
			tmp = 0;
		}
		else
		{
			sumNumber.push_back(findValue(findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp - valueOfSystem, valueOfSystem));
			tmp = 1;
		}
	}
	if (tmp != 0)
		sumNumber.push_back(findValue(tmp, valueOfSystem));
	reverseStr(sumNumber);
	return sumNumber;
}

std::string binarySum(char signOfFirstNumber,std::string firstNumber, char signOfSecondNumber,std::string secondNumber, int valueOfSystem){	

	if (convertToDecimal(firstNumber, valueOfSystem) < convertToDecimal(secondNumber, valueOfSystem)) {
		std::swap(firstNumber, secondNumber);
		std::swap(signOfFirstNumber, signOfSecondNumber);
	}

	reverseStr(firstNumber);
	reverseStr(secondNumber);

	updateStr(firstNumber,secondNumber);

	if (signOfFirstNumber == '+' && signOfSecondNumber == '+')
		return signOfFirstNumber + getBinarySum(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '-' && signOfSecondNumber == '+')
		return signOfFirstNumber + getBinaryDif(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '+' && signOfSecondNumber == '-')
		return signOfFirstNumber + getBinaryDif(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '-' && signOfSecondNumber == '-')
		return signOfFirstNumber + getBinarySum(firstNumber, secondNumber, valueOfSystem);
	return "I dont understand want i should to do!";
}

std::string getBinaryDif(std::string firstNumber, std::string secondNumber, int valueOfSystem) {
	int tmp = 0;
	std::string difNumber;

	for (int i = 0; i < firstNumber.length(); i++)
	{
		if (findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem) > 0)
		{
			difNumber.push_back(findValue((findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem)), valueOfSystem));
		}
		else
		{
			difNumber.push_back(findValue(findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem) + valueOfSystem, valueOfSystem));
			firstNumber[i + 1] = findValue(findValue(firstNumber[i + 1], valueOfSystem) - 1, valueOfSystem);
		}
	}
	reverseStr(difNumber);

	return difNumber;
}

std::string binaryDif(char signOfFirstNumber, std::string firstNumber, char signOfSecondNumber, std::string secondNumber, int valueOfSystem) {
	char finalSign = '+';
	if (convertToDecimal(firstNumber, valueOfSystem) < convertToDecimal(secondNumber, valueOfSystem)) {
		std::swap(firstNumber, secondNumber);
		std::swap(signOfFirstNumber, signOfSecondNumber);
		finalSign = '-';
	}
	updateStr(firstNumber, secondNumber);

	if (signOfFirstNumber == '+' && signOfSecondNumber == '+')
		return signOfFirstNumber + getBinaryDif(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '-' && signOfSecondNumber == '+')
		return signOfFirstNumber + getBinarySum(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '+' && signOfSecondNumber == '-')
		return signOfFirstNumber + getBinarySum(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '-' && signOfSecondNumber == '-')
		return signOfFirstNumber + getBinaryDif(firstNumber, secondNumber, valueOfSystem);
	return "I dont understand want i should to do!";
}

void reverseStr(std::string& str) {
	for (int i = 0; i < str.length() / 2; i++)
	{
		char tmp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = tmp;
	}
}

int getMaxBinaryNumber(int number) {
	int amount = 1;
	for (int i = 1; i < 100000; i++)
	{	
		std::string binaryStr, numberStr = std::to_string(i);
		convertFromDecimal(i, 2, binaryStr);

		while (numberStr != binaryStr)
		{
			if (binaryStr.length() == 0)
				break;
			binaryStr.erase(0, 1);
			if (numberStr == binaryStr)
				++amount;
		}

		if (amount == number) {
			return i;
			break;
		}

		if (i % 10 == 0) {
			i += 0;
		}
		else if ((i % 100) / 10 == 0) {
			i += 8;
		}
		else if ((i % 1000) / 100 == 0) {
			i += 88;
		}
		else if ((i % 10000) / 1000 == 0) {
			i += 888;
		}
		else if ((i % 100000) / 10000 == 0) {
			i += 8888;
		}
		else if ((i % 1000000) / 100000 == 0) {
			i += 88888;
		}
	}
	return -1;
}

int amountIntrestingNumbers(int number) {
	int amount = number / 10;

	if (number % 10 == 9)
		++amount;
	return amount;
}

std::string convertToRomanian(int number) {
	std::string num;
	std::string* units = new std::string[]{ "","I","II","III","IV","V","VI","VII","VIII","IX" };
	for (int i = 0; i < number / 1000; i++)
	{
		num.push_back('M');
	}
	number %= 1000;
	if ((number % 500) / 100 + 5 == 9)
	{
		num += "CM";
		number %= 900;
	}
	else if (number / 500 > 0)
	{
		num.push_back('D');
		number %= 500;
	}
	for (int i = 0; i < number / 100; i++)
	{
		num.push_back('C');
	}
	number %= 100;


	if ((number % 50) / 10 + 5 == 9)
	{
		num += "XC";
		number %= 90;
	}
	else if (number / 50 > 0)
	{
		num.push_back('L');
		number %= 50;
	}
	if (number % 10 == 4)
	{
		num += "XL";
		number %= 40;
	}

	for (int i = 0; i < number / 10; i++)
	{
		num.push_back('X');
	}
	number %= 10;
	num += units[number];
	return num;
}

void findNoneZeroNumber(std::string& number, int index) {
	if (number[index] == '0')
		findNoneZeroNumber(number, index + 1);
	number[index] -= 1;
	number[index - 1] = '3';

}

std::string convertToWrongThirdSystem(std::string number) {
	reverseStr(number);
	for (int i = 0; i < number.length(); i++)
	{
		while (number[i] == '0')
			findNoneZeroNumber(number, i + 1);

	}
	reverseStr(number);

	return number;
}

bool multiplieBySeven(int number) {
	int num = 0;
	for (int i = 0; num < number; i++)
	{
		num = (i << 2) + (i << 1) + i;
	}
	if (num == number)
		return true;
	return false;
}

bool multiplieByTwentyNune(int number) {
	int num = 0;
	for (int i = 0; num < number; i++)
	{
		num = (i << 4) + (i << 3) + (i << 2) + i;
	}
	if (num == number)
		return true;
	return false;
}

bool multiplieByBigValue(int number) {
	int num = 0;
	for (int i = 0; num < number; i++)
	{
		num = (i << 7) + (i << 4) + (i << 2) + i;
	}
	if (num == number)
		return true;
	return false;
}