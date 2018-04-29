#include <cstdlib>
#include "AllLabs.h"
#include <iostream>

//TODO: удалить всю лабораторную 1, 2, и 3 лабораторные - уже неактуальны
// Удалить вместе с функциями и файлами исходного кода.
//ИСПРАВЛЕНО.
//TODO: 4 лабораторную работу - удалить, также неактуальная. Оставить только Stack
//TODO: Переделать структуру папок в программе:
// - вместо папок Lab1, Lab2, Lab3 сделать папки Person, List, Stack, Demo (где лежат функции launchTask)

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