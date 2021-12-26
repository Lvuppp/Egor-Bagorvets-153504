//////Лабораторная работа №8 выполнил Багровец Е.С
// 
//// 
//// Реализовать любой из 30 вариантов (кроме уже реализованных вами)
//заданий используя классы.Реализовать корректировку записей внутри файла без
//полной перезаписи файла.Все методы класса должны иметь модификатор public,
//а остальные поля – private;

#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<filesystem>
#include<io.h>
#include"functions.h"

using namespace std;

ofstream file("d:\\txtFiles\\task2.txt",ios::trunc);
ifstream out("d:\\txtFiles\\task2.txt");

class Book
{
public:
	int getNumber();
	void setNumber(int num);
	string getAuthor();
	void setAuthor(string str);
	string getTitle();
	void setTitle(string str);
	string getPublishing();
	void setPublishing(string str);
	short getYear();
	void setYear(short num);
	int getAmountPages();
	void setAmountPages(int num);

private:
	int _number = 0;
	string _author = "-";
	string _title = "-";
	string _publishing = "-";
	short _year = 0;
	int _amountPages = 0;
};

int Book::getNumber() {
	return _number;
}
void Book::setNumber(int num) {
	_number = num;
}

string Book::getAuthor()
{
	return _author;
}
void Book::setAuthor(string str)
{
	_author = str;
}

string Book::getTitle()
{
	return _title;
}
void Book::setTitle(string str)
{
	_title = str;
}

string Book::getPublishing()
{
	return _publishing;
}
void Book::setPublishing(string str)
{
	_publishing = str;
}

short Book::getYear()
{
	return _year;
}
void Book::setYear(short num)
{
	_year = num;
}

int Book::getAmountPages()
{
	return _amountPages;
}
void Book::setAmountPages(int num)
{
	_amountPages = num;
}


class Books
{

public:

	void createArr();
	void printArr();
	void putElement(const int& index);
	void deleteStr(const int& index);
	void editStr(const int& index);
	void addStr();
	int getSize();

private:

	Book* _books = new Book[_size];
	int _size = 0;

	int* _lengthOfStr = new int[_size];

	void choiceOfFilling(Book* students, int& size, const int& startIndex, const int& endIndex);
	void createArrayOfBooks(Book* books, int& size, const int& index, const int& startIndex, const int& endIndex);
	void inputBooksInformation(Book& books, const int& index);
	void printStr(const int& index);
	void writeFile(const int& index);
};

void Books::createArr()
{
	cout << "How u wanna create ur structure of student: " << '\n';
	cout << "Enter size of array" << '\n';

	_size = inputInt(0, 20);
	_books = new Book[_size];

	choiceOfFilling(_books, _size, 0, _size);
	for (int i = 0; i < _size; i++)
	{
		writeFile(i);
		if(i != 0)
			_lengthOfStr[i] = (int)file.tellp() - (int)_lengthOfStr[i - 1];
		else
			_lengthOfStr[i] = (int)file.tellp();
	}

}

void Books::printArr()
{
	cout << "  " << "Number" << setw(20) << "Author" << setw(20) << "Title" << setw(20) << "Publishing" << setw(20)
		<< "Year" << setw(20) << "Amount pages" << '\n';
	for (int i = 0; i < _size; i++)
	{
		printStr(i);
	}
}

void Books::putElement(const int& index)
{
	file.seekp(_lengthOfStr[index], ios_base::beg);
	file << "hello";
}

void Books::deleteStr(const int& index)
{
	
	Book* oldBooks = _books;
	int count = 0;
	_books = new Book[_size - 1];

	for (int i = 0; i < _size; i++)
	{
		if (i == index - 1)
			continue;
		_books[count] = oldBooks[i];
		++count;
	}
	_size -= 1;

	delete[] oldBooks;

	if (index - 1== 0) {
		file.seekp(0);
	}
	else {
		file.seekp(_lengthOfStr[index - 1]);
	}

	for (int i = index - 1; i < _size; i++)
	{
		writeFile(i);
	}

	file.width(200);
	file << "";

}

void Books::editStr(const int& index)
{
	if (index - 1 == 0) {
		file.seekp(0);
	}
	else {
		file.seekp(_lengthOfStr[index - 1]);
	}
	inputBooksInformation(_books[index - 1],0);
	writeFile(index - 1);
}

void Books::addStr()
{
	int oldSize = _size;
	_size += 1;
	Book* newBooks = _books;
	_books = new Book[_size];
	for (int i = 0; i < oldSize; i++)
		_books[i] = newBooks[i];

	cout << "How u wanna add ur elements" << '\n';

	choiceOfFilling(_books, _size, oldSize, _size);
	for (int i = oldSize; i < _size; i++)
	{
		writeFile(i);
		if (i != 0)
			_lengthOfStr[i] = (int)file.tellp() - (int)_lengthOfStr[i - 1];
		else
			_lengthOfStr[i] = (int)file.tellp();
	}
}

void Books::choiceOfFilling(Book* _books, int& size, const int& startIndex, const int& endIndex) {
	cout << "Enter of a predetermined number of structures(enter 1)  or  enter before the appearance of a structure with a given attribute(enter 2)" << '\n';

	if (inputInt(0, 3) == 1) {
		createArrayOfBooks(_books, _size, 0, startIndex, endIndex);
	}
	else {
		cout << "Enter field which u want insert( 1 - Number, 2 - Author, 3 - Title, 4 - Publishing, 5 - Year, 6 - Amount of pages" << '\n';

		createArrayOfBooks(_books, _size, inputInt(0, 7), startIndex, endIndex);
	}
}

void Books::createArrayOfBooks(Book* _books, int& size, const int& index, const int& startIndex, const int& endIndex) {

for (int i = startIndex; i < endIndex; i++)
	{
		inputBooksInformation(_books[i], index);

		if (i != _size - 1) {
			cout << "Do u want enter information about next student(1 - yes, 2 - no)" << '\n';
			if (inputInt(0, 3) == 1) {
				continue;
			}
			else {
				_size = i + 1;
				break;
			}

		}
	}
}

void Books::inputBooksInformation(Book& _books, const int& index) {
	if (index == 1) return;
	cout << "Enter number of book(0-100): ";
	_books.setNumber(inputInt(0, 100));
	if (index == 2) return;
	cout << "Enter author of book: ";
	_books.setAuthor(inputStr(0, 30));
	if (index == 3) return;
	cout << "Enter title of book : ";
	_books.setTitle(inputStr(0, 30));
	if (index == 4) return;
	cout << "Enter publishing of book: ";
	_books.setPublishing(inputStr(0, 30));
	if (index == 5) return;
	cout << "Enter year of book: ";
	_books.setYear(inputInt(0,2022));
	if (index == 6) return;
	cout << "Enter amount of pages: ";
	_books.setAmountPages(inputInt(0,2000));
	
}

void Books::printStr(const int& index) {
	cout << index + 1 << " " << _books[index].getNumber() << setw(20) << _books[index].getAuthor() << setw(20) << _books[index].getTitle()
		<< setw(20) << _books[index].getPublishing() << setw(20) << _books[index].getYear() << setw(20) << _books[index].getAmountPages() << '\n';
}

void Books::writeFile(const int& index) {
	file << index + 1;
	file << _books[index].getNumber();
	file.width(20);
	file << _books[index].getAuthor();
	file.width(20);
	file << _books[index].getTitle();
	file.width(20);
	file << _books[index].getPublishing();
	file.width(20);
	file << _books[index].getYear();
	file.width(20);
	file << _books[index].getAmountPages();
	file.width(20);
	file << '\n';
	file.flush();
}

int Books::getSize() {
	return _size;
}

int main() {
	Books books;
	books.createArr();
	int answer;
	while (true) {
		answer = inputInt(0, 6);
		if(answer == 1)books.printArr();
		if(answer == 2)books.deleteStr(inputInt(0, books.getSize() + 1));
		if(answer == 3)books.editStr(inputInt(0, books.getSize() + 1));
		if(answer == 4)books.addStr();
		if (answer == 5)break;
	}
}

