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
			<< "3. ;" << endl
			<< "4. ;" << endl
			<< "5. Convert string to uppercase;" << endl
			<< "6. Convert string to lowercase;" << endl
			<< "7. Replace characters (tab on space);" << endl
			<< "8. Replace characters (space on tab);" << endl
			<< "9. Data on the person;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore();
		system("cls");
		switch (key)
		{
		case 1:
			char str[51];
			cout << "Enter your string: " << endl;
			cin.get(str, 51);
			cout << "Your string consists of " << GetLength(str) << " characters." << endl;
			break;
		case 2:
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

		case 5:
		{
			char string[100];
			cout << "Enter string:" << endl;
			cin.getline(string, 100);
			Uppercase(string);
			cout << "Convert string to uppercase:" << endl;
			ShowString(string);
		}
			break;

		case 6:
		{
			char string[100];
			cout << "Enter string:" << endl;
			cin.getline(string, 100);
			Lowercase(string);
			cout << "Convert string to lowercase:" << endl;
			ShowString(string);
		}
			break;

		case 7:
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

		case 8:
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

		case 9:
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

	//int k = atoi(&key);
	return(key);

};

void LaunchTask3()
{
	int key = Menu3();
	cout << key << "\n";
	system("pause");
};