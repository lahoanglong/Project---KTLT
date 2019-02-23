#ifndef _MEATBALL_H_
#define _CRT_SECURE_NO_WARNINGS
#define _MEATBALL_H_

#include "iostream"
#include "fstream"
#include "conio.h"
#include "vector"
using namespace std;

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

	protected:
		//vector chứa các thành viên 1 lớp
		vector<Student>all_classes;
};

class admin : public Class
{
	private:

		//array chứa được 6 lớp :v
		Class a[7];

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