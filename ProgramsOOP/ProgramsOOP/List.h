//#pragma once
//#include "Person.h"
//
////Структура данных, содержащая указатели на предыдущий и следующих элемент списка
//struct Node
//{
//	Person Data;
//	Node* Next = NULL;
//	Node* Prev = NULL;
//};
//
////Структура данных "Список"
//struct List
//{
//	int Size;
//	Node* Head = NULL;
//	Node* Tail = NULL;
//};
//
////Показать список
//void ListShow(List* list);
////Вставка элемента в конец списка
//void AddElement(List* list, Person data);
////Вставка элемента на любое место
//void InsertElement(List* list, Person data, int index);
////Удаление элемента из списка
//void Remove(List* list, int index);
////Возвращает ссылку на элемент списка по указанному индексу
//Person* GetPerson(List* list, int index);
////Заполнение Person случайными данными
//Person CreateRandomPerson();
//void CopyCharString(char* structString, const char* constString);
////Длина списка
//int GetLengthList(List* list);
////Очистить содержимое списка
//void Clear(List* list);