#pragma once
//TODO: убрать слово Class из названия файла
#include <iostream>
#include <string>

using namespace std;

//TODO: перечисление в отдельный файл
//TODO: каждое значение перечисления на новой строке, фигурные скобки на новой строке
enum Sex { Female = 0, Male = 1 };

class Person 
{
protected:
	string _surname;
	string _name;
	Sex _sex;
	unsigned int _age;
public:
	Person() {}; //TODO: между функциями надо одну пустую строку
    //TODO: реализацию в cpp-файл
	//TODO: комментарии к функции
	Person(string surname, string name, enum Sex sex, int age)
	{
		SetSurname(surname);
		SetName(name);
		SetSex(sex);
		SetAge(age);
	};
	//TODO: реализацию в cpp-файл
	//TODO: комментарии к функции
	void SetSurname(string surname)
	{
		_surname = surname;
	} //TODO: между функциями надо одну пустую строку
	  //TODO: реализацию в cpp-файл
	  //TODO: комментарии к функции
	void SetName(string name)
	{
		_name = name;
	} //TODO: между функциями надо одну пустую строку
	  //TODO: реализацию в cpp-файл
	  //TODO: комментарии к функции
	void SetSex(enum Sex sex)
	{
		_sex = sex;
	} //TODO: между функциями надо одну пустую строку
	  //TODO: реализацию в cpp-файл
	  //TODO: комментарии к функции
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
	//TODO: реализацию в cpp-файл
	//TODO: комментарии к функции
	string GetSurname()
	{
		return _surname;
	} //TODO: между функциями надо одну пустую строку
	  //TODO: реализацию в cpp-файл
	  //TODO: комментарии к функции
	string GetName()
	{
		return _name;
	} //TODO: между функциями надо одну пустую строку
	  //TODO: реализацию в cpp-файл
	  //TODO: комментарии к функции
	int GetSex()
	{
		return _sex;
	} //TODO: между функциями надо одну пустую строку
	  //TODO: реализацию в cpp-файл
	  //TODO: комментарии к функции
	int GetAge()
	{
		return _age;
	} //TODO: между функциями надо одну пустую строку
	  //TODO: комментарии к функции
	static Person* CreateRandomPerson();
	//TODO: комментарии к функции
	static Person* Read();
	//TODO: комментарии к функции
	static void ShowPerson(Person* person);
	//virtual char* GetDescription();
};



