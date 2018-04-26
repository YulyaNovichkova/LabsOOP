//TODO: убрать слово Class из названия файла
//ИСПРАВЛЕНО.
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
	Child(string surname, string name, enum Sex sex, int age, Person* mother, Person* father, string school);
	void SetMother(Person* mother);
	void SetFather(Person* father);
	void SetSchool(string school);
	Person* GetMother();
	Person* GetFather();
	string GetSchool();
	//TODO: реализацию в cpp
	//TODO: комментарии к функции
	static Child* CreateRandomChild();
};