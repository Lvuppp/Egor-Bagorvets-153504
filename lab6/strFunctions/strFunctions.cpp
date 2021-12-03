#include<iostream>
#include<string>
#include"strFunctions.h"

std::string input(int minValue, int maxValue) {
	std::string text;
	while (true)
	{
		getline(std::cin,text);
		if (text.length() < maxValue && text.length() > minValue)
			return text;
		std::cin.clear();
		std::cin.ignore(32000, '\n');
		text = "";
		std::cout << "Enter correct word" << std::endl;
	}
}

int inputInt(int minValue, int maxValue) {
	int x;
	while (true)
	{
		std::cin >> x;
		if (x < maxValue && x > minValue)
			return x;
		std::cin.clear();
		std::cin.ignore(32000, '\n');
		std::cout << "Enter correct word" << std::endl;
	}
}

void getTextInLowerRegister(std::string text) {
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = (char)tolower(text[i]);
	}
}

int numberSum(std::string line) {

	double sum = 0,tmp;
	int count = 0, fraction, ex;
	bool minus, exMinus;

	while (count < line.length()) {
		minus = false;

		if (isdigit(line[count])) {
			if (count != 0 && line[count - 1] == '-') 
			{
				tmp = line[count] - '0';

				minus = true;
			}
			else {
				tmp = line[count] - '0';
			}

			++count;

			while (isdigit(line[count])) {
				tmp = tmp * 10 + (line[count] - '0');

				++count;
			}

			fraction = 1;

			if (line[count] == '.' && isdigit(line[count + 1])) {
				++count;

				while (isdigit(line[count])) {
					fraction *= 10;

					tmp = tmp + (long double)(line[count] - '0') / fraction;

					++count;
				}
			}

			if ((line[count] == 'e' || line[count] == 'E') && (isdigit(line[count + 1]) || (line[count + 1] == '+' && isdigit(line[count + 2])) || (line[count + 1] == '-' && isdigit(line[count + 2])))) {
				exMinus = false;

				++count;

				if (line[count] == '-') {
					exMinus = true;
					++count;
				}
				else if (line[count] == '+') {
					++count;
				}

				ex = line[count] - '0';

				++count;

				while (isdigit(line[count])) {
					ex = ex * 10 + (line[count] - '0');
					++count;
				}

				if (exMinus) {
					ex *= -1;
				}

				tmp *= pow(10, ex);
			}

			if (minus) {
				tmp *= -1;
			}


			sum += tmp;
		}

		++count;
	}

	return sum;
}

bool makeWord(std::string firstWord, std::string secondWord, int index) {

	int movementIndex = 0;

	for (index; index < firstWord.length(); index++)
	{
		if (firstWord[index] != secondWord[movementIndex])
			break;
		++movementIndex;
	}
	index -= 2;
	while (movementIndex != secondWord.length())
	{
		if (index == -1 || firstWord[index] != secondWord[movementIndex])
			return false;
		--index;
		++movementIndex;
	}

	return true;

}

char canMakeWord(std::string firstWord, std::string secondWord) {
	for (int i = 0; i < firstWord.length(); i++)
	{
		if (firstWord[i] == secondWord[0])
		{
			if (makeWord(firstWord, secondWord, i)) {
				return 'Y';
			}
		}
	}
	return 'N';
}

long long factorial(int a) {
	if (a == 1)
		return 1;
	return a * factorial(a - 1);
}

bool isPolindrom(std::string word)
{
	for (int i = 0; i < word.length() / 2; i++)
	{
		if (word[i] != word[word.length() - i - 1])
			return false;
	}
	return true;
}

int maxPolinndromLine(std::string word) {

	if (word.length() == 0)
		return -1;

	int maxNonePolindromLine = 0;
	std::string nonePolindromLine;
	for (int i = 0; i < word.length(); i++)
	{
		nonePolindromLine += word[i];
		if (!isPolindrom(nonePolindromLine) || i == 0)
			maxNonePolindromLine++;
		else
			break;
	}
	return maxNonePolindromLine;
}

void getStr(std::string& text,const int& maxValue) {
	
	std::string inputText;

	while (true) {
		getline(std::cin, inputText);
		
		if (inputText == "" && text.length() + inputText.length() < maxValue)
			break;
		
		text += (inputText + '\n');
	}

}

int findWordAmount(const int& L,const int& m,std::string s1,std::string s2) {
	int  indexFirstPref = 0, indexSecondPref = 0, amount = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[indexFirstPref]) {
			for (int j = i; j < s1.length(); j++)
			{
				if (s1[j] == s2[indexFirstPref])
				{
					++indexFirstPref;
				}
				else {
					indexFirstPref = 0;
					break;
				}
			}

		}
	}

	int length = L - (s1.length() + s2.length() - indexFirstPref);
	if (length > 0)
		amount = pow(26, length) * 2;
	else if (length == 0)
		amount = 1;
	else
		amount = 0;
	return amount % m;
}

int maxCount(char* str) {
	int counter = 1, maxCount = 1;

	if (strlen(str) == 0) 
		return 0;

	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i - 1] == str[i])
		{
			counter++;
			if (counter > maxCount)
				maxCount = counter;
		}
		else {
			counter = 1;
		}
	}

	return maxCount;
}

void translateToDigits(char* str) {

	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (*str == ' ')
		{
			str++;
			std::cout << " ";
			continue;
		}
		else
		{
			std::cout << tolower((int)*str++) - 96;
		}
	}
}

int getRepeat(std::string word) {
	std::string wordWithoutReapiting;

	if (word.length() == 0) 
		return 0;

	int count = factorial(word.length()), repeat = 0;

	getTextInLowerRegister(word);

	for (int i = 0; i < word.length(); i++)
	{
		if (isLetterReapiting(word[i], wordWithoutReapiting))
			continue;
		else
			wordWithoutReapiting.push_back(word[i]);
	}

	for (int i = 0; i < wordWithoutReapiting.length(); i++)
	{
		for (int j = 0; j < word.length(); j++)
		{
			if (word[j] == wordWithoutReapiting[i])
				++repeat;
		}
		count /= factorial(repeat);
		repeat = 0;
	}

	return count;
}

bool isLetterReapiting(const char& letter, std::string wordWithoutReapiting) {
	for (int i = 0; i < wordWithoutReapiting.length(); i++)
	{
		if (wordWithoutReapiting[i] == letter)
		{
			return true;
		}
	}
	return false;
}

std::string createNewText(std::string text) {
	std::string updateText;
	for (int i = 0; i < text.length(); i++)
	{
		if ((char)tolower(text[i]) == 'c')
		{
			if ((char)tolower(text[i + 1]) == 'e' || (char)tolower(text[i + 1]) == 'i' || (char)tolower(text[i + 1]) == 'y')
			{
				addSymbol(text, 's', i, updateText);
			}
			else
			{
				addSymbol(text, 'k', i, updateText);
				++i;
			}
		}
		else if ((char)tolower(text[i]) == 'q')
		{
			addSymbol(text, 'k', i, updateText);

			if ((char)tolower(text[i + 1]) == 'u')
			{
				addSymbol(text, 'v', i + 1, updateText);
				++i;
			}
		}
		else if ((char)tolower(text[i]) == 'x')
		{
			addSymbol(text, 'k', i, updateText);
			addSymbol(text, 's', i, updateText);
		}
		else if ((char)tolower(text[i]) == 'w')
		{
			addSymbol(text, 'v', i, updateText);
		}
		else if ((char)tolower(text[i]) == 'p' && (char)tolower(text[i + 1]) == 'h')
		{
			addSymbol(text, 'f', i, updateText);
			++i;
		}
		else if ((char)tolower(text[i]) == 't' && (char)tolower(text[i + 1]) == 'h')
		{
			addSymbol(text, 'z', i, updateText);
			++i;
		}
		else if ((char)tolower(text[i]) == 'e' && (char)tolower(text[i + 1]) == 'e')
		{
			addSymbol(text, 'i', i, updateText);
			++i;
		}
		else if ((char)tolower(text[i]) == 'o' && (char)tolower(text[i + 1]) == 'o')
		{
			addSymbol(text, 'u', i, updateText);
			++i;
		}
		else if ((char)tolower(text[i]) == 'y' && (char)tolower(text[i + 1]) == 'o' && (char)tolower(text[i + 2]) == 'u')
		{
			addSymbol(text, 'u', i, updateText);
			i += 2;
		}
		else if (((char)tolower(text[i]) == (char)tolower(text[i + 1])))
		{
			addSymbol(text, text[i], i, updateText);
			++i;
		}
		else if(!updateText.empty() && updateText.back() == (char)tolower(text[i])){
			++i;
		}
		else
		{
			updateText.push_back(text[i]);
		}

	}
	return updateText;
}

void addSymbol(const std::string& text, char sign, const int& index, std::string& updateText)
{
	if (!updateText.empty() && updateText.back() != sign)
	{
		if (!islower(text[index]))
			sign -= 32;
	
		updateText.push_back(sign);
	}
}
