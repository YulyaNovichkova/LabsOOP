#pragma once
//TODO: Файл переименовать в Stack - слова типа Function в названии файлов лишние и не информативные
//ИСПРАВЛЕНО.
//TODO: Перед структурами и функциями обязательны комментарии!
//ИСПРАВЛЕНО.
//Структура данных "Стек"
struct Stack
{
	//TODO: Открытые поля структур должны именоваться с заглавной буквы
	//ИСПРАВЛЕНО.
	int* Buffer;
	int BufferSize;
	int Top;
};

//TODO: Добавить комментарии перед всеми функциями. Комментарии продублировать в cpp-файлах
//ИСПРАВЛЕНО.
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
//TODO: Remove - в случае структур принято использовать слово Remove, а не Delete
//ИСПРАВЛЕНО.
//Удаление стека
void Remove(Stack* stack);
//Изменение размера буфера
void Resize(Stack* stack, int size);
//Вывод стека
void StackShow(Stack* stack);

//TODO: Все переименования сделать в cpp-файлах тоже
//ИСПРАВЛЕНО.