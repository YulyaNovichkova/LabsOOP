﻿//TODO: Для этого файла нет заголовочного файла с таким же названием. Либо создать для него заголовочный файл, либо переместить функцию в другой файл исходного кода.
#include <iostream>
#include "Stack.h"
#include "List.h"
#include "Person.h"
#include "AllLabs.h"

using namespace std;

int Menu4(Stack* stack, List* list)
{
	char key;
	int key1, key2;
	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Struct Stack." << endl
			<< "2. Struct doubly linked list." << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			case '1':
			{
				cout << "Stack:" << endl;
				key1 = StackMenu(stack);
				cout << key1 << endl;
				break;
			}
			case '2':
			{
				cout << "Doubly linked list" << endl;
				key2 = MenuList(list);
				cout << key2 << endl;
				break;
			}
			case '0':
				cout << " Welcome back." << endl;
				break;
			default:
				cout << " Mistake,try again." << endl;
				break;
		}
	} while (key != '0');

	int k = atoi(&key);
	return(k);

};

int StackMenu(Stack* stack)
{
	char key;
	int data;
	int element;
	bool check;
	int size = 0;
	cout << "Enter size your stack:" << endl;
	cin >> size;

	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Push element." << endl
			<< "2. Pop element." << endl
			<< "3. Check Empty." << endl
			<< "4. Check Full." << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			case '1':
			{
				cout << "Enter the element which you want to add:" << endl;
				cin >> data;
				check = IsFull(stack);
				if (check == false)
					Push(stack, data);
				else
				{
					Resize(stack, stack->BufferSize * 2);
					Push(stack, data);
				}
				cout << "Your stack!" << endl << endl;
				StackShow(stack);
				break;
			}
			case '2':
			{
				cout << "Your stack!" << endl << endl;
				StackShow(stack);
				check = IsEmpty(stack);
				if (check == false)
				{
					element = Pop(stack);
					cout << "Last element: " << element << endl;
				}
				else
				{
					cout << "Your stack is already empty!" << endl;
				}
				cout << "New stack!" << endl << endl;
				StackShow(stack);
				break;
			}
			case '3':
			{
				check = IsEmpty(stack);
				if (check == true)
					cout << "Your stack is empty" << endl;
				else
					cout << "Your stack isn't empty" << endl;
				break;
			}
			case '4':
			{
				check = IsFull(stack);
				if (check == true)
					cout << "Your stack is full!" << endl;
				else
					cout << "Your stack isn't full!" << endl;
				break;
			}
			
			case '0':
				cout << " Welcome back." << endl;
				break;
			default:
				cout << " Mistake. Try again." << endl;
				break;
		}
	} while (key != '0');
	int k = atoi(&key);
	return(k);
};

int MenuList(List* list)
{
	char key;
	int index;
	Person person;
	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Add new element." << endl
			<< "2. Delete element." << endl
			<< "3. Insert element." << endl
			<< "4. The index of element." << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			case '1':
			{
				person = ReadPerson();
				AddElement(list, person);
				ListShow(list);
				break;
			}
			case 2:
			{
				cout << "Enter the index of element:" << endl;
				cin >> index;
				DeleteElement(list, index);
				ListShow(list);
				break;
			}
			case '3':
			{
				cout << "Enter the index of element:\n";
				cin >> index;
				InsertElement(list, ReadRandomPerson(), index);
				ListShow(list);
				break;
			}
			case '4':
			{
				ListShow(list);
				cout << "Enter the index of element:" << endl;
				cin >> index;
				person = ReadPerson();
				InsertElement(list, person, index);
				ListShow(list);
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


void LaunchTask4()
{
	int size = 0;
	Stack* stack = InitStack(size);

	List* list = new List();
	list->Head = NULL;
	list->Tail = NULL;

	int key = Menu4(stack, list);
	cout << key << endl;
	system("pause");
	delete[] stack;
	delete[] list;
};