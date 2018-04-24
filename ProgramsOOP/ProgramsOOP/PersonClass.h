#pragma once
//TODO: ������ ����� Class �� �������� �����
#include <iostream>
#include <string>

using namespace std;

//TODO: ������������ � ��������� ����
//TODO: ������ �������� ������������ �� ����� ������, �������� ������ �� ����� ������
enum Sex { Female = 0, Male = 1 };

class Person 
{
protected:
	string _surname;
	string _name;
	Sex _sex;
	unsigned int _age;
public:
	Person() {}; //TODO: ����� ��������� ���� ���� ������ ������
    //TODO: ���������� � cpp-����
	//TODO: ����������� � �������
	Person(string surname, string name, enum Sex sex, int age)
	{
		SetSurname(surname);
		SetName(name);
		SetSex(sex);
		SetAge(age);
	};
	//TODO: ���������� � cpp-����
	//TODO: ����������� � �������
	void SetSurname(string surname)
	{
		_surname = surname;
	} //TODO: ����� ��������� ���� ���� ������ ������
	  //TODO: ���������� � cpp-����
	  //TODO: ����������� � �������
	void SetName(string name)
	{
		_name = name;
	} //TODO: ����� ��������� ���� ���� ������ ������
	  //TODO: ���������� � cpp-����
	  //TODO: ����������� � �������
	void SetSex(enum Sex sex)
	{
		_sex = sex;
	} //TODO: ����� ��������� ���� ���� ������ ������
	  //TODO: ���������� � cpp-����
	  //TODO: ����������� � �������
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
	//TODO: ���������� � cpp-����
	//TODO: ����������� � �������
	string GetSurname()
	{
		return _surname;
	} //TODO: ����� ��������� ���� ���� ������ ������
	  //TODO: ���������� � cpp-����
	  //TODO: ����������� � �������
	string GetName()
	{
		return _name;
	} //TODO: ����� ��������� ���� ���� ������ ������
	  //TODO: ���������� � cpp-����
	  //TODO: ����������� � �������
	int GetSex()
	{
		return _sex;
	} //TODO: ����� ��������� ���� ���� ������ ������
	  //TODO: ���������� � cpp-����
	  //TODO: ����������� � �������
	int GetAge()
	{
		return _age;
	} //TODO: ����� ��������� ���� ���� ������ ������
	  //TODO: ����������� � �������
	static Person* CreateRandomPerson();
	//TODO: ����������� � �������
	static Person* Read();
	//TODO: ����������� � �������
	static void ShowPerson(Person* person);
	//virtual char* GetDescription();
};



