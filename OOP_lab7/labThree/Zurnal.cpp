#include "Zurnal.h"

#include <iostream>
#include <fstream>
using namespace std;

void Zurnal::showMarks(Abiturient abits, Teacher teachers)
{
	ofstream z_write("ZURNAL.TXT", ofstream::app);

	z_write << abits.getAbitName() << " " << abits.getAbitSurname() << ": " << teachers.getFirstRes() << " " << teachers.getSecondRes() << " " << 
	  teachers.getThirdRes() << endl;

	z_write.close();
}
