#include "Child.h"
#include "Person.h"
#include <ctime>

//TODO: реализацию в cpp
//ИСПРАВЛЕНО.
Child::Child(string surname, string name, enum Sex sex, int age, Person* mother, Person* father, string school) : Person(surname, name, sex, age)
{
	SetMother(mother);
	SetFather(father);
	SetSchool(school);
}

 //TODO: комментарии к функции
void Child::SetMother(Person* mother)
{
	_mother = mother;
}

 //TODO: комментарии к функции
void Child::SetFather(Person* father)
{
	_father = father;
}

 //TODO: комментарии к функции
void Child::SetSchool(string school)
{
	_school = school;
}

 //TODO: комментарии к функции
Person* Child::GetMother()
{
	return _mother;
}

 //TODO: комментарии к функции
Person* Child::GetFather()
{
	return _father;
}

 //TODO: комментарии к функции
string Child::GetSchool()
{
	return _school;
}

Child* Child::CreateRandomChild()
{
	srand(time(NULL));
	//Женщины
	const char* femaleSurname[] = { "Novichkova", "Ovsyannikova", "Belova", "Petuxova", "Shilnikova",
		"Nagih", "Bespalova", "Lebedeva", "Alexseeva", "Koreshkova",
		"Karipova", "Kislova", "Smirnova", "Proxorova", "Maksova" };

	const char* femaleName[] = { "Yulya", "Nastya", "Elena", "Irina", "Kristina",
		"Alisa", "Inna", "Ekaterina", "Dasha", "Masha",
		"Olga", "Evgeniya", "Anna", "Liliya", "Yana" };
	//Мужчины
	const char* maleSurname[] = { "Ivanov", "Petrov", "Sidorov", "Trofimov", "Vakulin",
		"Kolesnik", "Solovov", "Kalinin", "Kalachev", "Ermolaev",
		"Tihonov", "Brodt", "Dvornikov", "Pushkarev", "Mulenok" };

	const char* maleName[] = { "Dmitriy", "Pasha", "Aleksandr", "Sergey", "Ilya",
		"Yaroslav", "Aleksey", "Kirill", "Nikolay", "Ivan",
		"Vladislav", "Slava", "Georgiy", "Evgeniy", "Vitaliy" };

	string surname;
	string name;
	enum Sex sex;
	int age = rand() % 100;
	int randomSex = Sex(rand() % 2);
	if (randomSex == 0)
	{
		sex = Female;
		surname = femaleSurname[rand() % 15];
		name = femaleName[rand() % 15];
	}
	else
	{
		sex = Male;
		surname = maleSurname[rand() % 15];
		name = maleName[rand() % 15];
	}
	Person* mother = Person::CreateRandomPerson();
	Person* father = Person::CreateRandomPerson();
	string school;
	Child* child = new Child(surname, name, sex, age, mother, father, school);
	return	child;
}