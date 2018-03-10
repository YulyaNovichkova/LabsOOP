#pragma once

int Menu2();
void PrintHelloWorld();double MakeCalculation(int value1, int value2, char operationKey);//Корни квадратного уравнения
void GetRoots(int a, int b, int c, double* x1, double* x2);
//Корень квадратного уравнения (с использованием ссылок)
void GetRoots(int a, int b, int c, double& x1, double& x2);
void SummNumbers(int value1, int value2);
void SummNumbers(double value1, double value2);
void SummNumbers(int value1, double value2);
void GlobalPlusTwo();
void GlobalMultiplyThree();
void GlobalEqualsOne();double GetPower(int base, int power);
void GameRandomly();
void SortArray(int *array, int arraySize); // сортировка выбором
void SortArray(int array[7]); // сортировка выбором
void SortArray(double array[], int arraySize); // сортировка выборо
void MultiplyMatrices();
