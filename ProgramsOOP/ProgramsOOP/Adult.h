#pragma once
#include "Person.h"

class Adult : public Person
{
private:
	Person* _marriedOn = NULL;
	string _workPlace;
public:

	//Конструктор по умолчанию
	Adult() {};
	//Конструктор класса Adult
	Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace);
	//Задать паспортные данные 
	void SetMarriedOn(Person* marriedOn);
	//Задать место работы
	void SetWorkPlace(string workPlace);
	//Получить паспортные данные
	Person* GetMarriedOn();
	//Получить место работы
	string GetWorkPlace();

	//Задать случайные значения для Adult
	static Adult* CreateRandomAdult();
	//Вывод данных
	virtual string GetDescription();
};