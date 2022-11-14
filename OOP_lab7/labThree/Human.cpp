#include "Human.h"

void Human::setName(string name)
{
	this->name = name;
}

string Human::getName()
{
	return string(this->name);
}

void Human::setSurname(string surname)
{
	this->surname = surname;
}

string Human::getSurname()
{
	return string(this->surname);
}

void Human::DoWork()
{
	setlocale(LC_ALL, "Ukrainian");

	cout << "Людий дуть на роботу" << endl;
}
