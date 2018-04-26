#include "Adult.h"
#include "Person.h"
#include <ctime>

//TODO: реализацию в cpp
//ИСПРАВДЕНО.
Adult::Adult(string surname, string name, enum Sex sex, int age, Person*  marriedOn, string workPlace) : Person(surname, name, sex, age)
{
	SetMarriedOn(marriedOn);
	SetWorkPlace(workPlace);
}

//TODO: комментарии к функции
void Adult::SetMarriedOn(Person* marriedOn)
{
	_marriedOn = marriedOn;
} 

  //TODO: комментарии к функции
void Adult::SetWorkPlace(string workPlace)
{
	_workPlace = workPlace;
}

//TODO: комментарии к функции
Person* Adult::GetMarriedOn()
{
	return _marriedOn;
}

 //TODO: комментарии к функции
string Adult::GetWorkPlace()
{
	return _workPlace;
}

Adult* Adult::CreateRandomAdult()
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
	Person* marriedOn = Person::CreateRandomPerson();
	string workPlace;
	Adult* adult = new Adult(surname, name, sex, age, marriedOn, workPlace);
	return	adult;
}