#include <iostream>
#include <iomanip>
#include "Function3.h"

using namespace std;


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
	char string[100];
	cout << "Enter string:" << endl;
	cin.getline(string, 100);
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

char* ReplaceTabsOnSpaces(char* string)
{
	int lengthString;
	int countChar = 0;
	char tempString[100];
	lengthString = GetLength(string);
	//копируем строку во временную
	for (int j = 0; j < lengthString; j++)
	{
		tempString[j] = string[j];
	}
	int count = 0;
	for (int i = 0; i < lengthString; i++)
	{
		if (tempString[i] == '\\' && tempString[i + 1] == 't')
		{
			for (int j = 0; j < (4 - countChar); j++)
			{
				string[count] = ':';
				count++;
			}
			i++;
		}
		else
		{
			string[count] = tempString[i];
			count++;
			countChar++;
		}

	}
	string[count] = '\0';
	return string;
}
char* ReplaceSpacesOnTabs(char* string)
{
	int lengthString;
	int countChar = 0;
	char tempString[100];
	lengthString = GetLength(string);
	for (int i = 0; i < lengthString; i++)
	{
		tempString[i] = string[i];
	}
	int count = 0;
	for (int j = 0; j < lengthString; j++)
	{
		if (countChar == 4)
		{
			countChar = 0;
		}
		if ((tempString[j] == ':' &&  tempString[j + 1] == ':' &&  tempString[j + 2] == ':' && tempString[j + 3] == ':') && (countChar == 0))
		{
			string[count] = '\\';
			string[count + 1] = 't';
			j += 3;
			count += 2;
		}
		else if ((tempString[j] == ':' &&  tempString[j + 1] == ':' &&  tempString[j + 2] == ':') && (countChar == 1))
		{
			string[count] = '\\';
			string[count + 1] = 't';
			j += 2;
			count += 2;
			countChar = 0;
		}
		else if ((tempString[j] == ':' &&  tempString[j + 1] == ':') && (countChar == 2))
		{
			string[count] = '\\';
			string[count + 1] = 't';
			j += 1;
			count += 2;
			countChar = 0;
		}
		else if ((tempString[j] == ':') && (countChar == 3))
		{
			string[count] = '\\';
			string[count + 1] = 't';
			count += 2;
			countChar = 0;
		}
		else
		{
			if (tempString[j] == ' ')
			{
				string[count] = ':';
			}
			else
			{
				string[count] = tempString[j];
			}
			count++;
			countChar++;
		}
	}
	string[count] = '\0';
	return string;
}

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