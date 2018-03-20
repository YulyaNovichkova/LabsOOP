#include <iostream>
#include "StackFunction4.h"
#include "StructFunction3.h"
#include "AllLabs.h"

using namespace std;

int Menu4(Stack* stack)
{
	char key;
	int key1, key2;
	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Struct Stack." << endl
			<< "2. Struct Queue (buf)." << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
			case '1':
			{
				cout << "Stack:\n";
				key1 = MenuStack(stack);
				cout << key1 << "\n";
				break;
			}
			/*case '2':
			{
				cout << "Queue (buf):\n";
				key2 = MenuQueue1(bufqueue);
				cout << key2 << "\n";
				break;
			}*/
			case '0':
				cout << " Welcome back, Master ~<3.\n";
				break;
			default:
				cout << " Mistake, Master! Try again ~<3.\n";
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

void LaunchTask4()
{
	int size;
	cout << "Size: " << endl;
	cin >> size;
	Stack* stack = InitStack(size);
	int key = Menu4(stack);
	cout << key << endl;
	system("pause");
};