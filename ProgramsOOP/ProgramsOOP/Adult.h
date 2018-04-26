//TODO: убрать слово Class из названия файла
//ИСПРАВЛЕНО.
#pragma once
#include "Person.h"

class Adult : public Person
{
private:
	//TODO: присвоить значение null по умолчанию
	//ИСПРАВЛЕНО.
	Person* _marriedOn = NULL;
	string _workPlace;
public:
	Adult() {};
	Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace);

	void SetMarriedOn(Person* marriedOn);
	void SetWorkPlace(string workPlace);
	Person* GetMarriedOn();
	string GetWorkPlace();
	
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
	static Adult* CreateRandomAdult();
};