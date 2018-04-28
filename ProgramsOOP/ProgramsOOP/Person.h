﻿#pragma once
//TODO: убрать слово Class из названия файла
//ИСПРАВЛЕНО.
#include <iostream>
#include <string>
#include "Sex.h"

using namespace std;

class Person 
{
protected:
	string _surname;
	string _name;
	Sex _sex;
	unsigned int _age;
public:
	//Конструктор по умолчанию
	Person() {}; 
	//Конструктор класса Person
	Person(string surname, string name, enum Sex sex, int age);
	//Задать фамилию для Person
	void SetSurname(string surname);
	//Задать имя для Person
	void SetName(string name);
	//Задать пол для Person
	void SetSex(enum Sex sex);
	//Задать возраст для Person
	void SetAge(unsigned int age);
	//Получить фамилию Person
	string GetSurname();
	//Получить имя Person
	string GetName();
	//Получить пол Person
	int GetSex();
	//Получить возраст Person
	int GetAge();

	 //TODO: комментарии к функции
	//Исправлено.
	 //Заполнение Person случайными данными
	static Person* CreateRandomPerson();
	//TODO: комментарии к функции
	//Ввести данные о человеке
	static Person* Read();
	//TODO: комментарии к функции
	//Вывод данных о человеке
	static void ShowPerson(Person* person);
	//Перечисление всех данных о Person
	//virtual char* GetDescription();
};



