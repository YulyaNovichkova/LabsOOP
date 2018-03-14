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
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(0);
		system("cls");
		switch (key)
		{
			case 1:
			{
				PrintHelloWorld();
			}//TODO: Почему break везде за скобками? Это не правильно.
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
				cin >> operationKey;
				while ((operationKey != '+') && (operationKey != '-') && (operationKey != '*') && (operationKey != '/') && (operationKey != '%'))
				{
					cout << "INCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %): " << endl;
					cin >> operationKey;
					fflush(stdin);
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
				
				CreateArray(array1, arraySize1);
				ShowArray(array1, arraySize1);
				SortArray(array1, arraySize1);
				cout << "Sorted array: " << endl;
				ShowArray(array1, arraySize1);

				//Второй способ передачи массива в функцию
				cout << "The second method:" << endl << endl; 
				const int arraySize2 = 7;
				int array2[arraySize2];
				cout << "Unsorted array: " << endl;
				CreateArray(array2, 7);
				ShowArray(array2, 7);
				SortArray(array2);
				cout << "Sorted array: " << endl;
				ShowArray(array2, arraySize2);

				//Третий способ передачи массива в функцию
				cout << "The third method:" << endl << endl; 
				const int arraySize3 = 8;
				int array3[arraySize3];
				cout << "Unsorted array: " << endl;
				CreateArray(array3, arraySize3);
				ShowArray(array3, arraySize3);
				SortArray(array3, arraySize3);
				cout << "Sorted array: " << endl;
				ShowArray(array3, arraySize3);
			}
				break;

			case 10:
			{
				MultiplyMatrices();
			}
				break;

			case 0:
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
	switch (operationKey)
	{//TODO: Послн return нет смысла ставить break-и
		case '+':
			return (value1 + value2);
			break;

		case '-':
			return (value1 - value2);
			break;

		case '*':
			return (value1 * value2);
			break;

		case '/':
			return (value1 / value2);
			break;

		case '%':
			return (value1 % value2);
			break;
		default:
			return -1;
			break;
	}
}

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
				//TODO: Много кода дублируется - можно сократить.
				if (guessNumber > enteredNumber)
				{
					cout << "Wrong!!! Try to take a number more." << endl << " Enter number from 0 to 9: " << endl;
				}
				else
				{
					cout << "Wrong!!! Try to take a number less." << endl << " Enter number from 0 to 9: " << endl;
				}
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
//TODO: Избавьтесь от дублирования в этом и последующем методе
//ИСПРАВЛЕНО.
//Не увидел, что исправили.
void SortArray(int array[7])
{
	int key = 0;
	int i = 0;
	for (int j = 1; j < 7; j++)
	{
		key = array[j];
		i = j - 1;
		while (i >= 0 && array[i] > key) 
		{
			array[i + 1] = array[i];
			i = i - 1;
			array[i + 1] = key;
		}
	}
}

void SortArray(double array[], int arraySize)
{
	int tmp = 0;
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = (arraySize - 1); j >= (i + 1); j--) 
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}
int* CreateArray(int *array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 15;
	}
	return array;
}
void ShowArray(int *array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << setw(5);
	}
	cout << endl << endl;
}

void MultiplyMatrices()
{
	//TODO: плохое именование для переменных. Не понятно, за что они отвечают.
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
	//ИСПРАВЛЕНО.
	//Не всё исправили.
	int **matrixA = new int*[n];
	CreateMatrix(matrixA, n, m);
	ShowMatrix(matrixA, n, m);
	cout << endl;

	cout << "\tThe matrix B is: " << endl;
	int **matrixB = new int*[m];
	CreateMatrix(matrixB, m, l);
	ShowMatrix(matrixB, m, l);
	cout << endl;

	cout << "\tThe new matrix is: " << endl;

	int **matrixC = new int*[n];
	CreateMatrix(matrixC, n, m);
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
	ShowMatrix(matrixC, n, l);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		delete[] matrixA[i];
	}
	delete[] matrixA;
	for (int i = 0; i < m; i++)
	{
		delete[] matrixB[i];
	}
	delete[] matrixB;
	for (int i = 0; i < n; i++)
	{
		delete[] matrixC[i];
	}
	delete[] matrixC;
}

int** CreateMatrix(int **matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % 10;
		}
		cout << endl;
	}
	return matrix;
}
void ShowMatrix(int **matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(3) << matrix[i][j] << setw(6);
		}
		cout << endl;
	}
}