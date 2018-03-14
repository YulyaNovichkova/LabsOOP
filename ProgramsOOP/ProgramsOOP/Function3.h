#pragma once

void ShowString(char *string);
//����������� ����� ������
void CreateLength();
//����������� ���� �����
int GetLength(char* string);
char* Concatenate(char* string1, char* string2);
//����� ��������
char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);
//�������������� � ������� �������
char* Uppercase(char* string);
//�������������� � ������ �������
char* Lowercase(char* string);
void SplitFilename(char* source, char* path, char* name, char* extension);
//������ ��� �� �������
char* ReplaceTabsOnSpaces(char* string);
// ������ �������� �� ���
char* ReplaceSpacesOnTabs(char* string);


struct Person
{
	char Surname[40];
	char Name[20];
	char Sex[1];
	int Age;
	char Status[20];
};
//���� ������ � ��������
Person ReadPerson();
//����� ������ �������� �� �����
void PrintPerson(Person person);