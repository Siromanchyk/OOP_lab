#include "Facult.h"
#include <iostream>
#include <fstream>

using namespace std;

int Facult::numberOfAbits = 0;

Facult::Facult()
{
	this->name = "FIT";
}

Facult::Facult(string name)
{
	this->name = name;
}

void Facult::setFacultName(string name)
{
	this->name = name;
}

string Facult::getFacultName()
{
	return this->name;
}

void Facult::RW(Abiturient abits, Teacher teacher)
{
	ofstream f_write("FACULT.TXT", ofstream::app);

	f_write << abits.getAbitName() << " " << abits.getAbitSurname() 
		<< teacher.getFirstRes() << " " << teacher.getSecondRes() << " " 
		<< teacher.getThirdRes() << endl;

	numberOfAbits++;

	f_write.close();
}

void Facult::RW(Abiturient* abits, Teacher* teachers)
{
	ofstream f_write("FACULT.TXT", ofstream::app);

	if (this->name != "")
	{
		f_write << "================== " << this->name << " ==================" 
			<< endl;
	}

	f_write << abits->getAbitName() << " " << abits->getAbitSurname() << " "
		<< teachers->getFirstRes() << " " << teachers->getSecondRes()
		<< teachers->getThirdRes() << endl;

	f_write.close();
}

void Facult::showNumberOfAbits()
{
	setlocale(LC_ALL, "Ukrainian");

	cout << "Кількість студентів, які поступили: " << numberOfAbits << endl;
}

void Facult::addToFacult(Abiturient* abits, Teacher* teachers, int numberT)
{
	this->abits = new Abiturient[numberOfAbits];
	for (int i = 0; i < numberOfAbits; i++)
	{
		this->abits[i] = abits[i];
	}

	this->teachers = new Teacher[numberT];
	for (int i = 0; i < numberT; i++)
	{
		this->teachers[i] = teachers[i];
	}
}

void Facult::showFacult()
{
	for (int i = 0; i < numberOfAbits; i++)
	{
		cout << this->abits[i].getAbitName() << " "
			<< this->abits[i].getAbitSurname() << " : " << teachers[i].getFirstRes() << " " << this->teachers[i].getSecondRes() << " " <<
			teachers[i].getThirdRes() << endl;
	}
}

// 
void Facult::addToFacult(Abiturient* abits, Teacher* teachers, int teacherNumber)
{
	deque <Abiturient> abit;

	for (int i = 0; i < numberOfAbits; i++)
	{
		abit.push_front(abits[i]);
	}

	stack <Teacher> teacher;
	for (int i = 0; i < teacherNumber; i++)
	{
		teacher.push(teachers[i]);
	}
}

Abiturient Facult::operator[](int index)
{
	return Abiturient(this->abits[index]);
}

template<typename T>
inline int Facult::search(T* arr, int arrSize, T key)
{
	int low, high, mid;
	low = 0, high = arrSize - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < arr[mid])
		{
			high = mid - 1;
		}
		else if (key > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}