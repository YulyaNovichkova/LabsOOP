#include <iostream>
#include "Function1.h"

using namespace std;

void Hi()
{
	cout << "Hello, world!" << endl;
}

void Summ() //сумма целочисленных чисел
{
	int a = 5;
	int b = 3;
	cout << "Variable a equals " << a << endl;
	cout << "Variable a equals " << b << endl;
	cout << "Summ of a and b equals " << a + b << endl;
}

void Division() // деление целочисленных и вещественных чисел
{
	int a = 5;
	int b = 3;
	float x = 5.0;
	float y = 3.0;
	cout << "Float variables division: " << a / b << endl;
	cout << "Integer variables division: " << x / y << endl;
}

void Summ2() // чтение вещественных чисел с клавиатуры 
{			 // и вывод их суммы
	int a;
	int b;
	cout << " Enter first and second integer value" << endl;
	cin >> a >> b;
	cout << "Summ of a and b equals: " << a + b << endl;
}

void Pointer() // работа с указателями
{
	int value;
	int* pointer;
	int anotherValue;
	value = 5;

	pointer = &value; // взятие адреса
	anotherValue = *pointer; // операция разыменования	

	cout << "Value, stored in pointer: " << anotherValue << endl;
	cout << "Address in pointer: " << pointer << endl;
	cout << "Value in pointer: " << *pointer << endl;
}

void EvenOdd() // проверка на четность/нечетность
{
	int a;
	cout << "Enter value for check on even/odd: " << endl;
	cin >> a;
	if (a % 2 == 0)
	{
		cout << "Value is even!" << endl;
	}
	else
	{
		cout << "Value is odd!" << endl;
	}
}

void Multiples() // проверка чисел 5 и 2 на кратность
{
	int a;
	cout << "Enter value: " << endl;
	cin >> a;
	if (a % 5 == 0)
	{
		cout << "Value multiples 5!" << endl;
	}
	if (a % 2 == 0)
	{
		cout << "Value multiples 2!" << endl;
	}
	if ((a % 5 == 0) & (a % 5 == 0))
	{
		cout << "Value multiples 5 and 2!" << endl;
	}
	else
	{
		cout << "Value doesn`t multiply 5 or 2!" << endl;
	}
}

void PredCondition() //цикл с пред-условием
{
	int a = 0;
	while (a < 5)
	{
		cout << "Value is now: " << a << endl;
		a++;
	}
}

void PostCondition() // цикл с пост-условием
{
	int a = 0;
	do
	{
		cout << "Value is now: " << a << endl;
		a++;
	} while (a < 5);
}

void Iteration() // работа итерационного цикла
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		cout << "Iteration: " << i << endl;
	}
	for (int i = 0; i < a; i++)
	{
		a--;
		cout << "Iteration value is  " << i << "  " << a << endl;
	}
}

void Break() // досрочное завершение программы
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			cout << "I is more or equal A! Break of cycle" << endl;
			break;
		}
	}
	cout << "A is " << a << endl;
}

void Float() // явное и неявное преобразование типов данных
{
	int a = 5;
	int b = 3;
	float z;

	z = a;
	cout << "Value of z is " << z << endl;

	//a = z;

	a = (int)z;
	cout << "Value of a is " << a << endl;

	z = a / b;
	cout << "Value of z is " << z << endl;

	z = ((float)a) / b;
	cout << "Value of z is " << z << endl;
};

