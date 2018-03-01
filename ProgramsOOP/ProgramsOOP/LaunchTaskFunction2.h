#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iomanip> // for setw()

using namespace std;

int globalVariable = 7;

void PrintHelloWorld()
{
	cout << "Hello, World!" << endl;
};double MakeCalculation(int value1, int value2, char operationKey){	if (operationKey == '+')	{		double value = value1 + value2;		return value;	}	if (operationKey == '-')	{		double value = value1 - value2;		return value;	}	if (operationKey == '*')	{		double value = value1 * value2;		return value;	}	if (operationKey == '/')	{		double value = value1 / value2;		return value;	}	if (operationKey == '%')	{		double value = value1 % value2;		return value;	}};//Корни квадратного уравнения
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
}int GetPower(int base, int power){
	if (power == 0)
	{
		return 1;
	}
	if (power == 1)
	{
		return base;
	}
	else
	{
		return base * GetPower(base, power - 1);
	}}

void GameRandomly()
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
				if (guessNumber > enteredNumber)
					cout << "Wrong!!! Try to take a number more." << endl << " Enter number from 0 to 9: " << endl;
				else
					cout << "Wrong!!! Try to take a number less." << endl << " Enter number from 0 to 9: " << endl;
				cin >> enteredNumber;
			}
			
		}
		else
		{
			cout << "\nCorrect! You win in " << shots+1 << " shots!" << endl;
			break;
		}
	}	
}

void SortArray(int *array, int arraySize) // сортировка выбором
{
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

void SortArray(int array[7]) // сортировка выбором
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

void SortArray(double array[], int arraySize) // сортировка выбором
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
	int m;
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
			cout << setw(3) <<(matrixB[i][j] = rand() % 10) << setw(6);
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
			cout << setw(4) << matrixC[i][j] << setw(8);
		}
		cout << endl;
	}
	cout << endl;
}
