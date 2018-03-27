#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "List.h"
#include "Person.h"
//TODO: см. замечания в заголовочном файле
using namespace std;

void ListShow(List* list)
{
	Node* current = list->Head;
	if (list->Head == nullptr)
		return;

	cout << "List:" << endl;
	while (current != nullptr)
	{
		ShowPerson(current->Data);
		current = current->Next;
	}
	cout << endl;
};

void AddElement(List* list, Person data)
{
	InsertElement(list, data, GetLengthList(list));
	list->Size++;
}

Person* GetPerson(List* list, int index)
{
	Node* node = new Node;
	//TODO: Утечка памяти
	node = list->Head;
	int count = 0;
	while (count != index)
	{
		node = node->Next;
		count++;
	}
	return &node->Data;
}

void InsertElement(List* list, Person data, int index)
{
	Node* newNode = new Node();
	newNode->Data = data;

	Node* current = list->Head;
	int i = 0;
	//Если список пуст, то значение становится списком
	if (list->Head == NULL)
	{
		list->Head = newNode;
		list->Tail = newNode;
		return;
	}

	//TODO: имя переменной node малоинформативно - непонятно, зачем она нужна в алгоритме
	//TODO: Логичнее сначала определить количество элементов в списке, а потом переходить к текущему элементу
	Node* node = list->Head;
	while (i != index && node != NULL)
	{
		++i;
		node = node->Next;
	}
	// n check
	//TODO: count - это количество. Именовать так элемент списка - неправильно
	//TODO: Для подсчета элементов списка надо использовать готовую функцию
	Node* count = list->Head;
	int n = 0;
	do
	{
		count = count->Next;
		n++;
	} while (count != NULL);

	if (index > n)
	{
		//TODO: Выбрасывать надо exception, а не строку
		throw "Mistake! This index too big. \n";
		return;
	}

	//TODO: Опять поиск текущего элемента? Зачем тогда переменная node?
	//Node* current = list->head;

	for (int i = 1; i < index && current->Next != NULL; i++)
		current = current->Next;
	//Вставляем на первое место
	if (index == 0)
	{
		newNode->Next = list->Head;
		list->Head->Prev = newNode;
		list->Head = newNode;
	}
	else
	{
		//Вставляем элемент на нужное место
		if (current->Next != NULL)
			current->Next->Prev = newNode;
		newNode->Next = current->Next;
		current->Next = newNode;
		newNode->Prev = current;
		current = newNode;
	}
}

void DeleteElement(List* list, int index)
{
	if (list->Head == NULL)
		return;

	int i = 0;
	Node* node = list->Head;
	while (i != index && node != NULL)
	{
		++i;
		node = node->Next;
	}

	if (node == NULL)
		return;
	//начало списка
	if (node->Prev == NULL)
	{
		list->Head = NULL;
		if (node->Next != NULL)
		{
			list->Head = node->Next;
			list->Head->Prev = NULL;
		}
	}
	//конец списка
	if (node->Next == NULL)
	{
		list->Tail = NULL;
		if (node->Prev != NULL)
		{
			list->Tail = node->Prev;
			list->Tail->Next = NULL;
		}
	}
	//середина списка
	if (node->Next != NULL && node->Prev != NULL)
	{
		node->Next->Prev = node->Prev;
		node->Prev->Next = node->Next;
	}
	delete node;
}

Person ReadRandomPerson()
{
	Person person;
	srand(time(NULL));
	person.Age = rand() % 100;
	int sex = rand() % 1;

	switch (sex)
	{
		//TODO: ПОМЕНЯТЬ
		case 0:
		{
			const char *femaleSurname[] = { "Novichkova", "Ovsyannikova", "Belova", "Petuxova", "Kolesnik" };
			CopyCharString(person.Surname, femaleSurname[rand() % 5]);
			const char *femaleName[] = { "Yulya", "Nastya", "Elena", "Irina", "Kristina" };
			CopyCharString(person.Name, femaleName[rand() % 5]);
		}
		case 1:
		{
			const char *maleSurname[] = { "Ivanov", "Petrov", "Sidorov", "Trofimov", "Vakulin" };
			CopyCharString(person.Surname, maleSurname[rand() % 5]);
			const char *maleName[] = { "Dima", "Pasha", "Alex", "Sergey", "Uluya" };
			CopyCharString(person.Name, maleName[rand() % 5]);
		}
	}
	return person;
}

void CopyCharString(char* structString, const char* constString)
{
	int i = 0;
	for (; constString[i]; i++)
	{
		structString[i] = constString[i];
	}
	structString[i] = '\0';
}

int GetLengthList(List* list)
{
	int count = 0;
	Node* current = list->Head;
	while (current != NULL)
	{
		count++;
		current = current->Next;
	}
	if (count > 0)
	{
		return count;
	}
	//TODO: NULL - это адрес (указатель), а функция должна возвращать число
	else NULL;
}