#include "Person.h"
#include "PersonList.h"
#include "Adult.h"
#include "Child.h"
using namespace std;

int Menu6()
{
	char key;
	PersonList* list = new PersonList();
	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Add Person;" << endl
			<< "2. Get Description;" << endl
			<< "3. Get Count;" << endl
			<< "4. Clear list;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case '1':
		{
			int randomizer = rand() % 2;
			switch (randomizer)
			{
				case 0:
				{
					Child* child = Child::CreateRandomChild();
					list->Add(child);
					break;
				}
				case 1:
				{
					Adult* adult = Adult::CreateRandomAdult();
					list->Add(adult);
					break;
				}
			}
			list->Show();
		}
			break;
		case '2':
		{
			int index;
			list->Show();
			cout << "Enter index:" << endl;
			cin >> index;
			if (index < 0 || index > list->GetCount())
			{
				cout << "Incorrect value! Try again." << endl;
				cin >> index;
			}

			Person* person = list->Find(index);
			if (person == NULL)
			{
				cout << "Person not found." << endl;
			}
			else
			{
				cout << person->GetDescription();
			}
			cout << endl;
		}
			break;
		case '3':
		{
			cout << "List size: " << list->GetCount() << endl;
		}
			break;
		case '4':
		{
			cout << "List cleared" << endl;
			list->Clear();
		}
			break;
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