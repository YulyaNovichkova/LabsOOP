#pragma once
//TODO: Файл переименовать в Stack - слова типа Function в названии файлов лишние и не информативные
//TODO: Перед структурами и функциями обязательны комментарии!
struct Stack
{
	//TODO: Открытые поля структур должны именоваться с заглавной буквы
	int* buffer;
	int bufferSize;
	int top;
};

//TODO: Добавить комментарии перед всеми функциями. Комментарии продублировать в cpp-файлах
Stack* InitStack(int size);
void Push(Stack* stack, int data);
int Pop(Stack* stack);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
//TODO: Remove - в случае структур принято использовать слово Remove, а не Delete
void Delete(Stack* stack);
//TODO: ресайз это одно слово, S должна быть маленькой
void ReSize(Stack* stack, int size);
void StackShow(Stack* stack);
//TODO: StackMenu
int MenuStack(Stack* stack);
//TODO: Переименовать в CalculateNewStackSize
int FindSizeStack(Stack* stack);
//TODO: GetStackTop
int GetTopStack(Stack* stack);
//TODO: Все переименования сделать в cpp-файлах тоже

