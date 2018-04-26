#pragma once
#include "PersonClass.h"

class Adult : public Person
{
private:
	Person* _marriedOn;
	string _workPlace;
public:
	Adult();
	/*Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace)
	{
	SetSurname(surname);
	SetName(name);
	SetSex(sex);
	SetAge(age);
	SetMarriedOn(marriedOn);
	SetWorkPlace(workPlace);
	}*/

	void SetSurname(string surname)
	{
		_surname = surname;
	}
	string GetSurname()
	{
		return _surname;
	}
	void SetName(string name)
	{
		_name = name;
	}
	string GetName()
	{
		return _name;
	}
	void SetSex(enum Sex sex)
	{
		_sex = sex;
	}
	int GetSex()
	{
		return _sex;
	}
	void SetAge(unsigned int age)
	{
		if (age >= 18)
		{
			_age = age;
		}
		else
		{
			_age = 18;
		}
	}
	int GetAge()
	{
		return _age;
	}
	void SetMarriedOn(Person* marriedOn)
	{
		_marriedOn = marriedOn;
	}
	void SetWorkPlace(string workPlace)
	{
		_workPlace = workPlace;
	}

	Person* GetMarriedOn()
	{
		return _marriedOn;
	}
	string GetWorkPlace()
	{
		return _workPlace;
	}
	static Adult* CreateRandomAdult();
};