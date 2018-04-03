#pragma once

//Структура данных "Стек"
struct Stack
{
	int* Buffer;
	int BufferSize;
	int Top;
};

//Инициализация стека
Stack* InitStack(int size);
//Помещение элемета в стек
void Push(Stack* stack, int data);
//Извлечение из стека
int Pop(Stack* stack);
//Проверка на пустоту
bool IsEmpty(Stack* stack);
//Проверка на полноту
bool IsFull(Stack* stack);
//Удаление стека
void Remove(Stack* stack);
//Изменение размера буфера
void Resize(Stack* stack, int size);
//Вывод стека
void StackShow(Stack* stack);