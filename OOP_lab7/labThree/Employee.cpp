#include "Employee.h"

//void Employee::setRectorName(string name)
//{
//	this->rectorName = name;
//}

void Employee::setName(string name)
{
	this->rectorName = name;
}

string Employee::getRectorName()
{
	return string(this->rectorName);
}

void Employee::setSurname(string surname)
{
	this->rectorSurname = surname;
}

void Employee::setWage(double wage)
{
	this->wage = wage;
}

double Employee::getWage()
{
	return this->wage;
}
