#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "PersonList.h"
#include "Person.h"

using namespace std;

void PersonList::Show()
{
	PersonListItem* current = _head;
	if (!(current))
	{
		return;
	}
	while (current)
	{
		Person::ShowPerson(current->person);
		current = current->_next;
	}
	cout << endl;
}

//добавить человека в список
void PersonList::Add(Person* person)
{
	PersonListItem* newItem = new PersonListItem();
	newItem->person = person;
	if (!(_head))
	{
		_head = newItem;
	}
	else
	{
		newItem->_prev = _tail;
		_tail->_next = newItem;
	}
	_tail = newItem;
	_count++;
}

//найти человека по указанному индексу
Person* PersonList::Find(int index)
{
	if (index < 0)
	{
		//TODO: Нет - если кто-то извне передал отрицательный индекс - значит, код извне содержит ошибку. Надо выбрасывать исключение
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
	return searchedItem->person;
}

//вернуть индекс человека, если он есть в списке
int PersonList::IndexOf(Person* person)
{
	PersonListItem* current = _head;
	int index = 0;
	//TODO: вместо while лучше брать for от 0 до конца списка - форы гораздо читаемее уайлов
	while (current != nullptr && index <= _count)
	{
		//TODO: Ну что это за вложенная портянка ifов?
		// Заменить на логическое умножение
		if (current->person->GetSurname() == person->GetSurname())
		{
			if (current->person->GetName() == person->GetName())
			{
				if (current->person->GetSex() == person->GetSex())
				{
					if (current->person->GetAge() == person->GetAge())
					{
						return index;
					}
				}
			}
		}
		current = current->_next;
		index++;
	}
	return -1;
}

//удалить человека из списка
void PersonList::Remove(Person* person)
{
	PersonListItem* deletedItem = _head;

	if (person)
	{
		while (deletedItem->person != person)
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
	//TODO: Слишком большая реализация для функции. Переделать в две строчки
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
