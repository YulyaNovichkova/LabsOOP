#include <iostream>
#include <iomanip>
#include "Function3.h"

using namespace std;

int Menu3()
{
	char key;

	do
	{
		cout << "\t Choose next step:\n\n\n"
			<< "1. Determine the length of a string;" << endl
			<< "2. Combining two strings into one new one;" << endl
			<< "5. Convert string to uppercase;" << endl
			<< "6. Convert string to lowercase;" << endl
			<< "9. MEN;" << endl
			<< "0. Exit. \n";

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			case '1':
				char str[51];
				cout << "Enter your string: " << endl;
				cin.get(str, 51);
				cout << "Your string consists of " << GetLength(str) << " characters." << endl;
				break;
			case '2':
			{
				char str1[50];
				char str2[50];
				char *strResult;
				cout << "Enter your first string: " << endl;
				cin.getline(str1, 50);
				cout << "Enter your second string: " << endl;
				cin.getline(str2, 50);
				strResult = Concatenate(str1, str2);
				cout << "Combined string:" << endl;
				ShowString(strResult);
			}
				break;

			case '5':
			{
				char string[100];
				cout << "Enter string:" << endl;
				cin.getline(string, 100);
				Uppercase(string);
				cout << "Convert string to uppercase:" << endl;
				ShowString(string);
			}
			break;

			case '6':
			{
				char string[100];
				cout  << "Enter string:" << endl;
				cin.getline(string, 100);
				Lowercase(string);
				cout << "Convert string to lowercase:" << endl;
				ShowString(string);
			}
			break;

			case '9':
			{
				Person newPerson;
				newPerson = ReadPerson();
				PrintPerson(newPerson);
			}
				break;

			case '0':
				cout << " Welcome back.\n";
				break;
			default:
				cout << " Mistake. Try again.\n";
				break;
		}
	} while (key != '0');

	int k = atoi(&key);
	return(k);

};

void ShowString(char *string)
{
	int count = 0;
	while (string[count] != '\0')
	{
		cout << string[count];
		count++;
	}
	cout << endl;
}

void CreateLength()
{
	//максимальный размер строки
	const int max = 51;
	char str[max];
	cout << "Enter your string: " << endl;
	cin.get(str, max);
	cout << "Your string: " << endl << str << endl;
}

int GetLength(char* string)
{
	int lengthString = 0;
	while (string[lengthString] != '\0')
	{
		lengthString++;
	}
	return lengthString;
}

char* Concatenate(char* string1, char* string2)
{
	int count1 = 0;
	int count2 = 0;
	while (string1[count1])
	{
		count1++;
	}
	while (string2[count2])
	{

		string1[count1] = string2[count2];
		count2++;
		string1++;
	}
	string1[count1] = '\0';
	return string1;
}

char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);

char* Uppercase(char* string)
{
	int count = 0;
	while (string[count] != '\0')
	{
		if (string[count] >= 'a' && string[count] <= 'z')
		{
				string[count] = string[count] - 32;
		}
		count++;
	}
	return string;
}
char* Lowercase(char* string)
{
	int count = 0;
	while (string[count] != '\0')
	{
		if (string[count] >= 'A' && string[count] <= 'Z')
		{
				string[count] = string[count] + 32;
		}
		count++;
	}
	return string;
}
void SplitFilename(char* source, char* path, char* name, char* extension);
char* ReplaceTabsOnSpaces(char* string);
char* ReplaceSpacesOnTabs(char* string);

Person ReadPerson()
{
	Person person;
	cout << "Enter surname: ";
	cin.getline(person.Surname, 40);
	cout << "Enter name: ";
	cin.getline(person.Name, 20);
	cout << "Enter the status: ";
	cin.getline(person.Status, 20);
	while (person.Sex[0] != 'M' && person.Sex[0] != 'F')
	{
		cout << "Enter the sex (M/F) : ";
		cin.getline(person.Sex, 2);
		if (person.Sex[0] != 'M' && person.Sex[0] != 'F')
		{
			cout << "Input Error! " << endl;
		}
	}
	while (person.Age < 0)
	{
		cout << "Enter the age: ";
		cin >> person.Age;
		if (person.Age < 0)
		{
			cout << "An invalid value was entered!" << endl;
		}
	}
	return person;
}

void PrintPerson(Person person)
{
	cout << endl << "Surname: " << person.Surname;
	cout << endl << "Name: " << person.Name;
	cout << endl << "Status: " << person.Status;
	cout << endl << "Sex: " << person.Sex;
	cout << endl << "Age: " << person.Age << endl;
}