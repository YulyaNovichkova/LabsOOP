#pragma once
//TODO: ��������� ������ ���� � ��������� �����
//����������.
struct Person
{
	char Surname[40];
	char Name[20];
	//TODO: ������������� char ��� ���� - �����. ��������� ��������� ������. ����� enum.
	char Sex[1];
	int Age;
	char Status[20];
};
//���� ������ � ��������
Person ReadPerson();
//����� ������ �������� �� �����
void PrintPerson(Person person);
