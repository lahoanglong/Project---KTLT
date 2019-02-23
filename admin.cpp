#include "meatball.h"

//các hàm cho môn học
Courses::Courses()
{
}

Courses::~Courses()
{
}

//các hàm cho lớp
Class::Class()
{
}

Class::~Class()
{
}

//các hàm quản lý cho admin
void admin::load_student()
{
	ifstream fin;
	fin.open("clc6.csv");
	
	fin.getline(head,100);
	int i = 0;
	for (; ; i++)
	{
		fin >> a[i].number;
		if (a[i].number < 0)
			break;
		fin.get();
		fin >> a[i].student_ID;
		fin.get();
		fin.getline(a[i].lastname, 100, ',');
		fin.getline(a[i].firstname, 100, ',');
		fin.getline(a[i].gender, 100, ',');
		fin >> a[i].DoB.day;
		fin.get();
		fin >> a[i].DoB.month;
		fin.get();
		fin >> a[i].DoB.year;
	}
	num = i;
	fin.close();
}

void admin::save_student()
{
	ofstream fout;
	fout.open("test.csv");
	fout << head << endl;
	for (int i = 0;i < num;i++)
	{
		fout << a[i].number << "," << a[i].student_ID << "," << a[i].lastname << "," << a[i].firstname << "," << a[i].gender << "," << a[i].DoB.day << "-" << a[i].DoB.month << "-" << a[i].DoB.year << endl;
	}
	fout.close();
}