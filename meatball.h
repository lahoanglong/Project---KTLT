#ifndef _MEATBALL_H_
#define _CRT_SECURE_NO_WARNINGS
#define _MEATBALL_H_

#include "iostream"
#include "fstream"
#include "conio.h"
#include "vector"
#include "string"
using namespace std;

//khai báo tất cả các hàm
void clear();

//lvl 3 staff only
void classes();
void courses();
void Scoreboard();
void Attendance_list();
//lvl 2
void staff_menu();
void lecturer_menu();
void student_menu();
//lvl 1
void menu();

//cấu trúc thời gian
struct Time
{
	int Hour;
	int Minute;
};

//cấu trúc của 1 ngày
struct Date
{
	int day, month, year;
};

//cấu trúc 1 học sinh
struct Student
{
	int number;
	int student_ID;
	char lastname[25];
	char firstname[8];
	char gender[7];
	Date DoB;
};

//cấu trúc 1 môn học của 1 lớp
struct Course
{
	int No;
	string Course_ID;
	string Course_Name;

	//dùng để truy xuất thời khóa biểu
	string Class;
	string Lecturer_Account;

	//phần này đang thấy kì kì :V
	Date Start_Date;
	Date End_Date;
	Time Start;
	Time End;
};

//Login
struct Account
{
	string _account;
	string _password;
};

class Login
{
private:
	vector <Account> a;
public:
	void Load_password();
	int login_account();
};

//class quản lý 1 môn của 1 lớp
class Courses
{
public:
	Courses();
	~Courses();

private:
	//vector chứa các môn của từng lớp
	vector<Course>all_courses;
};

//class quản lý 1 lớp
class Class
{
public:
	Class();
	~Class();
	bool AddStudent(Student a);
	int GetSize();
	Student GetStudent(int i);
protected:
	//vector chứa các thành viên 1 lớp
	vector<Student>all_classes;
};

class control : public Class
{
private:

	//array 1 khóa
	Class K18[6];

	//Mảng tên file
	char file_name[6][10] = { "CLC1.csv","CLC2.csv","CLC3.csv","CLC4.csv","CLC5.csv","CLC6.csv" };

	//giá trị đếm số lượng sv :V
	int num;

	//lưu header file csv
	char head[100];
public:
	//sửa lại hàm load với save nha :V
	void load_student();
	void save_student();
};

#endif