//TODO: ������ ����� Class �� �������� �����
#pragma once
#include "PersonClass.h"

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
	PersonListItem * _head; //��������� �� ������ ������
	PersonListItem * _tail;
	int _count; //���������� ��������� � ������
public:
	PersonList() //����������� ������
	{
		//TODO: ������� ������������ � ������������� ����� �� ���������
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


