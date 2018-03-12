#pragma once

int Menu2();
void PrintHelloWorld();double MakeCalculation(int value1, int value2, char operationKey);//Корни квадратного уравнения
void GetRoots(int a, int b, int c, double* x1, double* x2);
//Корень квадратного уравнения (с использованием ссылок)
void GetRoots(int a, int b, int c, double& x1, double& x2);

void SummNumbers(int value1, int value2);
void SummNumbers(double value1, double value2);
void SummNumbers(int value1, double value2);
void GlobalPlusTwo();
void GlobalMultiplyThree();
void GlobalEqualsOne();double GetPower(int base, int power);
void GuessNumber();
//Сортировки выбором
void SortArray(int *array, int arraySize); 
void SortArray(int array[7]); 
void SortArray(double array[], int arraySize);

void MultiplyMatrices();
int** CreateMatrix(int **matrix, int row, int col);
void ShowMatrix(int **matrix, int row, int col);