////������������ ������ �5. ������� 8. ���������: �������� �. �.
//����� f(n) - ���������� �������� �������� ������������ ����� n.�� ���������
//������������ n ���������� ��������� �������� ����� f(1) + f(2) + ... + f(n).
#include<iostream>
#include"Functions.h"

int main() {
	std::cout << "Enter number: " << std::endl;
	int number = input(0, 2147483647);
	std::cout << recursiveSum(number);
	return 0;
}	
