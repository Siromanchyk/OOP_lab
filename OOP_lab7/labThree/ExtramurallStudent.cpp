#include "ExtramurallStudent.h"

ExtramurallStudent::ExtramurallStudent(Abiturient abit)
{
	this->name = abit.getAbitName();
	this->surname = abit.getAbitSurname();
}

void ExtramurallStudent::DoWork()
{
	setlocale(LC_ALL, "Ukrainian");

	cout << "Перевівся на очну форму навчання" << endl;
}