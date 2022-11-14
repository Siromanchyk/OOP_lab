#include "Testing.h"

void Testing::TestAbit(Abiturient abit)
{
	setlocale(LC_ALL, "Ukrainian");
	cout << abit.getAbitName() << " " << abit.getAbitSurname() << " проходить тестування" << endl;
}

void Testing::TestTeacher(Teacher teacher)
{
	setlocale(LC_ALL, "Ukrainian");
	cout << teacher.getTeacherName() << " " << teacher.getTeacherSurname() << " виставляє оцінки: " << endl;
}