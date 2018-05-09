#include <iostream>
#include "Person.h"
#include "PersonList.h"
#include "List.h"

using namespace std;

int Menu7()
{
	char key;
	PersonList list;

	do
	{
		cout << "\t Choose next step:" << endl << endl << endl
			<< "1. Demonstrate on double;" << endl
			<< "2. Demonstrate on *Person;" << endl
			<< "3. Demonstrate on double[5];" << endl
			<< "4. Demonstrate on List<double>;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case '1':
		{
			List<double> list;

			cout << "Adding 5 elements." << endl;
			list.Add(-0.42);
			list.Add(1.5);
			list.Add(6.66);
			list.Add(-111.11);
			list.Add(84.9876);
			list.Show();
			
			cout << "Removing 3 elements." << endl;
			list.RemoveAt(2);
			list.Show();
			break;
		}
		case '2':
		{
			List<Person*> list;

			cout << "Adding 5 elements." << endl;
			list.Add(Person::CreateRandomPerson());
			list.Add(Person::CreateRandomPerson());
			list.Add(Person::CreateRandomPerson());
			list.Add(Person::CreateRandomPerson());
			list.Add(Person::CreateRandomPerson());
			list.Show();

			cout << "Removing 3 elements." << endl;
			list.RemoveAt(2);
			list.Show();
			break;
		}

		case '3':
		{
			List<double*> list;

			cout << "Adding 5 elements." << endl;
			double array1[5] = { -10.98, -9.87, -8.76, -7.65, -6.54 };
			double array2[5] = { 0.12, 1.23, 2.34, 3.45, 4.56 };
			double array3[5] = { -21.03, -2.28, 0.001, 2.28, 21.03 };
			double array4[5] = { -1.0, 0.0, 1.0, 2.0, 3.0 };
			double array5[5] = { 9.99, 8.88, 7.77, 6.66, 5.55 };

			list.Add(array1);
			list.Add(array2);
			list.Add(array3);
			list.Add(array4);
			list.Add(array5);
			list.Show();

			cout << "Removing 3 elements." << endl;
			list.RemoveAt(2);
			list.Show();
			break;
		}

		case '4':
		{
			List<List<double>*> list;

			cout << "Adding 5 elements." << endl;
			List<double> list1;
			list1.Add(-1.1);
			list1.Add(-2.2);
			list1.Add(-3.3);
			list1.Add(-4.4);
			list1.Add(-5.5);

			List<double> list2;
			list2.Add(11.11);
			list2.Add(22.22);
			list2.Add(33.33);
			list2.Add(44.44);
			list2.Add(55.55);

			List<double> list3;
			list3.Add(-111.111);
			list3.Add(-222.222);
			list3.Add(-333.333);
			list3.Add(-444.444);
			list3.Add(-555.555);

			List<double> list4;
			list4.Add(-28.77);
			list4.Add(28.77);
			list4.Add(-28.77);
			list4.Add(28.77);
			list4.Add(-28.77);

			List<double> list5;
			list5.Add(100.100);
			list5.Add(-100.100);
			list5.Add(100.100);
			list5.Add(-100.100);
			list5.Add(100.100);

			list.Add(&list1);
			list.Add(&list2);
			list.Add(&list3);
			list.Add(&list4);
			list.Add(&list5);

			list.Show();

			cout << "Removing 3 elements." << endl;
			list.RemoveAt(2);
			list.Show();
			break;
		}

		case '0':
			cout << " Welcome back." << endl;
			break;
		default:
			cout << " Mistake, try again." << endl;
			break;
		}
	} while (key != '0');
	int k = atoi(&key);
	return(k);
}

//Перегрузка оператора "<<" (добавления) для *Person
ostream& operator << (ostream& s, Person* p)
{
	s << p->GetDescription();
	return s;
}

//Перегрузка оператора "<<" (добавления) для double[5]
ostream& operator << (ostream& s, double* d)
{
	for (int i = 0; i < 5; i++)
	{
		s << d[i] << " ";
	}
	return s;
}

void LaunchTask7()
{
	int key = Menu7();
	cout << key << endl;
	system("pause");
}