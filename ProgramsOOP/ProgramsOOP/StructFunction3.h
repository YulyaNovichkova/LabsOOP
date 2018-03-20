#pragma once

enum Gender {female = 0, male = 1};

struct Person
{
	char Surname[40];
	char Name[20];
	Gender Sex;
	int Age;
	char Status[20];
};

//Ввод данных о человеке
Person ReadPerson();
//Вывод данных человека на экран
void PrintPerson(Person *person);
