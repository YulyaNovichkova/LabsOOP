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
	PersonListItem * _head; //��������� �� ������ ������
	PersonListItem * _tail;
	int _count; //���������� ��������� � ������
public:
	PersonList() //����������� ������
	{
		_head = nullptr;
		_tail = nullptr;
		_count = 0;
	}; 
	void Add(Person* person); //�������� �������� � ������
	Person* Find(int index); //����� �������� �� ���������� �������
	int IndexOf(Person* person); //������� ������ ��������, ���� �� ���� � ������
	void Remove(Person* person); //������� �������� �� ������
	void RemoveAt(int index); //������� �������� �� ������ �� �������
	void Clear(); //�������� ������
	int GetCount();
	void Show();
};


