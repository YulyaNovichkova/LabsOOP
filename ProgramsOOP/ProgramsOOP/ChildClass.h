#pragma once
#include "PersonClass.h"

class Child : public Person
{
private:
	Person* _mother;
	Person* _father;
	string _school;
public:
	Child() {};
	Child(string surname, string name, enum Sex sex, int age, Person* mother, Person* father, string school)
	{
		SetSurname(surname);
		SetName(name);
		SetSex(sex);
		SetAge(age);
		SetMother(mother);
		SetFather(father);
		SetSchool(school);
	}
	void SetMother(Person* mother)
	{
		_mother = mother;
	}
	void SetFather(Person* father)
	{
		_father = father;
	}
	void SetSchool(string school)
	{
		_school = school;
	}
	Person* GetMother()
	{
		return _mother;
	}
	Person* GetFather()
	{
		return _father;
	}
	string GetSchool()
	{
		return _school;
	}
	static Child* CreateRandomChild();
};