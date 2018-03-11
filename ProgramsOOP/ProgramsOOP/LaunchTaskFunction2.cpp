#include "Function2.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iomanip> // для setw()

using namespace std;

int globalVariable = 7;

int Menu2()
{
	int key;
//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: и приведите свой код в соответстие со стандартом
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
			char operationKey;
			cout << "Enter mathematic operation (+, -, *, /, %): " << endl;
			operationKey = getchar(); 
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
			double value = GetPower(base, power);
			cout << "Value: " << value << endl;
		}
		break;

		case 8:
		{
			GuessNumber();
		}
		break;

		case 9:
		{
			srand(time(NULL));
			//Первый способ передачи массива в функцию
			cout << "The first method:" << endl << endl; 
			int arraySize1 = 10;
			int* array1 = new int[arraySize1];
			cout << "Unsorted array: " << endl;
			//TODO: Код дублируется с тем, что ниже, исправьте!
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

			//Второй способ передачи массива в функцию
			cout << "The second method:" << endl << endl; 
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

			//Третий способ передачи массива в функцию
			cout << "The third method:" << endl << endl; 
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
	} while (key != '0');
	return(key);
};

void PrintHelloWorld()
{
	cout << "Hello, World!" << endl;
};

double MakeCalculation(int value1, int value2, char operationKey)
{
	//TODO:Правильнее использовать switch-case, а не if-else
	if (operationKey == '+')
	{
		//TODO: можно возвращать сразу без присваивний.
		double value = value1 + value2;
		return value;
	}
	if (operationKey == '-')
	{
		double value = value1 - value2;
		return value;
	}
	if (operationKey == '*')
	{
		double value = value1 * value2;
		return value;
	}
	if (operationKey == '/')
	{
		double value = value1 / value2;
		return value;
	}
	if (operationKey == '%')
	{
		double value = value1 % value2;
		return value;
	}
};

//Корни квадратного уравнения
void GetRoots(int a, int b, int c, double* x1, double* x2)
{
	double D = b * b - 4 * a*c;
	if (D < 0)
	{
		*x1 = *x2 = NULL;
	}
	else if (D == 0)
	{
		*x1 = -b / (2 * a);
		*x2 = NULL;
	}
	else
	{
		*x1 = (-b - sqrt(D)) / (2 * a);
		*x2 = (-b + sqrt(D)) / (2 * a);
	}
}

//Корень квадратного уравнения (с использованием ссылок)
void GetRoots(int a, int b, int c, double& x1, double& x2)
{
	double D = b * b - 4 * a*c;
	if (D < 0)
	{
		x1 = x2 = NULL;
	}
	else if (D == 0)
	{
		x1 = -b / (2 * a);
		x2 = NULL;
	}
	else
	{
		x1 = (-b - sqrt(D)) / (2 * a);
		x2 = (-b + sqrt(D)) / (2 * a);
	}
}

void SummNumbers(int value1, int value2)
{
	cout << "Summ of integer is " << value1 + value2 << endl;
}
void SummNumbers(double value1, double value2)
{
	cout << "Summ of double is " << value1 + value2 << endl;
}
void SummNumbers(int value1, double value2)
{
	cout << "Summ of integer and double is " << value1 + value2 << endl;
}

void GlobalPlusTwo()
{
	globalVariable += 2;
}
void GlobalMultiplyThree()
{
	globalVariable *= 3;
}
void GlobalEqualsOne()
{
	globalVariable = 1;
}

double GetPower(int base, int power)
{
	if (power == 0)
	{
		return 1;
	}
	if (power == 1)
	{
		return base;
	}
	if (power < 0)
	{
		return 1 / GetPower(base, -power);
	}
	else
	{
		return base * GetPower(base, power - 1);
	}
}

void GuessNumber()
{
	srand(time(NULL));
	cout << "---Game: Guess the Number---" << endl;
	int guessNumber = rand() % 10;
	int enteredNumber = -1;
	int shots = 0;
	cout << "Enter number from 0 to 9: " << endl;
	cin >> enteredNumber;
	while (shots <= 2)
	{
		if (guessNumber != enteredNumber)
		{
			if (shots == 2)
			{
				cout << "You lose!" << endl;
				break;
			}
			else
			{
				shots++;
				//TODO: Для if-else всегда надо расставлять скобки!
				if (guessNumber > enteredNumber)
					cout << "Wrong!!! Try to take a number more." << endl << " Enter number from 0 to 9: " << endl;
				else
					cout << "Wrong!!! Try to take a number less." << endl << " Enter number from 0 to 9: " << endl;
				cin >> enteredNumber;
			}

		}
		else
		{
			cout << "\nCorrect! You win in " << shots + 1 << " shots!" << endl;
			break;
		}
	}
}

void SortArray(int *array, int arraySize)
{
//TODO: Не пишите комментарии к коду в завершении строки. Код должен читаться сверху вниз.
	//TODO: Без передвижения диагонального скрол-бара.
	//TODO: Правильнее будет располагать комментарии НАД комментируемой строкой.
	int j = 0;									//На каждой итерации ищется элемент с наименьшим значением,
	int tmp = 0;								//с ним нужно поменять местами последний элемент.
	for (int i = 0; i < arraySize; i++)			//Следующий элемент с наибольшим значением становится уже на предпоследнее место.
	{											//Продолжается, пока первые элементы не встанут на свои места 
		j = i;
		for (int k = i; k < arraySize; k++)
		{
			if (array[j] > array[k])
			{
				j = k;
			}
		}
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
//TODO: Избавьтесь от дублирования в этом и последующем методе
void SortArray(int array[7])
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i < 7; i++)
	{
		j = i;
		for (int k = i; k < 7; k++)
		{
			if (array[j] > array[k])
			{
				j = k;
			}
		}
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

void SortArray(double array[], int arraySize)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i < arraySize; i++)
	{
		j = i;
		for (int k = i; k < arraySize; k++)
		{
			if (array[j] > array[k])
			{
				j = k;
			}
		}
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

void MultiplyMatrices()
{
	double matrixA[10][10], matrixB[10][10], matrixC[10][10];
	int n; // параметр матрицы А
	int m; // общий параметр
	int l; //параметр матрицы B 
	srand(time(NULL));
	cout << "Attention! The number of columns of the matrix A" << endl
		<< "must coincide with the number of rows of the matrix B!" << endl;
	cout << "Enter the number of rows of matrix A: ";
	cin >> n;
	cout << "Enter the number of columns of the matrix A: ";
	cin >> m;
	cout << "Enter the number of rows of matrix B: ";
	cin >> m;
	cout << "Enter the number of columns of the matrix B: ";
	cin >> l;
	cout << endl;
	cout << "\tThe matrix A is: " << endl;
	//TODO: Ниже много дублирования. Избавьтесь от него!
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << (matrixA[i][j] = rand() % 10) << setw(6);
		}
		cout << endl;
	}
	cout << endl;
	cout << "\tThe matrix B is: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cout << setw(3) << (matrixB[i][j] = rand() % 10) << setw(6);
		}
		cout << endl;
	}
	cout << endl;
	cout << "\tThe new matrix is: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			matrixC[i][j] = 0;
			for (int k = 0; k < m; k++)
			{
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cout << setw(3) << matrixC[i][j] << setw(6);
		}
		cout << endl;
	}
	cout << endl;
}
