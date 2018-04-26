//TODO: ������ ����� Class �� �������� �����
#pragma once
#include "Person.h"

class Child : public Person
{
private:
	//TODO: null �� ���������
	//����������.
	Person* _mother = NULL;
	//TODO: null �� ���������
	//����������.
	Person* _father = NULL;
	string _school;
public:
	Child() {};
	//TODO: ���������� � cpp

	Child(string surname, string name, enum Sex sex, int age, Person* mother, Person* father, string school) : Person (surname, name, sex, age)
	{ 
		SetMother(mother);
		SetFather(father);
		SetSchool(school);
	}//TODO: ������ ������ ����� ���������
	//TODO: ���������� � cpp
	//TODO: ����������� � �������
	void SetMother(Person* mother)
	{
		_mother = mother;
	}//TODO: ������ ������ ����� ���������
	//TODO: ���������� � cpp
	//TODO: ����������� � �������
	void SetFather(Person* father)
	{
		_father = father;
	}//TODO: ������ ������ ����� ���������
	//TODO: ���������� � cpp
	//TODO: ����������� � �������
	void SetSchool(string school)
	{
		_school = school;
	}//TODO: ������ ������ ����� ���������
	//TODO: ���������� � cpp
	//TODO: ����������� � �������
	Person* GetMother()
	{
		return _mother;
	}//TODO: ������ ������ ����� ���������
	//TODO: ���������� � cpp
	//TODO: ����������� � �������
	Person* GetFather()
	{
		return _father;
	}//TODO: ������ ������ ����� ���������
	//TODO: ���������� � cpp
	//TODO: ����������� � �������
	string GetSchool()
	{
		return _school;
	} //TODO: ������ ������ ����� ���������
	//TODO: ���������� � cpp
	//TODO: ����������� � �������
	static Child* CreateRandomChild();
};