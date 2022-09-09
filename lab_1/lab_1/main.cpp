#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct TList
{
	string surname; 
	string name;
	int kurs;
	string group;
	int resOfFirstSubject;
	int resOfSecondSubject;
	int resOfThirdSubject;
	int resOfFourthSubject;
};
typedef struct TList list;

struct ListCar
{
	string surname;
	string mark;
	string number;
};
typedef struct ListCar car;

// заповнення інформації для INFO.DAT
void InformationAboutStudent(list* student, int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << "Enter surname: ";
		cin >> student[i].surname;

		cout << "Enter name: ";
		cin >> student[i].name;

		cout << "Enter kurs: ";
		cin >> student[i].kurs;

		cout << "Enter group: ";
		cin >> student[i].group;

		cout << "Enter result of first subject: ";
		cin >> student[i].resOfFirstSubject;

		cout << "Enter result of second subject: ";
		cin >> student[i].resOfSecondSubject;

		cout << "Enter result of third subject: ";
		cin >> student[i].resOfThirdSubject;

		cout << "Enter result of fourth subject: ";
		cin >> student[i].resOfFourthSubject;

		cout << endl;
	}
}

// 1.1
void RW(list* student, int numberOfStudents)
{
	fstream file_write("INFO.DAT", fstream::binary);

	for (int i = 0; i < numberOfStudents; i++)
	{
		file_write.write((char*)&student[i], sizeof(list));
	}
	file_write.close();
}

// 1.2
void RD(list* student, int numberOfStudents)
{
	ifstream file_read("INFO.DAT", ifstream::binary);

	if (file_read.is_open())
	{
		for (int i = 0; i < numberOfStudents; i++)
		{
			file_read.read((char*)&student[i], sizeof(list));
		}
	}
	file_read.close();
}

void SortListBubbleMethod(list* student, int number)
{
	for (int i = 0; i < number - 1; i++)
	{
		for (int j = 0; j < number - i - 1; j++)
		{
			if (student[j].resOfFirstSubject + student[j].resOfSecondSubject
				+ student[j].resOfThirdSubject + student[j].resOfFourthSubject <
				student[j + 1].resOfFirstSubject + student[j + 1].resOfSecondSubject
				+ student[j + 1].resOfThirdSubject + student[j + 1].resOfFourthSubject)
			{
				swap(student[j], student[j + 1]);
			}
		}
	}
}

// 1.1, 1.2
void ShowList(list* student, int number)
{
	cout << "=============== Sorted list ===============" << endl << endl;
	for (int i = 0; i < number; i++)
	{
		cout << "Surname: " << student[i].surname << endl;
		cout << "Name: " << student[i].name << endl;
		cout << "Kurs: " << student[i].kurs << endl;
		cout << "Group: " << student[i].group << endl;
		cout << "Result of first subject: " << student[i].resOfFirstSubject << endl;
		cout << "Result of second subject: " << student[i].resOfSecondSubject << endl;
		cout << "Result of third subject: " << student[i].resOfThirdSubject << endl;
		cout << "Result of fourth subject: " << student[i].resOfFourthSubject << endl << endl;
	}
}



// 1.3
void RW(car* bus, int number)
{
	ofstream file_write("INFO.TXT");

	for (int i = 0; i < number; i++)
	{
		file_write << bus[i].surname << " " << bus[i].mark << " "
		<< bus[i].number << endl;
	}
	file_write.close();
}

void RD(car* bus, int number)
{
	ifstream file_read("INFO.TXT");

	if (file_read.is_open())
	{
		for (int i = 0; i < number; i++)
		{
			file_read >> bus[i].surname >> bus[i].mark >> bus[i].number;
		}
	}
	else
	{
		cout << "Error" << endl;
		return;
	}
	file_read.close();
}

// перевірка bus[i].number на "12-13"
void CoutOnlySurname(car* bus, int number)
{
	int count = 0;

	for (int i = 0; i < number; i++)
	{
		if (bus[i].number.find("12-13") != string::npos)
		{
			cout << bus[i].surname << endl;
		}
		else
		{
			count++;
		}
		if (count == number)
		{
			cout << "There is no one number with 12-13!" << endl;
			return;
		}
	}
}

// заповнення інформації для INFO.TXT
void FillList(car* bus, int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << "Enter surname: ";
		cin >> bus[i].surname;

		cout << "Enter mark of auto: ";
		cin >> bus[i].mark;

		cout << "Enter number of auto: ";
		cin >> bus[i].number;

		cout << endl;
	}
}

int main()
{
	int MAX;

	cout << "Enter number of students: ";
	cin >> MAX;
	cout << endl;

	list* student = new list[MAX];
	car* bus = new car[MAX];

	if (MAX <= 0)
	{
		cout << "Enter correct number of student!" << endl;
		return 0;
	}
	else
	{
		//InformationAboutStudent(student, MAX);
		//RW(student, MAX);
		//RD(student, MAX);
		//SortListBubbleMethod(student, MAX);
		//ShowList(student, MAX);

		FillList(bus, MAX);
		RW(bus, MAX);
		RD(bus, MAX);
		CoutOnlySurname(bus, MAX);
	}

	delete[] student;
	delete[] bus;

	return 0;
}