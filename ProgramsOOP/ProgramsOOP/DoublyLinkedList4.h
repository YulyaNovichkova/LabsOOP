#pragma once
#include "StructFunction3.h"

struct Node
{
	Person data;
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	int size;
	Node* head = NULL;
	Node* tail = NULL;
};

int MenuList(List* list);
void ListShow(List* list);
void AddElement(List* list, Person data);
void InsertElement(List* list, Person data, int index);
void DeleteElement(List* list, int index);
Person* GetPerson(List* list, int index);
Person ReadRandomPerson();
void CopyCharString(char* structString, const char* constString);
//Длина списка
int GetLengthStruct(List* list);