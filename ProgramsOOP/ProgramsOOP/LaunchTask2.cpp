#include <iostream>
#include "LaunchTaskFunction2.h"
#include "AllLabs.h"

using namespace std;

int Menu2();

void LaunchTask2()
{
	int key = Menu2();
	cout << key << endl;
}

int Menu2()
{
	int key;

	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. ""Hello, World!"";" << endl
			<< "2. Make Calculation;" << endl
			<< "3. Get Roots;" << endl
			<< "4. GetRoots 2.0;" << endl
			<< "5. SummNumbers;" << endl
			<< "6. Global Variable;" << endl
			<< "7. Get Power;" << endl
			<< "8. Game: Guess the Number;" << endl
			<< "9. Sort an array;" << endl
			<< "10. Multiply Matrices;" << endl
			<< "0. Exit. \n";

		cin >> key;
		cin.ignore(0);
		system("cls");
		switch (key)
		{
		case 1:

			PrintHelloWorld();

			break;

		case 2:
		{
			int value1;
			int value2;
			cout << "Enter the first value:" << endl;
			cin >> value1;
			cout << "Enter the second value:" << endl;
			cin >> value2;
			char operationKey; //считываемый с клавиатуры символ
			cout << "Enter mathematic operation (+, -, *, /, %): " << endl;
			operationKey = getchar(); //getchar() - чтение символа с клавиатуры
			while ((operationKey != '+') && (operationKey != '-') && (operationKey != '*') && (operationKey != '/') && (operationKey != '%'))
			{
				cout << "INCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %): " << endl;
				operationKey = getchar();
				fflush(stdin); //функция очистки стандартного буфера ввода
							   //на случай ввода нескольких символов вместо одного
			}
			MakeCalculation(value1, value2, operationKey);
			cout << "Your value is: " << MakeCalculation(value1, value2, operationKey) << endl;
		}
		break;

		case 3:
		{
			int a;
			int b;
			int c;
			double x1 = 0;
			double x2 = 0;
			cout << "Enter 3 coefficients of your equation." << endl;
			cout << "The first coefficient A: " << endl;
			cin >> a;
			cout << "The second coefficient B: " << endl;
			cin >> b;
			cout << "The third coefficient C: " << endl;
			cin >> c;
			GetRoots(a, b, c, &x1, &x2);
			cout << "The root of your equation " << x1 << " and " << x2 << endl;
		}
		break;

		case 4:
		{
			int a;
			int b;
			int c;
			double x1 = 0;
			double x2 = 0;
			cout << "Enter 3 coefficients of your equation." << endl;
			cout << "The first coefficient A: " << endl;
			cin >> a;
			cout << "The second coefficient B: " << endl;
			cin >> b;
			cout << "The third coefficient C: " << endl;
			cin >> c;
			GetRoots(a, b, c, &x1, &x2);
			cout << "The root of your equation " << x1 << " and " << x2 << endl;
		}
		break;

		case 5:
		{
			int a;
			a = 1;
			int b;
			b = 2;
			SummNumbers(a, b);
			double x;
			x = 3.0;
			double y;
			y = 4.0;
			SummNumbers(x, y);
			SummNumbers(a, y);
			float m;
			m = 5.0;
			float n;
			n = 6.0;
			SummNumbers(m, n);
		}
		break;

		case 6:
		{
			cout << "Global Variable: " << globalVariable << endl;
			GlobalPlusTwo();
			cout << "Global Variable: " << globalVariable << endl;
			GlobalMultiplyThree();
			cout << "Global Variable: " << globalVariable << endl;
			GlobalEqualsOne();
			cout << "Global Variable: " << globalVariable << endl;
			globalVariable = 5;
			cout << "Global Variable: " << globalVariable << endl;
		}
		break;

		case 7:
		{
			int base;
			int power;

			cout << "Enter an integer:" << endl;
			cin >> base;
			cout << "Enter the power value:" << endl;
			cin >> power;
			GetPower(base, power);
			int value = GetPower(base, power);
			cout << "Value: " << value << endl;
		}
		break;

		case 8:
		{
			GameRandomly();
		}
		break;

		case 9:
		{
			srand(time(NULL));

			cout << "The first method:" << endl << endl; // первый способ передачи массива в функцию
			int arraySize1 = 10;
			int* array1 = new int[arraySize1];
			cout << "Unsorted array: " << endl;
			for (int i = 0; i < arraySize1; i++)
			{
				array1[i] = rand() % 15;
				cout << array1[i] << setw(5);
			}
			SortArray(array1, arraySize1);
			cout << endl;
			cout << "Sorted array: " << endl;
			for (int i = 0; i < arraySize1; i++)
			{
				cout << array1[i] << setw(5);
			}
			cout << endl << endl;


			cout << "The second method:" << endl << endl; // второй способ передачи массива в функцию
			const int arraySize2 = 7;
			int array2[arraySize2];
			cout << "Unsorted array: " << endl;
			for (int i = 0; i < arraySize2; i++)
			{
				array2[i] = rand() % 15;
				cout << array2[i] << setw(5);
			}
			SortArray(array2);
			cout << endl;
			cout << "Sorted array: " << endl;
			for (int i = 0; i < arraySize2; i++)
			{
				cout << array2[i] << setw(5);
			}
			cout << endl << endl;

			
			cout << "The third method:" << endl << endl; // третий способ передачи массива в функцию
			const int arraySize3 = 8;
			int array3[arraySize3];
			cout << "Unsorted array: " << endl;
			for (int i = 0; i < arraySize3; i++)
			{
				array3[i] = rand() % 15;
				cout << array3[i] << setw(5);
			}
			SortArray(array3, arraySize3);
			cout << endl;
			cout << "Sorted array: " << endl;
			for (int i = 0; i < arraySize3; i++)
			{
				cout << array3[i] << setw(5);
			}
			cout << endl << endl;
		}
		break;

		case 10:
		{	
			MultiplyMatrices();
		}
		break;

		case '0':
			cout << " Welcome back." << endl;
			break;
		default:
			cout << " Mistake. Try again." << endl;
			break;
		}
	}while (key != '0');
	return(key);
};
