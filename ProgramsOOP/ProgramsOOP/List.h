#pragma once
#include "Person.h"

using namespace std;

//Обобщенный класс "Список"
template <class Type>
class List
{
private:
	//Обобщенный класс, содержащий указатели на следующий и предыдущий элемент списка
	template <class TypeItem>
	class  ListItem
	{
	private:
		TypeItem _data;
	public:
		ListItem<TypeItem>* _next = NULL;
		ListItem<TypeItem>* _prev = NULL;
		//Person data;
		//Конструктор класса по умолчанию
		ListItem() {};

		//Конструктор класса
		ListItem(TypeItem data)
		{
			SetData(data);
		}

		void SetData(TypeItem data)
		{
			_data = data;
		}

		TypeItem GetData()
		{
			return _data;
		}
	};

	//указатель на голову списка
	ListItem<Type>* _head = NULL;
	//указатель на хвост списка
	ListItem<Type>* _tail = NULL;
	//количество элементов в списке
	int _count = 0;
public:
	//конструктор класса
	List() {};



	//Добавить данные в список
	void Add(Type element) 
	{
		ListItem<Type>* newItem = new ListItem<Type>(element);
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
	};

	//Поиск по индексу
	Type* Find(int index)
	{
		if (index < 0)
		{
			return -1;
		}

		ListItem<Type>* searchedItem = _head;
		for (int i = 0; i < index; i++)
		{
			if (searchedItem->_next)
			{
				searchedItem = searchedItem->_next;
			}
		}
		return searchedItem->data;
	}

	//Вернуть индекс данных, если они есть в списке
	int IndexOf(Type data)
	{
		ListItem<Type>* current = _head;
		for (int index = 0; index < GetCount(); index++)
		{
			if (current->datda == data)
			{
				return index;
			}
			current = current->_next;
		}
		return -1;
	}

	//Удалить человека из списка
	void Remove(Type data)
	{
		int index = IndexOf(data);
		RemoveAt(index);
	}

	//Удалить человека из списка по индексу
	void RemoveAt(int index) 
	{
		ListItem<Type>* deletedItem = _head;

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

	//Очистить список
	void Clear() 
	{
		ListItem<Type>* temp = _head;
		ListItem<Type>* tempNext;
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

	int GetCount() 
	{
		return _count;
	}

	//Вывод списка
	void Show() 
	{
		ListItem<Type>* current = _head;
		if (!(current))
		{
			return;
		}
		while (current)
		{
			cout << current->GetData() << endl;
			current = current->_next;
		}
		cout << endl;
	}

	//Перегрузка оператора "<<" (добавления) для *Person
	friend ostream& operator << (ostream& s, Person* p);

	//Перегрузка оператора "<<" (добавления) для double[5]
	friend ostream& operator << (ostream& s, double* d);

	//Перегрузка оператора "<<" (добавления) для List<double>
	friend ostream& operator << (ostream& s, List<Type>* l)
	{
		ListItem<Type>* temp = l->_head;
		while (temp)
		{
			s << temp->GetData() << " ";
			temp = temp->_next;
		}
		return s;
	}
};
