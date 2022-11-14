#pragma once
#include <iostream>
#include "Abiturient.h"
using namespace std;

class ExtramurallStudent : public Abiturient
{
private:
	string name;
	string surname;
public:
	ExtramurallStudent(Abiturient abit);
	void DoWork();
};