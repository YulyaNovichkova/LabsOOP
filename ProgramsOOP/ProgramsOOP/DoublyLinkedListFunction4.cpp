#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "DoublyLinkedList4.h"
#include "StructFunction3.h"

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
{/*
	Node *tempList = new Node; // Память под новый
	tempList->data = data; // Записываем значение в структуру
	if (list->tail != NULL)
	{
		tempList->prev = list->tail;
		list->tail->next = tempList;
	}
	else
	{
		list->head = tempList;
	}
	list->tail = tempList;
	list->size++;*/
	InsertElement(list, data, 0);
	list->size++;
}

Person* GetPerson(List* list, int index)
{
	Node* node = new Node;
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
	newNode->next = NULL;
	newNode->prev = NULL;

	Node* node = list->head;
	int i = 0;
	while (i != index && node != NULL)
	{
		++i;
		node = node->next;
	}
	// n check
	Node* count = list->head;
	int n = 0;
	do
	{
		count = count->next;
		n++;
	} while (count != NULL);

	if (index > n)
	{
		throw "Mistake! This index too big. \n";
		return;
	}

	Node* current = list->head;
	for (int i = 1; i < index && current->next != NULL; i++)
		current = current->next;

	if (index == 0)
	{
		//вставляем новый элемент на первое место
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
	}
	else
	{
		//вставляем новый элемент на непервое место
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
	case 1:
	{
		const char *maleSurname[] = { "Walter", "Krause", "Zimmer", "Regenherz", "Von-Webber" };
		CopyCharString(person.Surname, maleSurname[rand() % 5]);
		const char *maleName[] = { "Johann", "Walter", "Ludwig", "Karl", "Ulrich" };
		CopyCharString(person.Name, maleName[rand() % 5]);

	}
	case 0:
	{
		const char *femaleSurname[] = { "Marinelli", "Alfieri", "Bellini", "Ferrario", "Cortese" };
		CopyCharString(person.Surname, femaleSurname[rand() % 5]);
		const char *femaleName[] = { "Annabella", "Ottavia", "Laura", "Alessia", "Chiara" };
		CopyCharString(person.Name, femaleName[rand() % 5]);
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
	else NULL;
}