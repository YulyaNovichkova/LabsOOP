//TODO: ������ ����� Class �� �������� �����
#pragma once
#include "Person.h"

class Adult : public Person
{
private:
	//TODO: ��������� �������� null �� ���������
	Person* _marriedOn;
	string _workPlace;
public:
	Adult() {};
	Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace) : Person (surname, name, sex, age)
	{
	SetMarriedOn(marriedOn);
	SetWorkPlace(workPlace);
	}
	
	//TODO: �������������� �� Person ����������. ����� � ����� �����������?
	void SetAge(unsigned int age)
	{
		if (age >= 18)
		{
			_age = age;
		}
		else
		{
			//TODO: ��������� ��, ��� � ��������� ������� ������ 18? �����, �������� ������� ����������?
			_age = 18;
		}
	}
	//TODO: �������������� �� Person ����������. ����� � ����� �����������?
	int GetAge()
	{
		return _age;
	}

	//TODO: ����������� � �������
	//TODO: ���������� � cpp-����

	void SetMarriedOn(Person* marriedOn)
	{
		_marriedOn = marriedOn;
	} //TODO: ������ ������ ����� ���������
	  //TODO: ���������� � cpp-����
	  //TODO: ����������� � �������
	void SetWorkPlace(string workPlace)
	{
		_workPlace = workPlace;
	}
	//TODO: ���������� � cpp-����
	//TODO: ����������� � �������
	Person* GetMarriedOn()
	{
		return _marriedOn;
	}//TODO: ������ ������ ����� ���������
	 //TODO: ���������� � cpp-����
	 //TODO: ����������� � �������
	string GetWorkPlace()
	{
		return _workPlace;
	}
	//TODO: ����������� � �������
	static Adult* CreateRandomAdult();
};