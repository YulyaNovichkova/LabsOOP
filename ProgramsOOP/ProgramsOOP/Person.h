#pragma once
//TODO: убрать слово Class из названия файла
//ИСПРАВЛЕНО.
#include <iostream>
#include <string>

using namespace std;

//TODO: перечисление в отдельный файл
//TODO: каждое значение перечисления на новой строке, фигурные скобки на новой строке
//ИСПРАВЛЕНО.
enum Sex 
{ 
	Female = 0, 
	Male = 1 
};

class Person 
{
protected:
	string _surname;
	string _name;
	Sex _sex;
	unsigned int _age;
public:
	Person() {}; 
	Person(string surname, string name, enum Sex sex, int age);
	void SetSurname(string surname);
	void SetName(string name);
	void SetSex(enum Sex sex);
	void SetAge(unsigned int age);

	string GetSurname();
	string GetName();
	int GetSex();
	int GetAge();
	 //TODO: комментарии к функции
	static Person* CreateRandomPerson();
	//TODO: комментарии к функции
	static Person* Read();
	//TODO: комментарии к функции
	static void ShowPerson(Person* person);
	virtual char* GetDescription();
};



