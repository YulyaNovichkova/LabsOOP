#pragma once
#include "PersonClass.h"

class PersonList
{
private:
	class PersonListItem
	{
	private:
		Person * _value;
	public:
		Person * date;
		PersonListItem* _next = nullptr;
		PersonListItem* _prev = nullptr;
		PersonListItem(Person* person)
		{
			_value = person;
		};
		Person* GetValue()
		{
			return _value;
		}
	};
	PersonListItem * _head; //указатель на голову списка
	PersonListItem * _tail;
	int _count; //количество элементов в списке
public:
	PersonList() //конструктор класса
	{
		_head = nullptr;
		_tail = nullptr;
		_count = 0;
	}; 
	void Add(Person* person); //добавить человека в список
	Person* Find(int index); //найти человека по указанному индексу
	int IndexOf(Person* person); //вернуть индекс человека, если он есть в списке
	void Remove(Person* person); //удалить человека из списка
	void RemoveAt(int index); //удалить человека из списка по индексу
	void Clear(); //очистить список
	int GetCount();
	void Show();
};


