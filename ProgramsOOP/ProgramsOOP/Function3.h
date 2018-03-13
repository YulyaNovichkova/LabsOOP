#pragma once

int Menu3();
void ShowString(char *string);
//Определение длины строки
void CreateLength();
//Объединение двух строк
int GetLength(char* string);
char* Concatenate(char* string1, char* string2);
//Поиск подстрок
char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);
//Преобразование в верхний регистр
char* Uppercase(char* string);
//Преобразование в нижний регистр
char* Lowercase(char* string);
void SplitFilename(char* source, char* path, char* name, char* extension);
char* ReplaceTabsOnSpaces(char* string);
char* ReplaceSpacesOnTabs(char* string);


struct Person
{
	char Surname[40];
	char Name[20];
	char Sex[1];
	int Age;
	char Status[20];
};
//Ввод данных о человеке
Person ReadPerson();
//Вывод данных человека на экран
void PrintPerson(Person person);