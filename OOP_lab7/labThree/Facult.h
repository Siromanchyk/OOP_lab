#pragma once

#include "Abiturient.h"
#include "Teacher.h"
#include <iostream>
#include <deque>
#include <stack>
using namespace std;

class Facult
{
private:
	Abiturient* abits;
	static int numberOfAbits;
	Teacher* teachers;
	int numberOfTeachers;
	string name;
public:
	Facult();
	Facult(string name);

	void setFacultName(string name);
	string getFacultName();

	void RW(Abiturient abits, Teacher teacher);
	void RW(Abiturient* abits, Teacher* teachers);

	void addToFacult(Abiturient* abits, Teacher* teachers, int numberT);
	void showFacult();

	void addToFacult(Abiturient* abits, Teacher* teachers, int teacherNumber);

	Abiturient operator [] (int index);

	template <typename T> int search(T* arr, int arrSize, T key);

	static void showNumberOfAbits();
};