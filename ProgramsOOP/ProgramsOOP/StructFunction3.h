#pragma once

enum Gender {female = 0, male = 1};
//TODO: Структура должна быть в отдельном файле
//ИСПРАВЛЕНО.
struct Person
{
	char Surname[40];
	char Name[20];
	//TODO: Использование char для пола - плохо. Вспомните последнюю лекцию. Нужен enum.
	//ИСПРАВЛЕНО.
	Gender Sex;
	int Age;
	char Status[20];
};

//Ввод данных о человеке
Person ReadPerson();
//Вывод данных человека на экран
void PrintPerson(Person *person);
