//TODO: ������ ����� Class �� �������� �����
#pragma once
#include "PersonClass.h"

class Adult : public Person
{
private:
	//TODO: ��������� �������� null �� ���������
	Person* _marriedOn;
	string _workPlace;
public:
	Adult() {};
	/*Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace)
	{
		SetSurname(surname);
		SetName(name);
		SetSex(sex);
		SetAge(age);
		SetMarriedOn(marriedOn);
		SetWorkPlace(workPlace);
	}*/
	//TODO: �������������� �� Person ����������. ����� � ����� �����������?
	void SetSurname(string surname)
	{
		_surname = surname;
	}
	//TODO: �������������� �� Person ����������. ����� � ����� �����������?
	string GetSurname()
	{
		return _surname;
	}
	//TODO: �������������� �� Person ����������. ����� � ����� �����������?
	void SetName(string name)
	{
		_name = name;
	}
	//TODO: �������������� �� Person ����������. ����� � ����� �����������?
	string GetName()
	{
		return _name;
	}
	//TODO: �������������� �� Person ����������. ����� � ����� �����������?
	void SetSex(enum Sex sex)
	{
		_sex = sex;
	}
	//TODO: �������������� �� Person ����������. ����� � ����� �����������?
	int GetSex()
	{
		return _sex;
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