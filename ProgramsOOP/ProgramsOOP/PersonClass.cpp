#include "PersonClass.h"

Person ReadPerson()
{
	Person person;
	cout << "Enter surname: ";
	cin >> person.SetSurname;
	cout << "Enter name: ";
	cout << "Sex: Enter '0' for female, '1' for male: ";
	int sex;
	cin >> sex;
	switch (sex)
	{
	case 0:
	{
		person.SetSex = Female;
		break;
	}
	case 1:
	{
		person.SetSex = Male;
		break;
	}
	}
	do
	{
		cout << "Enter the age: ";
		cin >> person.SetAge;
		if (person.SetAge < 0)
		{
			cout << "An invalid value was entered!" << endl;
		}
	} while (person.SetAge < 0);
	return person;
}

void ShowPerson(Person person)
{
	cout << "Surname: " << person.GetSurname;
	cout << endl << "Name: " << person.GetName;
	switch (person.GetSex)
	{
	case 0:
		cout << endl << "Sex: female";
		break;
	case 1:
		cout << endl << "Sex: male";
		break;
	default:
		break;
	}
	cout << endl << "Age: " << person.GetAge << endl;
}