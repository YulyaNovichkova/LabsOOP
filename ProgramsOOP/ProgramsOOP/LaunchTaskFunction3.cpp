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

char* CreateLength()
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

char* GetSubstring(char* string, int startIndex, int charCount)
{
	if (((GetLength(string) - startIndex) < charCount) || (startIndex < 0) || (charCount < 0))
	{
		cout << "Value entered incorrectly." << endl;
		return NULL;
	}
	cout << "Your string: " << endl;
	for (int i = 0; i < charCount; i++)
	{
		cout << string[startIndex];
		startIndex++;
	}
	cout << endl;
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

void FindSubstringTest(char* string, char* substring, char testSubstring[20])
{
	int index;
	substring = testSubstring;
	index = FindSubstring(string, substring);
	cout << "Start index: " << index << endl;
}

void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int size = GetLength(source);

	size = GetSourcePart(source, extension, '.', "Extension: ", size);
	size = GetSourcePart(source, name, '\\', "Name: ", size);
	source[size + 1] = '\0';
	path = source;
	cout << "Path: " << path << endl;
}

//–азбиение строки source на части (путь, им€, расширение)
int GetSourcePart(char* source, char* partString, char symbol, const char partName[30], int size)
{
	int i = 0;
	while (source[size] != symbol)
	{
		partString[i] = source[size - 1];
		i++;
		size--;
	}
	if (symbol == '\\')
	{
		partString[i - 1] = '\0';
	}
	else
	{
		partString[i] = '\0';
	}
	partString = RevertString(partString, GetLength(partString) - 1);
	cout << partName << partString << endl;
	return size;
}


char* RevertString(char* string, int size)
{
	char* newString = new char[size];
	int i = 0;
	while (size != -1)
	{
		newString[i] = string[size];
		i++;
		size--;
	}
	newString[i] = '\0';
	return newString;
}

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