#include "Abiturient.h"

Abiturient::Abiturient()
{
	this->name = "Artem";
	this->surname = "Sakhno";
}

Abiturient::Abiturient(string name, string surname)
{
	this->name = name;
	this->surname = surname;
}

Abiturient::Abiturient(const Abiturient& other)
{
	this->name = other.name;
	this->surname = other.surname;
}

void Abiturient::setName(string name)
{
	this->name = name;
}

string Abiturient::getAbitName()
{
	return this->name;
}

void Abiturient::setSurname(string surname)
{
	this->name = name;
}

string Abiturient::getAbitSurname()
{
	return this->surname;
}

// з вектором
void Abiturient::RW(vector <Abiturient>& abitWrite)
{
	ofstream a_write("ABIT_INFO.TXT", ofstream::app);
	

	vector <Abiturient>::iterator itr;

	try
	{
		if (abitWrite.empty())
		{
			throw "There is nothing to write into file";
		}
		else
		{
			for (itr = abitWrite.begin(); itr != abitWrite.end(); itr++)
			{
				a_write << *itr;
			}
		}

	}
	catch (string warning)
	{
		cout << warning << endl;
		return;
	}
	//try
	//{
	//	if (this->getAbitName() == "" || this->getAbitSurname() == "")
	//	{
	//		throw "You haven't surname or name";
	//	}
	//	a_write << this->getAbitName() << " " << this->getAbitSurname() << endl;
	//}
	//catch (string warning)
	//{
	//	cout << warning << endl;
	//	return;
	//}

	a_write.close();
}

void Abiturient::RD()
{
	ifstream a_read("ABIT_INFO.TXT");

	if (a_read.is_open())
	{
		a_read >> this->name >> this->surname;
	}
	else
	{
		cout << "Problem with ABIT_INFO.TXT" << endl;
		return;
	}
	a_read.close();
}

Abiturient& Abiturient::operator++(int value)
{
	Abiturient temp(*this);

	this->number++;
	// TODO: insert return statement here
	return temp;
}

Abiturient& Abiturient::operator++()
{
	this->number++;
	// TODO: insert return statement here
	return *this;
}

Abiturient& Abiturient::operator--(int value)
{
	Abiturient temp(*this);

	this->number--;
	// TODO: insert return statement here
	return temp;
}

Abiturient& Abiturient::operator--()
{
	this->number--;
	// TODO: insert return statement here
	return *this;
}

Abiturient Abiturient::operator+(const Abiturient& other)
{
	Abiturient temp;

	temp.name = this->name + other.name;
	temp.surname = this->surname + other.surname;
	temp.number = this->number + other.number;

	return Abiturient(temp);
}

Abiturient Abiturient::operator-(const Abiturient& other)
{
	Abiturient temp;

	temp.number = this->number - other.number;
	return Abiturient(temp);
}

Abiturient Abiturient::operator*(const Abiturient& other)
{
	Abiturient temp;

	temp.number = this->number * other.number;

	return Abiturient(temp);
}

Abiturient& Abiturient::operator=(const Abiturient& other)
{
	this->number = other.number;
	// TODO: insert return statement here
	return *this;
}

Abiturient& Abiturient::operator+=(const Abiturient& other)
{
	this->number += other.number;
	// TODO: insert return statement here
	return *this;
}

Abiturient& Abiturient::operator-=(const Abiturient& other)
{
	this->number -= other.number;
	// TODO: insert return statement here
	return *this;
}

Abiturient& Abiturient::operator*=(const Abiturient& other)
{
	this->number *= other.number;
	// TODO: insert return statement here
	return *this;
}

void Abiturient::DoWork()
{
	setlocale(LC_ALL, "Ukrainian");

	cout << "Студенти йдуть здавати вступні іспити" << endl;
}
