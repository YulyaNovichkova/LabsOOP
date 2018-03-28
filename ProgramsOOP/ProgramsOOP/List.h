#pragma once
#include "Person.h"
//TODO: Если структура называется List, тогда и файл должен называться List, а не DoublyLinkedList. Переименовать файлы
//ИСПРАВЛЕНО.
//TODO: комментарий к структуре
//ИСПРАВЛЕНО.
//Структура данных, содержащая указатели на предыдущий и следующих элемент списка
struct Node
{
	//TODO: поля с заглавной буквы
	//ИСПРАВЛЕНО.
	Person Data;
	Node* Next = NULL;
	Node* Prev = NULL;
};

//TODO: комментарий к структуре
//ИСПРАВЛЕНО.
//Структура данных "Список"
struct List
{
	//TODO: поля с заглавной буквы
	//ИСПРАВЛЕНО.
	int Size;
	Node* Head = NULL;
	Node* Tail = NULL;
};

//TODO: комментарии ко всем функциям, продублировать в cpp_файлах
//ИСПРАВЛЕНО.
//Показать список
void ListShow(List* list);
//Вставка элемента в конец списка
void AddElement(List* list, Person data);
//Вставка элемента на любое место
void InsertElement(List* list, Person data, int index);
//Удаление элемента из списка
void Remove(List* list, int index);
//Возвращает ссылку на элемент списка по указанному индексу
Person* GetPerson(List* list, int index);
//Заполнение Person случайными данными
Person CreateRandomPerson();
//TODO: Если работать с классом string, то такие функции не понадобятся
void CopyCharString(char* structString, const char* constString);
//TODO: Сейчас функция переводится как "Получить длинную структуру", а должно быть "Получить длину списка". Переименовать
//ИСПРАВЛЕНО.
//Длина списка
int GetLengthList(List* list);
//Очистить содержимое списка
void Clear(List* list);