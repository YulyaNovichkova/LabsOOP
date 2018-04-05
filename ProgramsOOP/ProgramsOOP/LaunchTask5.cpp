#include "PersonClass.h"
#include "PersonListClass.h"
using namespace std;

int Menu5()
{
	char key;
	PersonList list;

	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Add Person." << endl
			<< "2. Find Person with Index." << endl
			<< "3. Get Person Index." << endl
			<< "4. Remove Person." << endl
			<< "5. Clear list." << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case '1':
		{
			list.Add(Person::CreateRandomPerson());
			list.Show();
			break;
		}
		case '2':
		{

			break;
		}
		case '3':
		{

			break;
		}
		case '4':
		{

			break;
		}
		case '5':
		{
			list.Clear();
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