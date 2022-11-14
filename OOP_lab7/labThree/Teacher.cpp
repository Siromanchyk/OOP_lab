#include "Teacher.h"
#include <fstream>
using namespace std;

void Teacher::Mark::setFirstRes(int res)
{
	this->resOfFirstTest = res;
}

void Teacher::Mark::setSecondRes(int res)
{
	this->resOfSecondTest = res;
}

void Teacher::Mark::setThirdRes(int res)
{
	this->resOfThirdTest = res;
}

int Teacher::Mark::getFirstRes()
{
	return this->resOfFirstTest;
}

int Teacher::Mark::getSecondRes()
{
	return this->resOfSecondTest;
}

int Teacher::Mark::getThirdRes()
{
	return this->resOfThirdTest;
}

Teacher::Teacher()
{
	this->name = "Vasyl";
	this->surname = "Stulchak";
}

Teacher::Teacher(string name, string surname)
{
	this->name = name;
	this->surname = surname;
}

void Teacher::RW()
{
	ofstream t_write("TEACHER_INFO.TXT", ofstream::app);

	t_write << this->name << " " << this->surname << endl;

	t_write.close();
}

void Teacher::RW(int number)
{
	ofstream t_write("TEACHER_INFO.TXT", ofstream::app);

	for (int i = 0; i < number; i++)
	{
		t_write << this[i].name << " " << this[i].surname << endl;
	}
	t_write.close();
}

void Teacher::RD()
{
	ifstream t_read("TEACHER_INFO.TXT");

	if (t_read.is_open())
	{
		t_read >> this->name >> this->surname;
	}
	else
	{
		cout << "Problem with TEACHER_INFO.TXT" << endl;
		return;
	}
}

void Teacher::RD(int number)
{
	ifstream t_read("TEACHER_INFO.TXT");

	if (t_read.is_open())
	{
		for (int i = 0; i < number; i++)
		{
			t_read >> this[i].name >> this[i].surname;
		}
	}
	else
	{
		cout << "Problem with TEACHER_INFO.TXT" << endl;
		return;
	}
}

void Teacher::setPosition(Position position)
{
	this->position = position;
}

Position Teacher::getPosition()
{
	return Position(this->position);
}

void Teacher::setEmployee(Employee empl)
{
	this->employee = empl;
}

Employee Teacher::getEmployee()
{
	return Employee(this->employee);
}

void Teacher::setName(string name)
{
	this->name = name;
}

string Teacher::getTeacherName()
{
	return this->name;
}

void Teacher::setSurname(string surname)
{
	this->surname = surname;
}

string Teacher::getTeacherSurname()
{
	return this->surname;
}

void Teacher::setFirstRes(int number)
{
	this->test.setFirstRes(number);
}

void Teacher::setSecondRes(int number)
{
	this->test.setSecondRes(number);
}

void Teacher::setThirdRes(int number)
{
	this->test.setThirdRes(number);
}

int Teacher::getFirstRes()
{
	return this->test.getFirstRes();
}

int Teacher::getSecondRes()
{
	return this->test.getSecondRes();
}

int Teacher::getThirdRes()
{
	return this->test.getThirdRes();
}

// з list
void Teacher::addToList(Teacher* teachers, list<Teacher>& teacherList)
{
	for (int i = 0; i < teacherList.size(); i++)
	{
		teacherList.push_back(teachers[i]);
	}
}

void Teacher::DoWork()
{
	setlocale(LC_ALL, "Ukrainian");

	cout << "¬икладач≥ перев≥р€ють роботи" << endl;
}
