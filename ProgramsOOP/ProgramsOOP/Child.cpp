#include "Child.h"
#include "Person.h"
#include <ctime>

//Конструктор класса Child
Child::Child(string surname, string name, enum Sex sex, int age, Person* mother, Person* father, string school) : Person(surname, name, sex, age)
{
	SetMother(mother);
	SetFather(father);
	SetSchool(school);
}

 //Задать данные матери
void Child::SetMother(Person* mother)
{
	_mother = mother;
}

 //Задать данные отца
void Child::SetFather(Person* father)
{
	_father = father;
}

 //Задать название детского сада/школы
void Child::SetSchool(string school)
{
	_school = school;
}

 //Получить данные матери
Person* Child::GetMother()
{
	return _mother;
}

 //Получить данные отца
Person* Child::GetFather()
{
	return _father;
}

 //Получить название детского сада/школы
string Child::GetSchool()
{
	return _school;
}

Child* Child::CreateRandomChild()
{
	srand(time(NULL));
	//Женщины
	string femaleSurname[] = { "Novichkova", "Ovsyannikova", "Belova", "Petuxova", "Shilnikova",
		"Nagih", "Bespalova", "Lebedeva", "Alexseeva", "Koreshkova",
		"Karipova", "Kislova", "Smirnova", "Proxorova", "Maksova" };

	string femaleName[] = { "Yulya", "Nastya", "Elena", "Irina", "Kristina",
		"Alisa", "Inna", "Ekaterina", "Dasha", "Masha",
		"Olga", "Evgeniya", "Anna", "Liliya", "Yana" };
	//Мужчины
	string maleSurname[] = { "Ivanov", "Petrov", "Sidorov", "Trofimov", "Vakulin",
		"Kolesnik", "Solovov", "Kalinin", "Kalachev", "Ermolaev",
		"Tihonov", "Brodt", "Dvornikov", "Pushkarev", "Mulenok" };

	string maleName[] = { "Dmitriy", "Pasha", "Aleksandr", "Sergey", "Ilya",
		"Yaroslav", "Aleksey", "Kirill", "Nikolay", "Ivan",
		"Vladislav", "Slava", "Georgiy", "Evgeniy", "Vitaliy" };

	string surname;
	string name;
	enum Sex sex;
	int age = (1 + rand() % 17);
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

//Вывод данных
string Child::GetDescription()
{
	string descriptionPerson = _surname + " " + _name + ", " + to_string(_age) + " years old ";

	if (_sex == Male)
	{
		descriptionPerson = descriptionPerson + ", " + "male, ";
	}
	else
	{
		descriptionPerson = descriptionPerson + ", " + "female, ";
	}

	if (_father != NULL && _mother != NULL)
	{
		descriptionPerson = descriptionPerson + "parents are " + _father->GetSurname() + " " + _father->GetName() + " and " + _mother->GetSurname() + " " + _mother->GetName();
	}
	else if (_mother != NULL)
	{
		descriptionPerson = descriptionPerson + "mother is " + _mother->GetSurname() + _mother->GetName();
	}
	else if (_father != NULL)
	{
		descriptionPerson = descriptionPerson + "father is " + ' ' + _father->GetSurname() + _father->GetName();
	}
	else
	{
		descriptionPerson = descriptionPerson + "Parents are not specified.";
	}

	return descriptionPerson;
}