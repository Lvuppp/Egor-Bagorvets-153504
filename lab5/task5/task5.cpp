//������������ ������ �5. ������� 5. ���������: �������� �. �.
//��� ��������� ������������ ������ ����� �����.�������� ��������� �������
//������� ������ � ����������.������� ������������ ������ �� ���������,
//������������� � ������ �������� ������� ������� � ������� �������� ��������.
//��������� ������� �������������� ��������� ������������� �������.
//������� ��������� �� �����.
#include<iostream>
#include"Functions.h"
int main() {
	std::cout << "Enter size of array: " << std::endl;
	int columnSize = inputInt(), lineSize = inputInt(), column = 0, line = 0;

	int** array = createArray(columnSize, lineSize);
	std::cout << "Fill array" << std::endl;
	fillArray(array, columnSize, lineSize);

	updateArrayTask5(array, columnSize, lineSize);
	deleteMatrix(array, columnSize);
	
	return 0;
}