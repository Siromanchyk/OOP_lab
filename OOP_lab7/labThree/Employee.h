#pragma once

#include "Human.h";
#include <iostream>
using namespace std;

class Employee : virtual public Human
{
protected:
	string rectorName;
	string rectorSurname;
	double wage;
public:
	void setName(string name) override;
	string getRectorName();

	void setSurname(string surname) override;

	void setWage(double wage);
	double getWage();
};