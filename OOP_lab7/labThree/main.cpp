#include "Facult.h"
#include "Testing.h"
#include "Zurnal.h"
#include "ExtramurallStudent.h"
#include <iostream>
#include <ctime>

using namespace std;


//Система Вступні іспити.Абітурієнт реєструється на Факультет, складає 
//Іспити.Викладач виставляє Оцінку.

//Система підраховує середній бал і визначає Абітурієнтів, зарахованих у навчальний заклад.

template <typename T>

void calculateMiddleMark(Abiturient abit, Teacher teacher, Facult f)
{
	srand(time(NULL));
	Testing test;

	test.TestAbit(abit);
	test.TestTeacher(teacher);

	teacher.setFirstRes(rand() % 5 + 1);
	teacher.setSecondRes(rand() % 5 + 1);
	teacher.setThirdRes(rand() % 5 + 1);

	cout << teacher.getFirstRes() << " " << teacher.getSecondRes() << " " << teacher.getThirdRes() << endl;


	if (teacher.getFirstRes() + teacher.getSecondRes() + teacher.getThirdRes() >= 9)
	{
		f.RW(abit, teacher);
	}
}

void calculateMiddleMark(Abiturient* abit, Teacher* teachers, Facult f, int number)
{
	srand(time(NULL));
	Testing test;
	Zurnal zur;

	for (int i = 0; i < number; i++)
	{
		test.TestAbit(abit[i]);
		test.TestTeacher(teachers[i]);

		teachers[i].setFirstRes(rand() % 5 + 1);
		teachers[i].setSecondRes(rand() % 5 + 1);
		teachers[i].setThirdRes(rand() % 5 + 1);

		cout << teachers[i].getFirstRes() << " " << teachers[i].getSecondRes() <<
			" " << teachers[i].getThirdRes() << endl;

		if (teachers[i].getFirstRes() <= 2 || teachers[i].getSecondRes() <= 2 || teachers[i].getThirdRes() <= 2)
		{
			cout << abit[i].getAbitName() << " " << abit[i].getAbitSurname() 
				<< " has 1 or 2" << endl;
			continue;
		}
		if (teachers[i].getFirstRes() + teachers[i].getSecondRes() +
			teachers[i].getThirdRes() >= 9)
		{
			f.RW(abit[i], teachers[i]);
			zur.showMarks(abit[i], teachers[i]);
		}
	}

	f.search(abit, number, abit[5]);
}

void randomNameTeacher(Teacher* teachers, int number)
{
	srand(time(NULL));

	string nameT[5] = {
	"Taras", "Oleksii", "Vasyl", "Andrii", "Oleksandr"
	};

	string surnameT[5] = {
		"Vorona", "Gudz", "Klyn", "Soma", "Loi"
	};

	for (int i = 0; i < 5; i++)
	{
		teachers[i].setName(nameT[rand() % 5]);
		teachers[i].setSurname(surnameT[rand() % 5]);
		teachers[i].RW();
		//teachers[i].RD();
	}
}

void randomNameAbit(Abiturient* abits, int number)
{
	string namesA[5] = {
	"Sasha", "Masha", "Natalia", "Tanya", "Kateryna"
	};

	string surnamesA[5] = {
		"Yablychna", "Koshova", "Perec", "Kacmar", "Sus"
	};

	for (int i = 0; i < 5; i++)
	{
		abits[i].setName(namesA[rand() % 5]);
		abits[i].setSurname(surnamesA[rand() % 5]);
		//abits[i].RW();
		//abits[i].RD();
	}
}


int main()
{
	srand(time(NULL));	 
	Human* h;
	Abiturient* abits = new Abiturient[5];
	randomNameAbit(abits, 5);

	Teacher* teachers = new Teacher[5];
	randomNameTeacher(teachers, 5);

	// 1 спосіб
	h = &abits[0];
	h->DoWork();

	h = &teachers[0];
	h->DoWork();

	// 2 спосіб
	h = &abits[2];
	h->DoWork();
	h = (Human*)&teachers[0];
	h->DoWork();

	// 3 спосіб
	h = &abits[0];
	h->DoWork();
	ExtramurallStudent stud(abits[0]);
	h = (Human*)&abits[0];
	cout << abits[0].getAbitName() << abits[0].getAbitSurname() << " переведений на очну форму" << endl;
	h->DoWork();

	string facultsName[5] = {
	"FIT", "MED", "PED", "ECONOMIC", "Disagn"
	};
	Facult facult(facultsName[rand() % 5]);

	calculateMiddleMark(abits, teachers, facult, 5);

	Facult::showNumberOfAbits();




	return 0;
}