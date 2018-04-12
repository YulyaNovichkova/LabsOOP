#pragma once
#include "PersonClass.h"

class Adult : public Person
{
private:
	Person* _marriedOn;
	string _workPlace;
public:
	Adult();
	Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace)
	{
		SetSurname(surname);
		SetName(name);
		SetSex(sex);
		SetAge(age);
		SetMarriedOn(marriedOn);
		SetWorkPlace(workPlace);
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
};