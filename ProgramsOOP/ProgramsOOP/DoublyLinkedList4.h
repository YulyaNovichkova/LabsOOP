#pragma once
#include "StructFunction3.h"
//TODO: Если структура называется List, тогда и файл должен называться List, а не DoublyLinkedList. Переименовать файлы
//TODO: комментарий к структуре
struct Node
{
	//TODO: поля с заглавной буквы
	Person data;
	Node* next = NULL;
	Node* prev = NULL;
};

//TODO: комментарий к структуре
struct List
{
	//TODO: поля с заглавной буквы
	int size;
	Node* head = NULL;
	Node* tail = NULL;
};

//TODO: комментарии ко всем функциям, продублировать в cpp_файлах
int MenuList(List* list);
void ListShow(List* list);
void AddElement(List* list, Person data);
void InsertElement(List* list, Person data, int index);

void DeleteElement(List* list, int index);

Person* GetPerson(List* list, int index);

//TODO: Read - подразумевает чтение с клавиатуры, а здесь функция сама генерирует данные. Заменить Read на Get, Create или Generate
Person ReadRandomPerson();
//TODO: Если работать с классом string, то такие функции не понадобятся
void CopyCharString(char* structString, const char* constString);
//Длина списка
//TODO: Сейчас функция переводится как "Получить длинную структуру", а должно быть "Получить длину списка". Переименовать
int GetLengthStruct(List* list);