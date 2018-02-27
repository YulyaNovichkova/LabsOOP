#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

int globalVariable = 7;

void PrintHelloWorld()
{
	cout << "Hello, World!" << endl;
};double MakeCalculation(int value1, int value2, char operationKey){	if (operationKey == '+')	{		double value = value1 + value2;		return value;	}	if (operationKey == '-')	{		double value = value1 - value2;		return value;	}	if (operationKey == '*')	{		double value = value1 * value2;		return value;	}	if (operationKey == '/')	{		double value = value1 / value2;		return value;	}	if (operationKey == '%')	{		double value = value1 % value2;		return value;	}};// орни квадратного уравнени€
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

// орень квадратного уравнени€ (с использованием ссылок)
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
}int GetPower(int base, int power){
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

void Randomly()
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
/*
void Array()
{
int integerArray[size];
for (int i = 0; i < size; i++)
{
integerArray[i] = rand();
}

double realArray[size];
for (int i = 0; i < size; i++)
{
realArray[i] = rand();
}
}

void MultiplyMatrices()*/
