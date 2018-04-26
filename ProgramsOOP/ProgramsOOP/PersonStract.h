#pragma once

//Перечисление пола Person
enum Sex {Female = 0, Male = 1};

//Структура Person
struct Person
{
	char Surname[40];
	char Name[20];
	Sex Sex;
	int Age;
};

//Ввод данных о человеке
Person ReadPerson();
//Вывод данных человека на экран
void ShowPerson(Person person);
