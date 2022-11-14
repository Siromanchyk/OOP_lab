#pragma once

#include "Human.h"
#include "Employee.h"
#include "Position.h"
#include <iostream>
#include <list>
using namespace std;

class Teacher : public Human
{
private:
	class Mark
	{
	private:
		int resOfFirstTest;
		int resOfSecondTest;
		int resOfThirdTest;
	public:
		void setFirstRes(int res);
		void setSecondRes(int res);
		void setThirdRes(int res);

		int getFirstRes();
		int getSecondRes();
		int getThirdRes();
	};
	Mark test;
	Employee employee;
	Position position;
	Teacher* teacher;
public:

	Teacher();
	Teacher(string name, string surname);

	void RW();
	void RW(int number);
	void RD();
	void RD(int number);

	void setPosition(Position position);
	Position getPosition();

	void setEmployee(Employee empl);
	Employee getEmployee();

	void setName(string name) override;
	string getTeacherName();

	void setSurname(string surname) override;
	string getTeacherSurname();

	void setFirstRes(int number);
	void setSecondRes(int number);
	void setThirdRes(int number);

	int getFirstRes();
	int getSecondRes();
	int getThirdRes();

	void addToList(Teacher* teachers, list<Teacher>& teacherList);
	void DoWork() override;
};