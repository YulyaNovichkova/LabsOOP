#pragma once

void ShowString(char *string);
char* CreateLength();
//����������� ����� ������
int GetLength(char* string);
//����������� ���� �����
char* Concatenate(char* string1, char* string2);
//����� ��������
char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);
//���������� ��������� �����
void FindSubstringTest(char* string, char* substring, char testSubstring[20]);
//�������������� � ������� �������
char* Uppercase(char* string);
//�������������� � ������ �������
char* Lowercase(char* string);
void SplitFilename(char* source, char* path, char* name, char* extension);
//��������� ������
int GetSourcePart(char* source, char* partString, char symbol, const char partName[30], int size);
//�������������� ������
char* RevertString(char* string, int size);
//������ ��� �� �������
char* ReplaceTabsOnSpaces(char* string);
// ������ �������� �� ���
char* ReplaceSpacesOnTabs(char* string);