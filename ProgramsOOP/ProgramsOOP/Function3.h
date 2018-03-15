#pragma once

void ShowString(char *string);
char* CreateLength();
//Определение длины строки
int GetLength(char* string);
//Объединение двух строк
char* Concatenate(char* string1, char* string2);
//Поиск подстрок
char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);
//Нахождение подстроки теста
void FindSubstringTest(char* string, char* substring, char testSubstring[20]);
//Преобразование в верхний регистр
char* Uppercase(char* string);
//Преобразование в нижний регистр
char* Lowercase(char* string);
void SplitFilename(char* source, char* path, char* name, char* extension);
//Разбиение строки
int GetSourcePart(char* source, char* partString, char symbol, const char partName[30], int size);
//Отзеркаливание строки
char* RevertString(char* string, int size);
//Замена таб на пробелы
char* ReplaceTabsOnSpaces(char* string);
// Замена пробелов на таб
char* ReplaceSpacesOnTabs(char* string);