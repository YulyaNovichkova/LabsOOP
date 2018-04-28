//#include <iostream>
//#include "Stack.h"
//
//using namespace std;
//
////Инициализация стека
//Stack* InitStack(int size)
//{
//	Stack* stack = new Stack();
//	stack->BufferSize = size;
//	stack->Buffer = new int[stack->BufferSize];
//	stack->Top = 0;
//	return stack;
//};
//
////Помещение элемета в стек
//void Push(Stack* stack, int data)
//{
//	stack->Buffer[stack->Top] = data;
//	stack->Top++;
//}
//
////Извлечение из стека
//int Pop(Stack* stack)
//{
//	int index = stack->Top - 1;
//	stack->Top--;
//	return stack->Buffer[index];
//}
//
////Проверка на пустоту
//bool IsEmpty(Stack* stack)
//{
//	return (stack->Top <= 0);
//}
//
////Проверка на полноту
//bool IsFull(Stack* stack)
//{
//	return (stack->Top == stack->BufferSize);
//}
//
////Удаление стека
//void Remove(Stack* stack)
//{
//	delete[] stack->Buffer;
//	delete stack;
//}
//
////Изменение размера буфера
//void Resize(Stack* stack, int newSize)
//{
//	int* newBuffer = new int[newSize];;
//	for (int i = 0; i < stack->BufferSize; i++)
//	{
//		newBuffer[i] = stack->Buffer[i];
//	}
//	delete[] stack->Buffer;
//	stack->BufferSize = newSize;
//	stack->Buffer = newBuffer;
//}
//
////Вывод стека
//void StackShow(Stack* stack)
//{
//	for (int i = stack->Top - 1; i >= 0; i--)
//	{
//		cout << (stack->Buffer[i]) << endl;
//	}
//	cout << endl << endl;
//}
