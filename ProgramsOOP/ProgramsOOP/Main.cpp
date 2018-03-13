#include <cstdlib>
#include "AllLabs.h"
#include <iostream>

using namespace std;

int Menu()
{
	char key;

	do
	{
		cout << "\t Choose laboratory work:\n\n\n"
			<< "1. Task 1;" << endl
			<< "2. Task 2;" << endl
			<< "3. Task 3;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
//TODO: ����������� ���������� �������� ���������� ���� RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: � ��������� ���� ��� � ����������� �� ����������
			// �������, ��� ��� ���������.
			case '1':
				LaunchTask1();
				break;

			case '2':
				LaunchTask2();
				break;

			case '3':
				LaunchTask3();
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