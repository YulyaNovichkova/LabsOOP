#include "Person.h"
#include "Sex.h"
#include <ctime>

//TODO: реализацию в cpp-файл
//ИСПРАВЛЕНО.
//TODO: комментарии к функции
//Исправлено.

//Конструктор класса Person
Person::Person(string surname, string name, enum Sex sex, int age)
{
	SetSurname(surname);
	SetName(name);
	SetSex(sex);
	SetAge(age);
};

//Задать фамилию для Person
void Person::SetSurname(string surname)
{
	_surname = surname;
} 

//Задать имя для Person
void Person::SetName(string name)
{
	_name = name;
} 

//Задать пол для Person
void Person::SetSex(enum Sex sex)
{
	_sex = sex;
} 

//Задать возраст для Person
void Person::SetAge(unsigned int age)
{
	_age = age;
}

//Получить фамилию Person
string Person::GetSurname()
{
	return _surname;
} 

//Получить имя Person
string Person::GetName()
{
	return _name;
} 

//Получить пол Person
int Person::GetSex()
{
	return _sex;
} 

//Получить возраст Person
int Person::GetAge()
{
	return _age;
} 

//Ввести данные о человеке
Person* Person::Read()
{
	string surname;
	string name;
	int age;
	enum Sex sex;

	cout << "Enter surname: ";
	cin >> surname;
	cout << "Enter name: ";
	cin >> name;
	cout << "Sex: Enter '0' for female, '1' for male: ";
	int numberSex;
	cin >> numberSex;
	switch (numberSex)
	{
		case 0:
		{
			sex = Female;
			break;
		}
		case 1:
		{
			sex = Male;
			break;
		}
	}
	do
	{
		cout << "Enter the age: ";
		cin >> age;
		if (age < 0)
		{
			cout << "An invalid value was entered!" << endl;
		}
	} while (age < 0);
	Person* person = new Person(surname, name, sex, age);
	return person;
}

//Заполнение Person случайными данными
Person* Person::CreateRandomPerson()
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
	Person* person = new Person(surname,name,sex,age);
	return	person;
}

//TODO: лучше вывод Person в одну строку - так удобнее тестировать/отлаживать. Да и пользователю удобнее
//Вывод данных о человеке
//Сделано.
void Person::ShowPerson(Person* person)
{
	cout << person->GetSurname() << " "
		<< person->GetName() << ", "
		<< person->GetAge() << " years old, ";
	switch (person->GetSex())
	{
	case 0:
		cout << "female." << endl;
		break;
	case 1:
		cout << "male." << endl;
		break;
	default:
		break;
	}
}

//Перечисление всех данных о Person
string Person::GetDescription()
{
	string descriptionPerson = _surname + " " + _name + ", " + to_string(_age) + " years old, ";
	if (_sex == Male)
	{
		descriptionPerson = descriptionPerson + "male. ";
	}
	else
	{
		descriptionPerson = descriptionPerson + "female. ";
	}

	return descriptionPerson;
}