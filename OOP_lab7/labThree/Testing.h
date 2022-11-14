#pragma once

#include "Abiturient.h"
#include "Teacher.h"

#include <iostream>
using namespace std;

class Testing
{
private:
	Abiturient* abit;
	Teacher* teacher;
public:
	void TestAbit(Abiturient abit);
	void TestTeacher(Teacher teacher);
};