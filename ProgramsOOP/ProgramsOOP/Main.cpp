#include <cstdlib>
#include "Demo.h"
#include <iostream>

//TODO: ������� ��� ������������ 1, 2, � 3 ������������ - ��� �����������
// ������� ������ � ��������� � ������� ��������� ����.
//�������.
//TODO: 4 ������������ ������ - �������, ����� ������������. �������� ������ Stack
//�������.
//TODO: ���������� ��������� ����� � ���������:
// - ������ ����� Lab1, Lab2, Lab3 ������� ����� Person, List, Stack, Demo (��� ����� ������� launchTask)

using namespace std;

int Menu()
{
	char key;

	do
	{
		cout << "\t Choose laboratory work:" << endl << endl << endl
			<< "1. Task 5;" << endl
			<< "2. Task 6;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			case '1':
				LaunchTask5();
				break;
			case '2':
				LaunchTask6();
				break;

			case '0':
				cout << " Welcome back." << endl;
				break;

			default:
				cout << " Mistake. Try again." << endl;
				break;
		}
	} while (key != '0');
	int k = atoi(&key);
	return(k);
};

int main()
{
	int key = Menu();
	cout << key << endl;
	system("pause");
	return(0);
}