#include <cstdlib>
#include "AllLabs.h"
#include <iostream>

//TODO: ������� ��� ������������ 1, 2, � 3 ������������ - ��� �����������
// ������� ������ � ��������� � ������� ��������� ����.
//����������.
//TODO: 4 ������������ ������ - �������, ����� ������������. �������� ������ Stack
//TODO: ���������� ��������� ����� � ���������:
// - ������ ����� Lab1, Lab2, Lab3 ������� ����� Person, List, Stack, Demo (��� ����� ������� launchTask)

using namespace std;

int Menu()
{
	char key;

	do
	{
		cout << "\t Choose laboratory work:" << endl << endl << endl
			<< "4. Task 4;" << endl
			<< "5. Task 5;" << endl
			<< "6. Task 6;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			//case '4':
			//	LaunchTask4();
			//	break;
			case '5':
				LaunchTask5();
				break;
			case '6':
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