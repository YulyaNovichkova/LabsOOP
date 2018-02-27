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
			<< "9. Get Power;" << endl
			<< "10. Get Power;" << endl
			<< "11. Get Power;" << endl
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

			Randomly();

			break;

			/*	case 9:
			const int size = 5;

			Array();
			break;

			case 10:

			Iteration();
			break;

			case 'B':

			Break();
			break;

			case 'C':

			Float();
			break;*/

		case '0':
			cout << " Welcome back." << endl;
			break;
		default:
			cout << " Mistake. Try again." << endl;
			break;
		}
	} while (key != '0');

	int k = key;
	return(k);

};
