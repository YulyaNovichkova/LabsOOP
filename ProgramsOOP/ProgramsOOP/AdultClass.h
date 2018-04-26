//TODO: убрать слово Class из названия файла
#pragma once
#include "Person.h"

class Adult : public Person
{
private:
	//TODO: присвоить значение null по умолчанию
	Person* _marriedOn;
	string _workPlace;
public:
	Adult() {};
	Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace) : Person (surname, name, sex, age)
	{
	SetMarriedOn(marriedOn);
	SetWorkPlace(workPlace);
	}
	
	//TODO: унаследованная от Person реализация. Зачем её здесь дублировать?
	void SetAge(unsigned int age)
	{
		if (age >= 18)
		{
			_age = age;
		}
		else
		{
			//TODO: правильно ли, что у взрослого возраст меньше 18? Может, логичнее бросать исключение?
			_age = 18;
		}
	}
	//TODO: унаследованная от Person реализация. Зачем её здесь дублировать?
	int GetAge()
	{
		return _age;
	}

	//TODO: комментарии к функции
	//TODO: реализацию в cpp-файл

	void SetMarriedOn(Person* marriedOn)
	{
		_marriedOn = marriedOn;
	} //TODO: пустая строка между функциями
	  //TODO: реализацию в cpp-файл
	  //TODO: комментарии к функции
	void SetWorkPlace(string workPlace)
	{
		_workPlace = workPlace;
	}
	//TODO: реализацию в cpp-файл
	//TODO: комментарии к функции
	Person* GetMarriedOn()
	{
		return _marriedOn;
	}//TODO: пустая строка между функциями
	 //TODO: реализацию в cpp-файл
	 //TODO: комментарии к функции
	string GetWorkPlace()
	{
		return _workPlace;
	}
	//TODO: комментарии к функции
	static Adult* CreateRandomAdult();
};