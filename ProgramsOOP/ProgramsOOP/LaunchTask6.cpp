#include "PersonClass.h"
#include "PersonListClass.h"
#include "AdultClass.h"
#include "ChildClass.h"
using namespace std;

int Menu6()
{
	char key;
	int index;
	//PersonList* list = new PersonList();
	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case '0':
			cout << " Welcome back." << endl;
			break;
		default:
			cout << " Mistake, try again." << endl;
			break;
		}
	} while (key != '0');
	int k = atoi(&key);
	return(k);
}

void LaunchTask6()
{
	int key = Menu6();
	cout << key << endl;
	system("pause");
}