#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "PersonListClass.h"
#include "PersonClass.h"
using namespace std;

//�������� ������
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

//������� �������� � ����� ������
void AddElement(List* list, Person data)
{
	InsertElement(list, data, GetLengthList(list));
}

//���������� ������ �� ������� ������ �� ���������� �������
Person* GetPerson(List* list, int index)
{
	Node* node = new Node;
	node = list->Head;
	int count = 0;
	while (count != index)
	{
		node = node->Next;
		count++;
	}
	return &node->Data;
	delete[] node;
}

//������� �������� �� ����� �����
void InsertElement(List* list, Person data, int index)
{
	Node* newNode = new Node();
	newNode->Data = data;
	int i = 0;
	//���� ������ ����, �� �������� ���������� �������
	if (list->Head == NULL)
	{
		list->Head = newNode;
		list->Tail = newNode;
		return;
	}

	Node* node = list->Head;
	while (i != index && node != NULL)
	{
		++i;
		node = node->Next;
	}

	if (index > GetLengthList(list))
	{
		//TODO: ����������� ���� exception, � �� ������
		throw "Mistake! This index too big. \n";
		return;
	}

	for (int i = 1; i < index && node->Next != NULL; i++)
		node = node->Next;
	//��������� �� ������ �����
	if (index == 0)
	{
		newNode->Next = list->Head;
		list->Head->Prev = newNode;
		list->Head = newNode;
	}
	else
	{
		//��������� ������� �� ������ �����
		if (node->Next != NULL)
			node->Next->Prev = newNode;
		newNode->Next = node->Next;
		node->Next = newNode;
		newNode->Prev = node;
		node = newNode;
	}
}

//�������� �������� �� ������
void Remove(List* list, int index)
{
	Node* node = list->Head;

	if (node == NULL)
	{
		return;
	}
	if (list->Head == NULL)
	{
		return;
	}

	int i = 0;
	while (i != index && node != NULL)
	{
		++i;
		node = node->Next;
	}
	//������ ������
	if (node->Prev == NULL)
	{
		list->Head = NULL;
		if (node->Next != NULL)
		{
			list->Head = node->Next;
			list->Head->Prev = NULL;
		}
	}
	//����� ������
	if (node->Next == NULL)
	{
		list->Tail = NULL;
		if (node->Prev != NULL)
		{
			list->Tail = node->Prev;
			list->Tail->Next = NULL;
		}
	}
	//�������� ������
	if (node->Next != NULL && node->Prev != NULL)
	{
		node->Next->Prev = node->Prev;
		node->Prev->Next = node->Next;
	}
	delete node;
}

//���������� Person ���������� �������
Person CreateRandomPerson()
{
	srand(time(NULL));
	//�������
	const char* femaleSurname[] = { "Novichkova", "Ovsyannikova", "Belova", "Petuxova", "Shilnikova",
		"Nagih", "Bespalova", "Lebedeva", "Alexseeva", "Koreshkova",
		"Karipova", "Kislova", "Smirnova", "Proxorova", "Maksova" };

	const char* femaleName[] = { "Yulya", "Nastya", "Elena", "Irina", "Kristina",
		"Alisa", "Inna", "Ekaterina", "Dasha", "Masha",
		"Olga", "Evgeniya", "Anna", "Liliya", "Yana" };
	//�������
	const char* maleSurname[] = { "Ivanov", "Petrov", "Sidorov", "Trofimov", "Vakulin",
		"Kolesnik", "Solovov", "Kalinin", "Kachev", "Ermolaev",
		"Tihonov", "Brodt", "Dvornikov", "Pushkarev", "Mulenok" };

	const char* maleName[] = { "Dmitriy", "Pasha", "Aleksandr", "Sergey", "Ilya",
		"Yaroslav", "Aleksey", "Kirill", "Nikolay", "Ivan",
		"Vladislav", "Slava", "Georgiy", "Evgeniy", "Vitaliy" };
	Person person;
	person.Age = rand() % 100;
	person.Sex = Sex(rand() % 2);
	if (person.Sex == 0)
	{
		CopyCharString(person.Surname, femaleSurname[rand() % 15]);
		CopyCharString(person.Name, femaleName[rand() % 15]);
	}
	else
	{
		CopyCharString(person.Surname, maleSurname[rand() % 15]);
		CopyCharString(person.Name, maleName[rand() % 15]);
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

//����� ������
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
	else return 0;
}

//�������� ���������� ������
void Clear(List* list)
{
	while (list->Head)
	{
		list->Tail = list->Head->Next;
		delete list->Head;
		list->Head = list->Tail;
	}
}