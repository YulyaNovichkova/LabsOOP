//TODO: убрать слово Class из названия файла
#pragma once
#include "PersonClass.h"

class Child : public Person
{
private:
	//TODO: null по умолчанию
	Person* _mother;
	//TODO: null по умолчанию
	Person* _father;
	string _school;
public:
	Child() {};
	//TODO: реализацию в cpp
	Child(string surname, string name, enum Sex sex, int age, Person* mother, Person* father, string school)
	{ //TODO: отнаследовать от конструктора базового класса, чтобы избавиться от дублирования кода в этом конструкторе
		SetSurname(surname);
		SetName(name);
		SetSex(sex);
		SetAge(age);
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