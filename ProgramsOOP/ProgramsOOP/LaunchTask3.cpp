#include <iostream>
#include "Function3.h"
#include "AllLabs.h"

using namespace std;

int Menu3()
{
	int key;
	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Determine the length of a string;" << endl
			<< "2. Combining two strings into one new one;" << endl
			<< "3. Get substring (test);" << endl
			<< "4. FindSub string (test);" << endl
			<< "5. Convert string to uppercase;" << endl
			<< "6. Convert string to lowercase;" << endl
			<< "7. Split Filename;" << endl
			<< "8. Replace characters (tab on space);" << endl
			<< "9. Replace characters (space on tab);" << endl
			<< "10. Data on the person;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore();
		system("cls");
		switch (key)
		{
		case 1:
			char str[100];
			cout << "Enter your string: " << endl;
			cin.get(str, 100);
			cout << "Your string consists of " << GetLength(str) << " characters." << endl;
			break;
		case 2:
		{
			char str1[100];
			char str2[100];
			char *strResult;
			cout << "Enter your first string: " << endl;
			cin.getline(str1, 100);
			cout << "Enter your second string: " << endl;
			cin.getline(str2, 100);
			strResult = Concatenate(str1, str2);
			cout << "Combined string:" << endl;
			ShowString(strResult);
		}//TODO: Break ����� ��������
			break;

		case 3:
		{
			char str[12] = { 'H', 'e', 'l', 'l', 'o', ',', 'W', 'o', 'r', 'l', 'd', '\0' };
			GetSubstring(str, 2, 4);
			GetSubstring(str, -3, 3);
			GetSubstring(str, 2, -4);
			GetSubstring(str, 7, 8);//TODO: ������ ������.

		}
			break;

		case 4:
		{
			char mainString[25] = "Lorem ipsum aset ametsum";
			char* string = mainString;
			char* subString = new char[100];
			char testSubstring1[10] = "ipsum a";
			FindSubstringTest(string, subString, testSubstring1);
			char testSubstring2[10] = "Arom";
			FindSubstringTest(string, subString, testSubstring2);
			char testSubstring3[10] = "sum";
			FindSubstringTest(string, subString, testSubstring3);
		}
			break;
			
		case 5:
		{
			char* string = CreateLength();
			Uppercase(string);
			cout << "Convert string to uppercase:" << endl;
			ShowString(string);
		}
			break;

		case 6:
		{
			char* string = CreateLength();
			Lowercase(string);
			cout << "Convert string to lowercase:" << endl;
			ShowString(string);
		}
			break;

		case 7:
		{
			char* source = CreateLength();
			char* path = new char[20];
			char* name = new char[20];
			char* extension = new char[10];
			SplitFilename(source, path, name, extension);
			delete[] source;
			delete[] name;
			delete[] extension;
		}
			break;

		case 8:
		{
			char string[100];
			cout << "Enter string." << endl;
			cout << "Specify a space with the symbol ':', tab '\ t':" << endl;
			cin.getline(string, 100);
			ReplaceTabsOnSpaces(string);
			cout << "New string: " << endl;
			ShowString(string);
		}
			break;

		case 9:
		{
			char string[100];
			cout << "Enter string." << endl;
			cout << "Specify a space with the symbol ':', tab '\ t':" << endl;
			cin.getline(string, 100);
			ReplaceSpacesOnTabs(string);
			cout << "New string: " << endl;
			ShowString(string);
		}
			break;

		case 10:
		{
			Person newPerson;
			newPerson = ReadPerson();
			PrintPerson(newPerson);
		}
			break;

		case 0:
			cout << " Welcome back.\n";
			break;
		default:
			cout << " Mistake. Try again.\n";
			break;
		}
	} while (key != '0');
	return(key);
};

void LaunchTask3()
{
	int key = Menu3();
	cout << key << "\n";
	system("pause");
};