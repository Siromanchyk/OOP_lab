#pragma once

#include "Human.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Abiturient : virtual public Human
{
private:
	int number;
	//IdCard iCard;
public:
	Abiturient();
	Abiturient(string name, string surname);
	Abiturient(const Abiturient& other);

	//void setIdCard(IdCard c);
	//IdCard getIdCard();

	void setName(string name) override;
	string getAbitName();
	void setSurname(string surname) override;
	string getAbitSurname();

	void RW(vector <Abiturient>& abitWrite);
	void RD();
	
	Abiturient& operator ++(int value);
	Abiturient& operator ++ ();

	Abiturient& operator --(int value);
	Abiturient& operator -- ();

	Abiturient operator + (const Abiturient& other);
	Abiturient operator - (const Abiturient& other);
	Abiturient operator * (const Abiturient& other);
	Abiturient& operator = (const Abiturient& other);
	Abiturient& operator += (const Abiturient& other);
	Abiturient& operator -= (const Abiturient& other);
	Abiturient& operator *= (const Abiturient& other);

	void DoWork() override;

	friend ostream& operator << (ostream& out, const Abiturient& c)
	{
		out << "(" << c.name << ", " << c.surname << c.number << ")";
		return out;
	}
};