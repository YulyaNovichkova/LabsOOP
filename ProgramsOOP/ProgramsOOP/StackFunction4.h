#pragma once

struct Stack
{
	int* buffer;
	int bufferSize;
	int top;
};

Stack* InitStack(int size);
void Push(Stack* stack, int data);
int Pop(Stack* stack);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
void Delete(Stack* stack);
void ReSize(Stack* stack, int size);
void StackShow(Stack* stack);
int MenuStack(Stack* stack);
int FindSizeStack(Stack* stack);