//������������ ������ �6. ������� 9. ���������: �������� �. �.
//
//� �������� ������, ��������� �� ����, ���� � ������ ��������, �������
//����� ���� �����.
#include<iostream>
#include<string>
#include<iomanip>
#include"../strFunctions/strFunctions.h"
using namespace std;

int main() {
	string line = input(0, 101);
	cout<< setprecision(7) << numberSum(line);

	return 0;
}