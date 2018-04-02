#pragma once
#include "PersonClass.h"

class PersonList
{
private:
	//PersonListItem * _head; //��������� �� ������ ������
	int _count; //���������� ��������� � ������
public:
	PersonList(); //����������� ������
	void Add(Person* person); //�������� �������� � ������
	Person* Find(int index); //����� �������� �� ���������� �������
	int IndexOf(Person* person); //������� ������ ��������, ���� �� ���� � ������
	void Remove(Person* person); //������� �������� �� ������
	void RemoveAt(int index); //������� �������� �� ������ �� �������
	void Clear(); //�������� ������
	int GetCount();
};