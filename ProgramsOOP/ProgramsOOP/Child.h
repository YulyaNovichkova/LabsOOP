﻿#pragma once
#include "Person.h"

class Child : public Person
{
private:
	Person* _mother = NULL;
	Person* _father = NULL;
	string _school;
public:
	//Конструктор по умолчанию
	Child() {};
	//Конструктор класса Child
	Child(string surname, string name, enum Sex sex, int age, Person* mother, Person* father, string school);
	//Задать данные матери
	void SetMother(Person* mother);
	//Задать данные отца
	void SetFather(Person* father);
	//Задать название детского сада/школы
	void SetSchool(string school);
	//Получить данные матери
	Person* GetMother();
	//Получить данные отца
	Person* GetFather();
	//Получить название детского сада/школы
	string GetSchool();
	//Задать случайные значения для Child
	static Child* CreateRandomChild();
	//Вывод данных
	virtual string GetDescription();
};