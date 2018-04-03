#pragma once

void ShowString(char *string);
//Создание строки
char* CreateString();
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
char* ToUppercase(char* string);
//Преобразование в нижний регистр
char* ToLowercase(char* string);
void SplitFilename(char* source, char* path, char* name, char* extension);
//Замена таб на пробелы
char* ReplaceTabsOnSpaces(char* string, int sizeTabs);
//Заменапробелов на таб
char* ReplaceSpacesOnTabs(char* string, int sizeSpaces);
bool NeedTab(char* string, int i, int sizeSpaces);
void  ErrorOutput();
void CopyString(char* string1, char* string2);