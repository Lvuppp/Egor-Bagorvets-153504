///������������ ������ �7. ������� 10. ���������: �������� �. �.
//
//�������� ����� �������� �������� � ��� ����� ���������� 240
//����� ����.������ � ���� ��������� ���������������, ������� ��������
//�� � ���� �� �����.��������������� ��� �� �������, ���������� ��� ������
//����������.��� �� ��������, ��� �������, ������� ��� �����, ������� �
//������� 24 �����.�� ��������� �������� ��� ���, �� ���� 48 �����.�
//�������� ���� ���� �����, �������� �� ����� ������������, ����� ������, �
//����� ������ ����� ��.����� ������� ����� ��� ������ ?

#include <iostream>
using namespace std;

int main()
{
	int time, n;
	cout << "Time of death(minutes):";
	cin >> time;
	cout << "Death slave:";
	cin >> n;
	cout << (time / 30) + (n - 1) * (240 / 5) + 1;

	return 0;
}