#include <iostream>
#include <iomanip>
#include "Function3.h"
#include "StructFunction3.h"

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
	int i;
	char* string3 = new char[100];
	for (i = 0; i < GetLength(string1); i++)
	{
		string3[i] = string1[i];
	}
	for (int j = 0; j < GetLength(string2); j++)
	{
		string3[i] = string2[j];
		i++;
	}
	/*
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
	return string1;*/
	string3[i] = '\0';
	return string3;
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
//TODO: Название метода не соответствует стандарту именования
//ИСПРАВЛЕНО
char* ToUppercase(char* string)
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
//TODO: Название метода не соответствует стандарту именования
//ИСПРАВЛЕНО
char* ToLowercase(char* string)
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

//Разбиение строки source на части (путь, имя, расширение)
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

char* ReplaceTabsOnSpaces(char* string, int sizeTabs)
{
	int countChar = 0;
	char tempString[100];
	int lengthString = GetLength(string);
	//копируем строку во временную
	for (int j = 0; j < lengthString; j++)
	{
		tempString[j] = string[j];
	}
	int count = 0;
	for (int i = 0; i < lengthString; i++)
	{//TODO: Жёстко реализовано, что может быть только 4 символа. Иногда выставляют другое количество. Должно быть просто это поменять.
		//ИСПРАВЛЕНО.
		if (tempString[i] == '\t')
		{
			for (int j = 0; j < (sizeTabs - countChar); j++)
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

char* ReplaceSpacesOnTabs(char* string, int sizeSpace)
{
	int j = 0;
	int i = 0;
	char tempString[100];
	for (i = 0; string[i + j]; i++)
	{
		if (string[i + j] == ':')
		{
			while (i % sizeSpace != 0)
			{
				if (string[i] != ':')
				{
					return 0;
				}
				i++;

				while ((i + j + 1) % sizeSpace != 0)
				{
					j++;
				}
				tempString[i] = '\t';
			}
		}
		else
		{
			tempString[i] = string[i + j];
		}
	}
	tempString[i] = '\0';
	return tempString;
}

Person ReadPerson()
{
	Person *person = new Person();
	cout << "Enter surname: ";
	cin.getline(person->Surname, 40);
	cout << "Enter name: ";
	cin.getline(person->Name, 20);
	cout << "Enter the status: ";
	cin.getline(person->Status, 20);
	cout << "Sex: Enter '0' for female, '1' for male: ";
	int sex;
	cin >> sex;
	do
	{
		cout << endl << "Enter the age: ";
		cin >> person->Age;
		if (person->Age < 0)
		{
			cout << "An invalid value was entered!" << endl;
		}
	} while (person->Age < 0);
	return *person;
}
//TODO: Передача по значению - не очень оптимально.
//ИСПРАВЛЕНО.
void PrintPerson(Person *person)
{
	cout << endl << "Surname: " << person->Surname;
	cout << endl << "Name: " << person->Name;
	cout << endl << "Status: " << person->Status;
	switch (person->Sex)
	{
		case 0:
			cout << endl << "Sex: " << female;
			break;
		case 1:
			cout << endl << "Sex: " << male;
			break;
		default:
			break;
	}
	cout << endl << "Age: " << person->Age << endl;
}