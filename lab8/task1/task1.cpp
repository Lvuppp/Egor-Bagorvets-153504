////Лабораторная работа №8 выполнил Багровец Е.С
// 
//Для получения места в общежитии формируется список
//студентов, который включает ФИО студента, номер группы, средний балл, доход
//на члена семьи.Вывести фамилии студентов, у которых доход на члена
//семьи меньше двух минимальных зарплат(сортировка выбором по возрастанию)

#include <iostream>
#include<string>
#include<iomanip>
#include"functions.h"
using namespace std;

struct Student
{
	string firstName = "-";
	string lastName = "-";
	string patronymic = "-";
	int age = 0;
	string numberOfGroup = "-";
	double averageMark = 0;
	char sex = '-';
	double income = 0;
};

Student* createArray( int& size);
Student* choiceOfFilling(Student* students, int& size, const int& startIndex, const int& endIndex);
void inputStudentInformation(Student& students, const int& index);
Student* createArrayOfStudents(Student* students, int& size, const int& index, const int& startIndex, const int& endIndex);
void printData(Student* students, int& size);
Student* addElementsArrayOfStudents(Student* students, int& size);
void searchFieldArrayOfStudents(Student* students,int& size);
Student* updateArrayOfStudents(Student* students, int& size);
void insertSort(Student* students,const int& size);
void printString(Student* students, const int& i);
void mainTask(Student* students, const int& size);


int main() {
	Student* students ;
	int answer, size;

	students = createArray(size);

	while (true) {
		cout <<'\n' << "Enter what u gonna do: " << '\n';
		cout << "Enter 1 - to print data, 2 - to create new data, 3 - to add elements, 4 - to find element, 5 - to delete element, 6 - to sort , 7- main task" << '\n';

		answer = inputInt(0,8);

		if (answer == 1) printData(students, size);
		else if (answer == 2) students = createArray(size);	
		else if (answer == 3) students = addElementsArrayOfStudents(students, size);
		else if (answer == 4) searchFieldArrayOfStudents(students, size);
		else if (answer == 5) students = updateArrayOfStudents(students, size);
		else if (answer == 6) insertSort(students, size);
		else if (answer == 7) mainTask(students, size);
		
	}

	delete[] students;
}
void mainTask(Student* students, const int& size) {
	for (int i = 0; i < size; i++)
	{
		if (students[i].income > 800)
			printString(students, i);
	}
}

Student* createArray(int& size) {
	cout << "How u wanna create ur structure of student: " << '\n';
	cout << "Enter size of array" << '\n';
	
	size = inputInt(0, 20);

	Student* students = new Student[size];

	return choiceOfFilling(students, size, 0, size);
}

void inputStudentInformation(Student& students, const int& index){
	if (index == 1) return;
	cout << "Enter first name of student: ";
	students.firstName = inputStr(0, 30);
	if (index == 2) return;
	cout << "Enter last name of student: ";
	students.lastName = inputStr(0, 30);
	if (index == 3) return;
	cout << "Enter Patronymic of student : ";
	students.patronymic = inputStr(0, 30);
	if (index == 4) return;
	cout << "Enter age of student: ";
	students.age = inputInt(0, 200);
	if (index == 5) return;
	cout << "Enter sex of student: ";
	students.sex = inputChar();
	if (index == 6) return;
	cout << "Enter income of student: ";
	students.income = inputDoub(0, INT_MAX);
	if (index == 7) return;
	cout << "Enter number of group of student: ";
	students.numberOfGroup = inputStr(5, 7);
	if (index == 8) return;
	cout << "Enter average mark of student: ";
	students.averageMark = inputDoub(0, 10);
}

Student* createArrayOfStudents(Student* students, int& size, const int& index, const int& startIndex, const int& endIndex) {

	for (int i = startIndex; i < endIndex; i++)
	{
		inputStudentInformation(students[i], index);

		if (i != size - 1) {
			cout << "Do u want enter information about next student(1 - yes, 2 - no)" << '\n';
			if (inputInt(0, 3) == 1) {
				continue;
			}
			else {
				size = i + 1;
				break;
			}

		}
	}

	return students;
}

void printData(Student* students, int& size) {

	cout << setw(5) << "First name" << setw(20) << "Second name" << setw(20) << "Patronymic" << setw(10) << "Age" << setw(7) << "Sex" << setw(9)
		<< "Income" << setw(20) << "Number of group" << setw(20) << "Average mark" << '\n';

	for (int i = 0; i < size; i++)
	{
		printString(students, i);
	}
}

Student* addElementsArrayOfStudents(Student* students, int& size) {
	cout << "How many position would u want to add" << '\n';

	int amountAddElements = inputInt(0, 10), oldSize = size;
	size += amountAddElements;
	Student* newStudents = new Student[size];

	for (int i = 0; i < oldSize; i++)
		newStudents[i] = students[i];

	cout << "How u wanna add ur elements" << '\n';

	return choiceOfFilling(newStudents, size, oldSize, size);
}

void searchFieldArrayOfStudents(Student* students, int& size){

	cout << "Enter field which u want find( 1 - First name, 2 - Second name, 3 - Patronymic, 4 - Age, 5 - Sex, 6 - Dohod, 7 - Number of group, 8 - Average mark" << '\n';
	int index = inputInt(0, 9), counter = 0;

	if (index < 6 || index) {

		std::cout << "Enter what do you want to find: " << endl;

		string findLine = inputStr(0, 30);


		if (index == 1) {
			for (int i = 0; i < size; i++)
			{
				if (students[i].firstName.compare(findLine) == 0) {
					printString(students, i);
					counter++;
				}
			}

			if (counter == 0) {
				cout << "Unfortunately, we didn't find similar results." << endl;
			}
		}
		if (index == 2) {
			for (int i = 0; i < size; i++)
			{
				if (students[i].lastName.compare(findLine) == 0) {
					printString(students, i);
					counter++;
				}
			}

			if (counter == 0) {
				cout << "Unfortunately, we didn't find similar results." << endl;
			}
		}
		if (index == 3) {
			for (int i = 0; i < size; i++)
			{
				if (students[i].patronymic.compare(findLine) == 0) {
					printString(students, i);
					counter++;
				}
			}

			if (counter == 0) {
				cout << "Unfortunately, we didn't find similar results." << endl;
			}
		}
		if (index == 7) {
			for (int i = 0; i < size; i++)
			{
				if (students[i].numberOfGroup.compare(findLine) == 0) {
					printString(students, i);
					counter++;
				}
			}

			if (counter == 0) {
				cout << "Unfortunately, we didn't find similar results." << endl;
			}
		}
	}
	else if(index == 4 || index == 6 || index == 8) {

		std::cout << "enter the value by which you want to search: " << endl;
		double compareElement = inputInt(0, 60);

		if (index == 4) {
			for (int i = 0; i < size; i++)
			{
				if (students[i].age = compareElement) {
					printString(students, i);
					counter++;
				}
			}

			if (counter == 0) {
				cout << "Unfortunately, we didn't find similar results." << endl;
			}
		}
		if (index == 6) {
			for (int i = 0; i < size; i++)
			{
				if (students[i].income == compareElement) {
					printString(students, i);
					counter++;
				}
			}

			if (counter == 0) {
				cout << "Unfortunately, we didn't find similar results." << endl;
			}
		}
		if (index == 8) {
			for (int i = 0; i < size; i++)
			{
				if (students[i].averageMark == compareElement) {
					printString(students, i);
					counter++;
				}
			}

			if (counter == 0) {
				cout << "Unfortunately, we didn't find similar results." << endl;
			}
		}
	}

}

Student* updateArrayOfStudents(Student* students, int& size)
{
	cout << "Which element u want to delete: " << '\n';

	int deleteIndex = inputInt(0, size + 1),index = 0;
	Student* newStudents = new Student[size - 1];

	for (int i = 0; i < size; i++)
	{
		if (deleteIndex - 1 != i) {
			newStudents[index] = students[i];
			index++;
		}
	}
	size -= 1;

	return newStudents;
}

Student* choiceOfFilling(Student* students, int& size, const int& startIndex, const int& endIndex) {
	cout << "Enter of a predetermined number of structures(enter 1)  or  enter before the appearance of a structure with a given attribute(enter 2)" << '\n';
	
	if (inputInt(0, 3) == 1) {
		return createArrayOfStudents(students, size, 0, startIndex, endIndex);
	}
	else {
		cout << "Enter field which u want insert( 1 - First name, 2 - Second name, 3 - Patronymic, 4 - Age, 5 - Sex, 6 - Dohod, 7 - Number of group, 8 - Average mark" << '\n';

		return createArrayOfStudents(students, size, inputInt(0, 8), startIndex, endIndex);
	}
}

void insertSort(Student* students,const int& size){
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && students[j - 1].income > students[j].income; j--) {
			swap(students[j], students[j - 1]);
		}
	}
}

void printString(Student* students, const int& i) {
	cout << i + 1 << " " << students[i].firstName << setw(20) << students[i].lastName << setw(20) << students[i].patronymic << setw(10) << students[i].age << setw(7)
		<< students[i].sex << setw(9) << students[i].income << setw(20) << students[i].numberOfGroup << setw(20) << students[i].averageMark << '\n';

}