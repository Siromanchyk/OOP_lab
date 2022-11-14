#pragma once

#include <iostream>
using namespace std;

class Human
{
protected:
	string name;
	string surname;
public:
	virtual void setName(string name) = 0;
	string getName();
	
	virtual void setSurname(string surname) = 0;
	string getSurname();

	virtual void DoWork();
};