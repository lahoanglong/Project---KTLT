#ifndef _MEATBALL_H_
#define _CRT_SECURE_NO_WARNINGS
#define _MEATBALL_H_

#include "iostream"
#include "fstream"
#include "conio.h"
using namespace std;

struct Date
{
	int day, month, year;
};

struct Student
{
	int number;
	int student_ID;
	char lastname[25];
	char firstname[8];
	char gender[7];
	Date DoB;
};

class admin
{
private:
	Student a[40];
	int num;
	char head[100];
public:
	void load_student();
	void save_student();
};

#endif