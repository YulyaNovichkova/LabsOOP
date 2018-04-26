#include <iostream>
#include <iomanip>
#include "String.h"
#include "PersonStract.h"

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

char* CreateString()
{
	int size = 100;
	char* str = new char[size];
	cout << "Enter your string: " << endl;
	cin.get(str, size);
	cout << "Your string: " << endl << str << endl;
	return str;
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
	int i;
	int lengthSrting1 = GetLength(string1);
	int lengthString2 = GetLength(string2);
	int length = lengthSrting1 + lengthString2;
	//Ниже прибавляется 1 для '\0'
	char* string3 = new char[length + 1];
	for (i = 0; i < lengthSrting1; i++)
	{
		string3[i] = string1[i];
	}
	for (int j = 0; j < lengthString2; j++)
	{
		string3[i] = string2[j];
		i++;
	}
	string3[i] = '\0';
	return string3;
}

char* GetSubstring(char* string, int startIndex, int charCount)
{
	//Индекс конца подстроки не был больше длины самой строки ИЛИ был больше нуля
	//ИЛИ индекс начало подстроки был больше нуля
	if (((GetLength(string) - startIndex) < charCount) || (startIndex < 0) || (charCount < 0))
	{
		ErrorOutput();
		return NULL;
	}
	char* substring = new char[charCount + 1];
	for (int i = 0; i < charCount; i++)
	{
		substring[i] = string[startIndex];
		startIndex++;
	}
	substring[charCount] = '\0';
	return substring;
	//delete[] substring;
}

int FindSubstring(char* string, char* substring)
{
	if (GetLength(string) < GetLength(substring))
	{
		return -1;
	}
	for (int i = 0; i < GetLength(string); i++)
	{
		if (string[i] == substring[0])
		{
			bool subString = true;
			int str = ++i;
			for (int subStr = 1; subStr < GetLength(substring); subStr++)
			{
				if (str > GetLength(string))
				{
					return -1;
				}
				if (string[str] != substring[subStr])
				{
					subString = false;
				}
				str++;
			}
			if (subString)
			{
				return i - 1;
			}
		}
	}
	return -1;
}

char* ToUppercase(char* string)
{
	char* result = new char[255];
	for (int i = 0; i < 255; i++)
	{
		result[i] = string[i];
	}
	int count = 0;
	while (result[count] != '\0')
	{
		if (result[count] >= 'a' && result[count] <= 'z')
		{
			result[count] = result[count] - ('A' - 'a');
		}
		count++;
	}
	return result;
}

char* ToLowercase(char* string)
{
	char* result = new char[255];
	for (int i = 0; i < 255; i++)
	{
		result[i] = string[i];
	}
	int count = 0;
	while (result[count] != '\0')
	{
		if (result[count] >= 'A' && result[count] <= 'Z')
		{
			result[count] = result[count] + ('A' - 'a');
		}
		count++;
	}
	return result;
}

void FindSubstringTest(char* string, char* substring, char testSubstring[20])
{
	int index;
	substring = testSubstring;
	index = FindSubstring(string, substring);
	cout << "Start index: " << index << endl;
}

void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int startName = 0;
	int startExtension = -1;

	for (int i = 0; source[i]; i++)
	{
		if (source[i] == '\\')
		{
			startName = i + 1;
		}
		else if (source[i] == '.')
		{
			startExtension = i;
		}
	}
	if (startExtension > startName)
	{
		if (!startName)
		{
			*path = '\0';
		}
		else
		{
			CopyString(path, GetSubstring(source, 0, startName));
		}
		CopyString(name, GetSubstring(source, startName, startExtension - startName));
		CopyString(extension, GetSubstring(source, startExtension, GetLength(source) - startExtension));
	}
	else if (startExtension == -1)
	{
		if (!startName)
		{
			*path = '\0';
		}
		else
		{
			CopyString(path, GetSubstring(source, 0, startName));
		}
		CopyString(name, GetSubstring(source, startName, GetLength(source) - startName));

		*extension = '\0';
	}
	else
	{
		*path = '\0';
		*name = '\0';
		*extension = '\0';
	}
}

char* ReplaceTabsOnSpaces(char* string, int sizeTabs)
{
	int i = 0;
	int j = 0;
	char* resultString = new char[100];

	for (i = 0; string[i]; i++)
	{
		if (string[i] == '\t')
		{
			for (j = 0; (i + j + 1) % 8 != 0; j++)
			{
				resultString[i + j] = ':';
			}
			resultString[i + j] = ':';
		}
		else
		{
			resultString[i + j] = string[i];
		}
	}
	resultString[i + j] = '\0';
	return resultString;
	delete[] resultString;
}

char* ReplaceSpacesOnTabs(char* string, int sizeSpaces)
{
	int j = 0;
	int i = 0;

	char* tempString = new char[100];
	for (i = 0; string[i + j]; i++)
	{
		if (string[i + j] == ':' && NeedTab(string, i + j + 1, sizeSpaces))
		{
				while ((i + j + 1) % sizeSpaces != 0)
				{
					j++;
				}
				tempString[i] = '\t';
		}
		else
		{
			tempString[i] = string[i + j];
		}
	}
	tempString[i] = '\0';
	return tempString;
}
bool NeedTab(char* string, int i, int sizeSpaces)
{
	while (i % sizeSpaces != 0)
	{
		if (string[i] != ':')
		{
			return false;
		}
		i++;
	}
	return true;
}

void CopyString(char* string1, char* string2)
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}

Person ReadPerson()
{
	Person person;
	cout << "Enter surname: ";
	cin.getline(person.Surname, 40);
	cout << "Enter name: ";
	cin.getline(person.Name, 20);
	cout << "Sex: Enter '0' for female, '1' for male: ";
	int sex;
	cin >> sex;
	switch (sex)
	{
		case 0:
		{
			person.Sex = Female;
			break;
		}
		case 1:
		{
			person.Sex = Male;
			break;
		}
	}
	do
	{
		cout << "Enter the age: ";
		cin >> person.Age;
		if (person.Age < 0)
		{
			cout << "An invalid value was entered!" << endl;
		}
	} while (person.Age < 0);
	return person;
}

void ShowPerson(Person person)
{
	cout << "Surname: " << person.Surname;
	cout << endl << "Name: " << person.Name;
	switch (person.Sex)
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
	cout << endl << "Age: " << person.Age << endl;
}
void ErrorOutput()
{
	cout << "Value entered incorrectly." << endl;
}