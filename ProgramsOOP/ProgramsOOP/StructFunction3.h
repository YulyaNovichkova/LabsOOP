﻿#pragma once
//TODO: Файл переименовать в Person - название файла должно отражать его содержание, а не говорить об абстракным структурах 3 лабораторной
//TODO: элементы перечисления именуются с заглавной буквы
//TODO: Перед всеми функциями, структурами, перечислениями и классами - комментарии обязательны!
enum Gender {female = 0, male = 1};

//TODO: комментарий
struct Person
{
	//TODO: Здесь и в последующих лабораторных уже можно использовать строки string вместо массива char[]
	char Surname[40];
	char Name[20];
	//TODO: Gender - понятие социальное, Sex - биологическое. Но использовать оба слова для именования одной и той же сущности - неправильно.
	Gender Sex;
	int Age;
};

//Ввод данных о человеке
Person ReadPerson();
//TODO: Person в функцию лучше передавать по ссылке - тогда не будет лишнего копирования персоны в памяти
//Вывод данных человека на экран
void ShowPerson(Person person);
