#include <iostream>
#include "StackFunction4.h"
#include "DoublyLinkedList4.h"
//#include "StructFunction3.h"
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
				key1 = MenuStack(stack);
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

int MenuStack(Stack* stack)
{
	char key;
	int data;
	int element;
	bool check;
	cout << "Your stack!" << endl << endl;
	StackShow(stack);

	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Push element." << endl
			<< "2. Pop element." << endl
			<< "3. Check Empty." << endl
			<< "4. Check Full." << endl
			<< "5. Size stack." << endl
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
					ReSize(stack, stack->bufferSize * 2);
					Push(stack, data);
				}
				cout << "Your stack!" << endl << endl;
				StackShow(stack);
				break;
			}
			case '2':
			{
				cout << "Your stack, Master!" << endl << endl;
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
			case '5':
			{
				cout << "Size stack: " << FindSizeStack(stack) << endl;
				break;
			}
			case '6':
			{
				cout << "Top stack element: " << GetTopStack(stack) << endl;
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
	int element;
	int index;

	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Add new element." << endl
			<< "2. Delete element." << endl
			<< "3. Insert element." << endl
			<< "4. Sort elements." << endl
			<< "5. Line Search." << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			case '1':
			{
				cout << "Enter new element!" << endl;
				cin >> element;
				AddElement(list, element);
				ListShow(list);
				break;
			}
			case '2':
			{
				cout << "Enter the index of element:" << endl;
				cin >> index;
				DeleteElement(list, index);
				ListShow(list);
				break;
			}
			case '3':
			{
				ListShow(list);
				cout << "Enter the index of element:" << endl;
				cin >> index;
				cout << "Enter new element!" << endl;
				cin >> element;
				InsertElement(list, element, index);
				ListShow(list);
				break;
			}

			case '4':
			{
				ListShow(list);
				cout << "Now we sort your list!" << endl;
				SortDoublyLinkedList(list);
				ListShow(list);
				break;
			}

			case '5':
			{
				ListShow(list);
				cout << "Which element we must find?" << endl;
				cin >> element;
				Node* temp = Search(list, element);
				if (temp != NULL)
					cout << "This element here!" << endl;
				else
					cout << "Can not find the item." << endl;
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
	int size;
	cout << "Size: " << endl;
	cin >> size;
	Stack* stack = InitStack(size);
	////////////////////////////////////
	List* list = new List();
	list->head = NULL;
	list->tail = NULL;
	///////////////////////////////////
	int key = Menu4(stack, list);
	cout << key << endl;
	system("pause");
};