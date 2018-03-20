#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "DoublyLinkedList4.h"

using namespace std;

void ListShow(List* list)
{
	Node* current = list->head;
	if (list->head == NULL)
		return;

	cout << "List" << endl;
	do
	{
		cout << current->data << ' ';
		current = current->next;
	} while (current != NULL);
	cout << endl;
};

// Добавление узла в ДЛС 
void AddElement(List* list, int data)
{
	//валидация параметров
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	int i = 0;
	Node* node = list->head;

	if (list->head == NULL)
	{
		list->head = newNode;
		list->tail = newNode;
		return;
	}

	while (node->next)
		node = node->next;

	node->next = newNode;
	newNode->prev = node;
	list->tail = newNode;


}
// Вставка узла ДЛС
void InsertElement(List* list, int data, int index)
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
		throw "Mistake, Master! This index too big. Try again! \n";
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

// Удаление узла из ДЛС

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


// Сортировка ДЛС 

Node* SortDoublyLinkedList(List* list)
{
	Node* count = list->head;
	int n = 0;
	do
	{
		count = count->next;
		n++;
	} while (count != NULL);

	int z = 0;

	for (Node* start = list->head; start != NULL; start = start->next)
	{
		for (Node* start2 = start; start2 != NULL; start2 = start2->next)
		{
			Node* temp = start2->next;
			if (temp != NULL && start2->data > temp->data)
			{
				z = start2->data;
				start2->data = temp->data;
				temp->data = z;

			}
		}
	}

	return NULL;
};

// Линейный поиск по ДЛС

Node* Search(List* list, int element)
{
	Node* current = list->head;
	while (current != nullptr)
	{
		if (current->data == element)
		{

			return current;
		}
		current = current->next;
	}
	return NULL;
};