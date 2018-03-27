#pragma once
//TODO: переименовать файл в string - чтобы название отражало содержащиеся в нём функции, а не просто нумеровало лабораторные работы
//ИСПРАВЛЕНО.
void ShowString(char *string);

char* CreateString();
//Определение длины строки
int GetLength(char* string);
//Объединение двух строк
char* Concatenate(char* string1, char* string2);
//Поиск подстрок
char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);
//Нахождение подстроки теста
//TODO: Странно, что функция-тест написана только для поиска подстроки. Почему только для неё?
void FindSubstringTest(char* string, char* substring, char testSubstring[20]);
//Преобразование в верхний регистр
char* ToUppercase(char* string);
//Преобразование в нижний регистр
char* ToLowercase(char* string);
void SplitFilename(char* source, char* path, char* name, char* extension);
//Разбиение строки
int GetSourcePart(char* source, char* partString, char symbol, const char partName[30], int size);
//Отзеркаливание строки
char* RevertString(char* string, int size);
//Замена таб на пробелы
char* ReplaceTabsOnSpaces(char* string, int sizeTabs);
//Заменапробелов на таб
char* ReplaceSpacesOnTabs(char* string, int sizeSpaces);
bool NeedTab(char* string, int i, int sizeSpaces);
void  ErrorOutput();