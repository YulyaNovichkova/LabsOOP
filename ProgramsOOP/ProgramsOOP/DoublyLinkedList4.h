#pragma once
#include "iostream"
#include "StructFunction3.h"

struct Node
{
	int data;
	//Person *person;
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};

int MenuList(List* list);
void AddElement(List* list, int data);
void InsertElement(List* list, int data, int index);
void DeleteElement(List* list, int index);
void ListShow(List* list);

Node* SortDoublyLinkedList(List* list);
Node* Search(List* list, int element);
