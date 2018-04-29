//TODO: убрать слово Class из названия файла
//ИСПРАВЛЕНО.
#pragma once
#include "Person.h"
#include "Sex.h"

class PersonList
{
private:
	class PersonListItem
	{
	public:
		PersonListItem* _next = nullptr;
		PersonListItem* _prev = nullptr;
		Person* person;
	};
	//указатель на голову списка
	PersonListItem * _head = nullptr; 
	PersonListItem * _tail = nullptr;
	//количество элементов в списке
	int _count = 0; 
public:
	//конструктор класса
	PersonList() {}; 
	//Добавить человека в список
	void Add(Person* person); 
	//Найти человека по указанному индексу
	Person* Find(int index); 
	//Вернуть индекс человека, если он есть в списке
	int IndexOf(Person* person); 
	//Удалить человека из списка
	void Remove(Person* person); 
	//Удалить человека из списка по индексу
	void RemoveAt(int index); 
	//Очистить список
	void Clear(); 
	int GetCount();
	//Вывод списка
	void Show();
};


