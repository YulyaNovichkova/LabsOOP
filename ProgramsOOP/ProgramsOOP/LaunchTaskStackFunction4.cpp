#include <iostream>
#include "StackFunction4.h"

using namespace std;

Stack* InitStack(int size)
{
	Stack* stack = new Stack();
	stack->bufferSize = size;
	stack->buffer = new int[stack->bufferSize];
	stack->top = 0;
	return stack;
};

void Push(Stack* stack, int data)
{
	stack->buffer[stack->top] = data;
	stack->top++;
}

int Pop(Stack* stack)
{
	int index = stack->top - 1;
	stack->top--;
	return stack->buffer[index];
}

bool IsEmpty(Stack* stack)
{
	return (stack->top <= 0);
}

bool IsFull(Stack* stack)
{
	return (stack->top == stack->bufferSize);
}

void Delete(Stack* stack)
{
	delete[] stack->buffer;
	delete stack;
}

void ReSize(Stack* stack, int newSize)
{
	int* newBuffer = new int[newSize];;
	for (int i = 0; i < stack->bufferSize; i++)
	{
		newBuffer[i] = stack->buffer[i];
	}
	delete[] stack->buffer;
	stack->bufferSize = newSize;
	stack->buffer = newBuffer;
}

int FindSizeStack(Stack* stack)
{
	int lengthStack = 0;
	for (int i = 0; i < stack->buffer[i]; i++)
	{
		lengthStack++;
	}
	return lengthStack;
}

void StackShow(Stack* stack)
{
	for (int i = stack->top - 1; i >= 0; i--)
	{
		std::cout << (stack->buffer[i]) << endl;
	}
	cout << endl << endl;
}
