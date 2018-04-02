#include <cstdlib>
#include "AllLabs.h"
#include <iostream>

using namespace std;

int Menu()
{
	char key;

	do
	{
		cout << "\t Choose laboratory work:" << endl << endl << endl
			<< "1. Task 1;" << endl
			<< "2. Task 2;" << endl
			<< "3. Task 3;" << endl
			<< "4. Task 4;" << endl
			<< "5. Task 5;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			case '1':
				LaunchTask1();
				break;

			case '2':
				LaunchTask2();
				break;

			case '3':
				LaunchTask3();
				break;
			case '4':
				LaunchTask4();
				break;
			case '5':
				LaunchTask5();
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