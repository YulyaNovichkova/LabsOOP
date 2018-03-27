#include <iostream>
#include <iomanip>
#include "String.h"
#include "Person.h"
//TODO: см. замечания в заголовочном файле
//ИСПРАВЛЕНО.
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
	//TODO: А если сумма длин строк string1 и string2 будет больше 100? Переделать для строк любой длины
		//ИСПРАВЛЕНО.
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
	//TODO: Такие длинные условия тяжело прочесть, поэтому их следует комментировать
	//ИСПРАВЛЕНО.

	//Индекс конца подстроки не был больше длины самой строки ИЛИ был больше нуля
	//ИЛИ индекс начало подстроки был больше нуля
	if (((GetLength(string) - startIndex) < charCount) || (startIndex < 0) || (charCount < 0))
	{
		ErrorOutput();
		return NULL;
	}
	for (int i = 0; i < charCount; i++)
	{
		//TODO: Убрать вывод на экран
		cout << string[startIndex];
		startIndex++;
	}
	//TODO: Функция должна вернуть найденную подстроку, а сейчас они ничего не возвращает
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

//TODO: функция должна вернуть НОВУЮ строку, а не изменить старую
//ИСПРАВЛЕНО.
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
			//TODO: Избавиться от магического числа 32
			result[count] = result[count] - 32;
		}
		count++;
	}
	return result;
}


//TODO: функция должна вернуть НОВУЮ строку, а не изменить старую
//ИСПРАВЛЕНО.
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
			//TODO: Избавиться от магического числа 32
			result[count] = result[count] + 32;
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
	int size = GetLength(source);
	//TODO: Вместо GetSourcePart нужно использовать GetSubstring, FindSubstring и другие ранее написанные функции
	size = GetSourcePart(source, extension, '.', "Extension: ", size);
	size = GetSourcePart(source, name, '\\', "Name: ", size);
	source[size + 1] = '\0';
	path = source;
	//TODO: Функция ничего не должна выводить. Она должна разбить полный путь на части, части поместить во входные параметры, а вывод на экран должен быть в main/LaunchTask3
	cout << "Path: " << path << endl;
}

//TODO: Эта функция не нужна
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
	//TODO: Функция ничего не должна выводить. Она должна разбить полный путь на части, части поместить во входные параметры, а вывод на экран должен быть в main/LaunchTask3
	cout << partName << partString << endl;
	return size;
}

//TODO: Так и не понял, зачем вы с Козыревой вертите строки туда-обратно...
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

//TODO: сейчас функция работает неправильно. Тестировать и исправлять
char* ReplaceTabsOnSpaces(char* string, int sizeTabs)
{
	//TODO: Функция перезаписывает исходную строку, а это неправильно - потеря данных. Сделать так, чтобы новая строка помещалась только в tempString
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
	{
		if (countChar == sizeTabs)
		{
			countChar = 0;
		}
		if (tempString[i] == '\t')
		{
			for (int j = 0; j < (sizeTabs - countChar); j++)
			{
				string[count] = ':';
				count++;
			}
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

char* ReplaceSpacesOnTabs(char* string, int sizeSpaces)
{
	int j = 0;
	int i = 0;
	//TODO: этот массив надо было создавать динамически. Теперь функция работает. Почему с динамическим массивом работает, а с обычным нет - спрошу на защите следующей лабораторной
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
	//TODO: Вывод персоны лучше делать в одну строку - так будет удобнее потом тестировать списки персон
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