//������������ ������ �5. ������� 2. ���������: �������� �. �.
//��� ��������� ����������� ������� B �� N ��������� ����� ������������
//����������, ����������� �� �������.����������� ������� ���������
//������ ��� �������� ��� ������ �� ������� �������.����������� ������
//�����������, ����� ��������� ������ ���� �������.
#include<iostream>

int main() {
	std::cout << "Enter size of array: " << std::endl;
	int size = input();
	int* array = new int[size];
	std::cout << "Enter elements of array: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		array[i] = input();
	}
	int elementsMultiply = multiplyOfElements(array, size-1, size / 2) * multiplyOfElements(array, size/2-1, 0);
	std::cout << elementsMultiply;
}