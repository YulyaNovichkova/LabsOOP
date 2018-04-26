#pragma once
#include <iostream>
#include <string>

using namespace std;

enum Sex { Female = 0, Male = 1 };

class Person 
{
protected:
	string _surname;
	string _name;
	Sex _sex;
	unsigned int _age;
public:
	Person() {};
	Person(string surname, string name, enum Sex sex, int age)
	{
		SetSurname(surname);
		SetName(name);
		SetSex(sex);
		SetAge(age);
	};

	void SetSurname(string surname)
	{
		_surname = surname;
	}
	void SetName(string name)
	{
		_name = name;
	}
	void SetSex(enum Sex sex)
	{
		_sex = sex;
	}
	void SetAge(unsigned int age)
	{
			_age = age;
	}

	string GetSurname()
	{
		return _surname;
	}
	string GetName()
	{
		return _name;
	}
	int GetSex()
	{
		return _sex;
	}
	int GetAge()
	{
		return _age;
	}
	static Person* CreateRandomPerson();
	static Person* Read();
	static void ShowPerson(Person* person);
	virtual char* GetDescription();
};



