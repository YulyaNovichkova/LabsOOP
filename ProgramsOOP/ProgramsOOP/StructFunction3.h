#pragma once
//TODO: Структура должна быть в отдельном файле
//ИСПРАВЛЕНО.
struct Person
{
	char Surname[40];
	char Name[20];
	//TODO: Использование char для пола - плохо. Вспомните последнюю лекцию. Нужен enum.
	char Sex[1];
	int Age;
	char Status[20];
};
//Ввод данных о человеке
Person ReadPerson();
//Вывод данных человека на экран
void PrintPerson(Person person);
