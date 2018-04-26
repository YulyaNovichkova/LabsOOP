#include "Person.h"
#include "PersonListClass.h"
using namespace std;

int Menu5()
{
	char key;
	int index;
	PersonList* list = new PersonList();
	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Add Person." << endl
			<< "2. Find Person with Index." << endl
			<< "3. Get Person Index." << endl
			<< "4. Remove Person by index." << endl
			<< "5. Clear list." << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case '1':
		{
			Person* person = Person::CreateRandomPerson();
			list->Add(person);
			list->Show();
			break;
		}
		case '2':
		{
			cout << "Enter the index:" << endl;
			cin >> index;
			Person* person = list->Find(index);
			Person::ShowPerson(person);
			break;
		}
		case '3':
		{
			Person* person = Person::Read();
			index = list->IndexOf(person);
			if (index == -1)
			{
				cout << "Person not found." << endl;
			}
			else
			{
				cout << "Index: " << index << endl;
			}
			break;
		}
		case '4':
		{
			cout << "Enter the index:" << endl;
			cin >> index;
			list->RemoveAt(index);
			list->Show();
			break;
		}
		case '5':
		{
			list->Clear();
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