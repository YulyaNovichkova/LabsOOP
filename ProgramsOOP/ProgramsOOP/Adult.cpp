#include "Adult.h"
#include "Person.h"
#include <ctime>

//Конструктор класса Adult
Adult::Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace) : Person(surname, name, sex, age)
{
	SetMarriedOn(marriedOn);
	SetWorkPlace(workPlace);
}

//Задать паспортные данные 
void Adult::SetMarriedOn(Person* marriedOn)
{
	_marriedOn = marriedOn;
} 

 //Задать место работы
void Adult::SetWorkPlace(string workPlace)
{
	_workPlace = workPlace;
}

//Получить паспортные данные
Person* Adult::GetMarriedOn()
{
	return _marriedOn;
}

 //Получить место работы
string Adult::GetWorkPlace()
{
	return _workPlace;
}

Adult* Adult::CreateRandomAdult()
{
	srand(time(NULL));
	//Профессия
	string tempWorkPlace[] = { "Attorney", "Agronomist", "Actor", "Architect", "Mechanic",
		"Accountant", "Banker", "Librarian", "Doctor", "Veterinarian",
		"Driver", "Pilot", "Cashier", "Lawyer", "Economist" };
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

	string workPlace = tempWorkPlace[rand() % 15];
	string surname;
	string name;
	enum Sex sex;
	int age = 18 + rand() % 100;
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
	Person* marriedOn = Person::CreateRandomPerson();

	Adult* adult = new Adult(surname, name, sex, age, marriedOn, workPlace);
	return	adult;
}

//Вывод данных
string Adult::GetDescription() 
{
	string descriptionPerson = _surname + " " + _name + ", " + to_string(_age) + " years old";

	if (_sex == Male)
	{
		descriptionPerson = descriptionPerson + ", " + "male,";
	}
	else
	{
		descriptionPerson = descriptionPerson + ", " + "female,";
	}

	if (_marriedOn != NULL)
	{
		descriptionPerson = descriptionPerson + " married on " + _marriedOn->GetSurname() + " " + _marriedOn->GetName() + ", " + "works as a " + _workPlace;
	}
	else
	{
		descriptionPerson = descriptionPerson + " single, " + _workPlace;
	}
	return descriptionPerson;
}