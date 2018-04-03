#pragma once
#include <iostream>
#include <string>

using namespace std;

enum Sex { Female = 0, Male = 1 };

class Person 
{
private:
	string _surname;
	string _name;
	Sex _sex;
	int _age;
public:
	Person(string surname, string name, enum Sex sex, int age) //конструктор класса
	{
		SetSurname(surname);
		SetName(name);
		SetSex(sex);
		SetAge(age);
	}
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
	void SetAge(int age)
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
	void Show()
	{
		cout << "Surname: " << _surname;
		cout << endl << "Name: " << _name;
		switch (_sex)
		{
		case 0:
			cout << endl << "Sex: female";
			break;
		case 1:
			cout << endl << "Sex: male";
			break;
		default:
			break;
		}
		cout << endl << "Age: " << _age << endl;
	}
	Person* GetRandomPerson();
};

Person ReadPerson();
void ShowPerson(Person person);
