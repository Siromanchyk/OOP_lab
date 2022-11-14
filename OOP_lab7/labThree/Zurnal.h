#pragma once

#include "Teacher.h"
#include "Abiturient.h"

class Zurnal
{
private:
	Abiturient* abits;
	Teacher* teachers;
public:
	void showMarks(Abiturient abits, Teacher teachers);
};