#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "PersonListClass.h"
#include "PersonClass.h"

using namespace std;

void PersonList::Show()
{
	PersonListItem* current = _head;
	if (_head == NULL)
	{
		return;
	}
	cout << "List:" << endl;
	while (current)
	{
		Person::ShowPerson(current->date);
		current = current->_next;
	}
	cout << endl;
}

//добавить человека в список
void PersonList::Add(Person* person)
{
	PersonListItem* temp = new PersonListItem(person);
	if (!_head)
	{
		_head = temp;
	}
	else
	{
		temp->_prev = _tail;
		_tail->_next = temp;
	}
	_tail = temp;
	_count++;
}

//найти человека по указанному индексу
Person* PersonList::Find(int index)
{
	if (index < 0)
	{
		return nullptr;
	}

	PersonListItem* searchedItem = _head;

	for (int i = 0; i < index; i++)
	{
		if (searchedItem->_next)
		{
			searchedItem = searchedItem->_next;
		}
	}
	return searchedItem->GetValue();
}

//вернуть индекс человека, если он есть в списке
int PersonList::IndexOf(Person* person)
{
	PersonListItem* searchedPerson = _head;
	int index = 0;
	while (searchedPerson)
	{
		if (searchedPerson->GetValue() == person)
		{
			return index;
		}
		index++;
		searchedPerson = searchedPerson->_next;
	}
	return -1;
}

//удалить человека из списка
void PersonList::Remove(Person* person)
{
	PersonListItem* deletedItem = _head;

	if (person)
	{
		while (deletedItem->GetValue() != person)
		{
			if (!deletedItem->_next)
			{
				return;
			}
			deletedItem = deletedItem->_next;
		}
	}
	else
	{
		return;
	}

	if (deletedItem->_prev)
		deletedItem->_prev->_next = deletedItem->_next;
	else
		_head = deletedItem->_next;

	if (deletedItem->_next)
		deletedItem->_next->_prev = deletedItem->_prev;
	else
		_tail = deletedItem->_prev;

	delete deletedItem;
}

//удалить человека из списка по индексу
void PersonList::RemoveAt(int index)
{
	PersonListItem* deletedItem = _head;

	if (index >= 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (!deletedItem->_next)
			{
				return;
			}
			deletedItem = deletedItem->_next;
		}
	}
	else
	{
		return;
	}

	if (deletedItem->_prev)
		deletedItem->_prev->_next = deletedItem->_next;
	else
		_head = deletedItem->_next;

	if (deletedItem->_next)
		deletedItem->_next->_prev = deletedItem->_prev;
	else
		_tail = deletedItem->_prev;

	delete deletedItem;
}

//очистить список
void PersonList::Clear()
{
	PersonListItem* temp = _head;
	PersonListItem* tempNext;
	while (temp)
	{
		tempNext = temp->_next;
		delete temp;
		temp = tempNext;
	}
	_head = nullptr;
	_tail = nullptr;
	_count = 0;
}


int PersonList::GetCount()
{
	return _count;
}
