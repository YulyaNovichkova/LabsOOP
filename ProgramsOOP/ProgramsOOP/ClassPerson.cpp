#include "PersonClass.h"
#include "PersonListClass.h"
using namespace std;

int Menu5()
{
	Person person1("Ivanov", "Ivan", Male, 18);
	//Person person2;
	//Person person3;
	char key;
	int index;

	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Add new element." << endl
			<< "2. Delete element." << endl
			<< "3. Return a reference to the item in the list." << endl
			<< "4. Insert random element." << endl
			<< "5. Clear list." << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case '1':
		{
			person1.Show();
			break;
		}
		case '2':
		{
		//	cout << "Enter the index of element:" << endl;
			//cin >> index;
			//Remove(list, index);
			//ListShow(list);
			break;
		}
		case '3':
		{/*
			cout << "Enter the index of element:" << endl;
			cin >> index;
			Person* person = GetPerson(list, index);
			if (person)
			{
				ShowPerson(*GetPerson(list, index));
			}
			else
			{
				cout << "Invalid value entered!" << endl;
			}*/
			break;
		}
		case '4':
		{
			//cout << "Enter the index of element:" << endl;
			//cin >> index;
			//InsertElement(list, CreateRandomPerson(), index);
			//ListShow(list);
			break;
		}
		case '5':
		{
			//Clear(list);
			break;
		}
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
};

void LaunchTask5()
{
	int key = Menu5();
	cout << key << endl;
	system("pause");
}