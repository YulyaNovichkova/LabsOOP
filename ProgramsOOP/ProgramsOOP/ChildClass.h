//TODO: убрать слово Class из названия файла
#pragma once
#include "Person.h"

class Child : public Person
{
private:
	//TODO: null по умолчанию
	//ИСПРАВЛЕНО.
	Person* _mother = NULL;
	//TODO: null по умолчанию
	//ИСПРАВЛЕНО.
	Person* _father = NULL;
	string _school;
public:
	Child() {};
	//TODO: реализацию в cpp

	Child(string surname, string name, enum Sex sex, int age, Person* mother, Person* father, string school) : Person (surname, name, sex, age)
	{ 
		SetMother(mother);
		SetFather(father);
		SetSchool(school);
	}//TODO: пустую строку между функциями
	//TODO: реализацию в cpp
	//TODO: комментарии к функции
	void SetMother(Person* mother)
	{
		_mother = mother;
	}//TODO: пустую строку между функциями
	//TODO: реализацию в cpp
	//TODO: комментарии к функции
	void SetFather(Person* father)
	{
		_father = father;
	}//TODO: пустую строку между функциями
	//TODO: реализацию в cpp
	//TODO: комментарии к функции
	void SetSchool(string school)
	{
		_school = school;
	}//TODO: пустую строку между функциями
	//TODO: реализацию в cpp
	//TODO: комментарии к функции
	Person* GetMother()
	{
		return _mother;
	}//TODO: пустую строку между функциями
	//TODO: реализацию в cpp
	//TODO: комментарии к функции
	Person* GetFather()
	{
		return _father;
	}//TODO: пустую строку между функциями
	//TODO: реализацию в cpp
	//TODO: комментарии к функции
	string GetSchool()
	{
		return _school;
	} //TODO: пустую строку между функциями
	//TODO: реализацию в cpp
	//TODO: комментарии к функции
	static Child* CreateRandomChild();
};