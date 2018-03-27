#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "DoublyLinkedList4.h"
#include "Person.h"
//TODO: см. замечания в заголовочном файле
using namespace std;

void ListShow(List* list)
{
	Node* current = list->head;
	if (list->head == nullptr)
		return;

	cout << "List:" << endl;
	while (current != nullptr)
	{
		ShowPerson(current->data);
		current = current->next;
	}
	cout << endl;
};

void AddElement(List* list, Person data)
{
	InsertElement(list, data, GetLengthStruct(list));
	list->size++;
}

Person* GetPerson(List* list, int index)
{
	Node* node = new Node;
	//TODO: Утечка памяти
	node = list->head;
	int count = 0;
	while (count != index)
	{
		node = node->next;
		count++;
	}
	return &node->data;
}

void InsertElement(List* list, Person data, int index)
{
	Node* newNode = new Node();
	newNode->data = data;

	Node* current = list->head;
	int i = 0;
	//Если список пуст, то значение становится списком
	if (list->head == NULL)
	{
		list->head = newNode;
		list->tail = newNode;
		return;
	}

	//TODO: имя переменной node малоинформативно - непонятно, зачем она нужна в алгоритме
	//TODO: Логичнее сначала определить количество элементов в списке, а потом переходить к текущему элементу
	Node* node = list->head;
	while (i != index && node != NULL)
	{
		++i;
		node = node->next;
	}
	// n check
	//TODO: count - это количество. Именовать так элемент списка - неправильно
	//TODO: Для подсчета элементов списка надо использовать готовую функцию
	Node* count = list->head;
	int n = 0;
	do
	{
		count = count->next;
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

	for (int i = 1; i < index && current->next != NULL; i++)
		current = current->next;
	//Вставляем на первое место
	if (index == 0)
	{
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
	}
	else
	{
		//Вставляем элемент на нужное место
		if (current->next != NULL)
			current->next->prev = newNode;
		newNode->next = current->next;
		current->next = newNode;
		newNode->prev = current;
		current = newNode;
	}
}

void DeleteElement(List* list, int index)
{
	if (list->head == NULL)
		return;

	int i = 0;
	Node* node = list->head;
	while (i != index && node != NULL)
	{
		++i;
		node = node->next;
	}

	if (node == NULL)
		return;
	//начало списка
	if (node->prev == NULL)
	{
		list->head = NULL;
		if (node->next != NULL)
		{
			list->head = node->next;
			list->head->prev = NULL;
		}
	}
	//конец списка
	if (node->next == NULL)
	{
		list->tail = NULL;
		if (node->prev != NULL)
		{
			list->tail = node->prev;
			list->tail->next = NULL;
		}
	}
	//середина списка
	if (node->next != NULL && node->prev != NULL)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
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

int GetLengthStruct(List* list)
{
	int count = 0;
	Node* current = list->head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	if (count > 0)
	{
		return count;
	}
	//TODO: NULL - это адрес (указатель), а функция должна возвращать число
	else NULL;
}