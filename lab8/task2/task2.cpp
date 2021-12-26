#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"functions.h"
using namespace std;

struct Sportsman
{
	char* country = (char*)calloc(20,sizeof(char));
	char* teamName = (char*)calloc(20, sizeof(char));
	char* firstName = (char*)calloc(20, sizeof(char));
	char* secondName = (char*)calloc(20, sizeof(char));
	char* patronymic = (char*)calloc(20, sizeof(char));
	char* number;
	int age = 0;
	int height = 0;
	double weight = 0;

};

Sportsman* createArray(int& siz);
Sportsman* createArrayOfSportsman(Sportsman* sportsman, int& size, const int& index, const int& startIndex, const int& endIndex);
void inputSportsmanInformation(Sportsman& sportsman, const int& index);
void printString(Sportsman* sportsman, const int& i);
void printData(Sportsman* sportsman, int& size);
void writeData(Sportsman* sportsman, ofstream& file, const int& size);
Sportsman* addElementsOfSportsman(Sportsman* sportsman, int& size);
Sportsman* choiceOfFilling(Sportsman* sportsman, int& size, const int& startIndex, const int& endIndex);
Sportsman* deleteElementOfSportsman(Sportsman* sportsman, int& size);
void editElement(Sportsman* sportsman,int& size);
void writeColumns(ofstream& file);

int main() {

	ofstream file("d:\\txtFiles\\task1.txt",ios::trunc);
	Sportsman* sportsman;
	int answer, size;

	sportsman = createArray(size);

	while (true) {
		cout << '\n' << "Enter what u gonna do: " << '\n';
		cout << "Enter 1 - to print data, 2 - to edit element, 3 - to add elements, 4 - delete arr ,5 - close and save file" << '\n';

		answer = inputInt(0, 7);

		if (answer == 1) printData(sportsman, size);
		else if (answer == 2) editElement(sportsman, size);
		else if (answer == 3) sportsman = addElementsOfSportsman(sportsman, size);
		else if (answer == 4) sportsman = deleteElementOfSportsman(sportsman, size);
		else if (answer == 5) break;
	}
	writeColumns(file);

	for (int i = 0; i < size; i++)
	{
		writeData(sportsman, file, i);
	}

	file.close();
	free(sportsman);
}

void writeColumns(ofstream& file) {

	file.width(20);
	file << "First name";
	file.width(20); 
	file << "Second name"; 
	file.width(20);
	file << "Patronymic"; 
	file.width(20);
	file << "Number";
	file.width(20);
	file << "Country";
	file.width(20);
	file << "Team name";
	file.width(20);
	file << "Age";
	file.width(20);
	file << "Height"; 
	file.width(20);
	file << "Weight" << '\n';
}

void writeData(Sportsman* sportsman,ofstream& file,const int& i) {
		file << i + 1;
		file << " " << sportsman[i].firstName;
		file.width(20);
		file << sportsman[i].secondName;
		file.width(20);
		file << " " << sportsman[i].patronymic;
		file.width(20);
		file << sportsman[i].number;
		file.width(20);
		file << sportsman[i].country;
		file.width(20);
		file << sportsman[i].teamName;
		file.width(20);
		file << " " << sportsman[i].age;
		file.width(20);
		file << sportsman[i].height;
		file.width(20);
		file << sportsman[i].weight << '\n';
		file.flush();
}

Sportsman* createArray(int& size) {
	cout << "How u wanna create ur structure of student: " << '\n';
	cout << "Enter size of array" << '\n';

	size = inputInt(0, 20);

	Sportsman* sportsman = (Sportsman*)calloc(size, sizeof(Sportsman));
	return choiceOfFilling(sportsman, size, 0, size);
	
}

void inputSportsmanInformation(Sportsman& sportsman, const int& index) {
	cout << "Enter first name of sportsman: ";
	sportsman.firstName = inputCharStr(20);
	cout << "Enter last name of sportsman: ";
	sportsman.secondName = inputCharStr(20);
	cout << "Enter Patronymic of sportsman : ";
	sportsman.patronymic = inputCharStr(20);
	cout << "Enter number of sportsman: ";
	sportsman.number = inputCharStr(20);
	cout << "Enter team name of sportsman: ";
	sportsman.teamName = inputCharStr(20);
	cout << "Enter country of sportsman: ";
	sportsman.country = inputCharStr(20);
	cout << "Enter age of sportsman: ";
	sportsman.age = inputInt(0, 200);
	cout << "Enter height of sportsman(in cm): ";
	sportsman.height = inputDoub(0, 300);
	cout << "Enter weight of sportsman(in kg): ";
	sportsman.weight = inputDoub(0, 200);
	
}

Sportsman* createArrayOfSportsman(Sportsman* sportsman, int& size, const int& index, const int& startIndex, const int& endIndex) {

	for (int i = startIndex; i < endIndex; i++)
	{
		inputSportsmanInformation(sportsman[i], index);

		if (i != size - 1) {
			cout << "Do u want enter information about next student(1 - yes, 2 - no)" << '\n';
			if (inputInt(0, 3) == 1) {
				continue ;
			}
			else {
				size = i + 1;
				break;
			}

		}
	}

	return sportsman;
}

void printData(Sportsman* sportsman, int& size) {

	cout << setw(5) << "First name" << setw(20) << "Second name" << setw(20) << "Patronymic" << setw(20) 
	<< "Number" << setw(20) << "Country" << setw(20) << "Team name" << setw(20)
	<< "Age" << setw(20) << "Height" << setw(20) << "Weight" << '\n';

	for (int i = 0; i < size; i++)
	{
		printString(sportsman, i);
	}
}

void printString(Sportsman* sportsman, const int& i) {
	cout << i + 1 << " " << sportsman[i].firstName << setw(20) << sportsman[i].secondName << setw(20) 
	<< sportsman[i].patronymic << setw(20) << sportsman[i].age << setw(20) << sportsman[i].number << setw(20) 
	<< sportsman[i].country << setw(20) << sportsman[i].teamName << setw(20) << sportsman[i].age << setw(20) 
	<< sportsman[i].height << setw(20) << sportsman[i].weight << '\n';

}

Sportsman* choiceOfFilling(Sportsman* sportsman, int& size, const int& startIndex, const int& endIndex) {

	return createArrayOfSportsman(sportsman, size, 0, startIndex, endIndex);
}

Sportsman* addElementsOfSportsman(Sportsman* sportsman, int& size) {
	cout << "How many position would u want to add" << '\n';

	int amountAddElements = inputInt(0, 10), oldSize = size;
	size += amountAddElements;
	Sportsman* newSportsman = (Sportsman*)calloc(size, sizeof(Sportsman));

	for (int i = 0; i < oldSize; i++)
		newSportsman[i] = sportsman[i];

	cout << "How u wanna add ur elements" << '\n';

	return choiceOfFilling(newSportsman, size, oldSize, size);

}

Sportsman* deleteElementOfSportsman(Sportsman* sportsman, int& size)
{
	cout << "Which element u want to delete: " << '\n';

	int deleteIndex = inputInt(0, size + 1), index = 0;
	Sportsman* newSportsman = new Sportsman[size - 1];

	for (int i = 0; i < size; i++)
	{
		if (deleteIndex - 1 != i) {
			newSportsman[index] = sportsman[i];
			index++;
		}
	}
	size -= 1;

	return newSportsman;
}

void editElement(Sportsman* sportsman, int& size){
	cout << "Do u wanna edit whole element(1 - yes, 2- no)" << '\n';
	int answer = inputInt(0, 3);

	cout << "Enter element what u wanna edit" << '\n';
	int index = inputInt(0, size + 1) - 1;

	if (answer == 1) {
		inputSportsmanInformation(sportsman[index],0);
	}
	else {
		cout << "Enter field which u want insert( 1 - First name, 2 - Second name, 3 - Patronymic, 4 - Numebr, 5 -  Team name, 6 - Country, 7 - Age, 8 - Height, 9 - Weight" << '\n';
		answer = inputInt(0,10);
		if (answer == 1) sportsman[index].firstName = inputCharStr(20);
		if (answer == 2) sportsman[index].secondName = inputCharStr(20);
		if (answer == 3) sportsman[index].patronymic = inputCharStr(20);
		if (answer == 4) sportsman[index].number = inputCharStr(20);
		if (answer == 5) sportsman[index].teamName = inputCharStr(20);
		if (answer == 6) sportsman[index].country = inputCharStr(20);
		if (answer == 7) sportsman[index].age = inputInt(0, 200);
		if (answer == 8) sportsman[index].height = inputDoub(0, 300);
		if (answer == 9) sportsman[index].weight = inputDoub(0, 200);
	}
}