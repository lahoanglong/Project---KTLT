#include "meatball.h"

//Login
int Login::login_account()
{
	char account_[10], password_[10]; //biến nhập tài khoản
	cout << "Please input your account:";
	cin >> account_;
	for (int i = 0; i < a.size(); i++)
	{
		if (account_ == a.at(i)._account)
		{
			cout << "Please input your password:";
			cin >> password_;
			if (password_ == a.at(i)._account)
			{
				if (_stricmp(account_, "99999") == -1)
				{
					return -1;
				}
				else
				{
					if (_stricmp(account_,"admin") == 0)
					{
						return 0;
					}
				}
				return 1;
			}
		}
	}
}
void Login::Load_password()
{
	ifstream fin;
	fin.open("password.csv");
	Account b; // biến tạm
	char c[5]; //rác
	fin.getline(c, 100);
	while (!fin.eof())
	{
		getline(fin, b._account, ',');
		getline(fin, b._password, '\n');
		a.push_back(b);
	}
	fin.close();
}
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
bool Class::AddStudent(Student a)
{
	bool similar = false;
	for (int i = 0; i < GetSize(); i++)
	{
		if (a.student_ID == GetStudent(i).student_ID)
		{
			similar = true;
		}
	}
	if (similar == false)
		all_classes.push_back(a);
	return similar;
}
int Class::GetSize()
{
	return all_classes.size();
}
Student Class::GetStudent(int i)
{
	return all_classes.at(i);
}
//các hàm quản lý cho admin
void control::load_student()
{
	for (int i = 0;i < 6;i++)
	{
		char * ptr = file_name[i];
		ifstream fin;
		fin.open(ptr);

		fin.getline(head, 100);
		Student a;
		while (!fin.eof())
		{
			fin >> a.number;
			if (a.number < 0)
				break;
			fin.get();
			fin >> a.student_ID;
			fin.get();
			fin.getline(a.lastname, 100, ',');
			fin.getline(a.firstname, 100, ',');
			fin.getline(a.gender, 100, ',');
			fin >> a.DoB.day;
			fin.get();
			fin >> a.DoB.month;
			fin.get();
			fin >> a.DoB.year;
			K18[i].AddStudent(a);
		}
		fin.close();
	}
}

void control::save_student()
{
	ofstream fout;
	fout.open("test.csv");
	fout << head << endl;
	for (int i = 0;i < 7;i++)
	{
		Student a;
		int b = K18[i].GetSize();
		for (int k = 0; k < b; k++)
		{
			a = K18[i].GetStudent(k);
			fout << a.number << "," << a.student_ID << "," << a.lastname << "," << a.firstname << "," << a.gender << "," << a.DoB.day << "-" << a.DoB.month << "-" << a.DoB.year << endl;
		}
	}
	fout.close();
}

//hàm ngoài
void clear()
{
	system("cls");
}

void classes()
{
	int ans;
	cout << "List:\n Import students of a class\n 2. Manually add a new student to a class\n 3. Edit an existing student\n 4. Remove a student\n 5. Move students\n 6. View list of classes\n 7. View list of students in a class\nwhat do you want to do : ";
	cin >> ans;
	switch (ans)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	}
}

void courses()
{
	int ans;
	cout << "List:" << endl;
	cout << " 1. Create / update / delete / view academic years, and semesters" << endl;
	cout << " 2. From a semester, import courses from a csv file" << endl;
	cout << " 3. Manually add a new course" << endl;
	cout << " 4. Edit an existing course" << endl;
	cout << " 5. Remove a course" << endl;
	cout << " 6. Remove a specific student from a course" << endl;
	cout << " 7. Add a specific student to a course" << endl;
	cout << " 8. View list of courses in the current semester" << endl;
	cout << " 9. View list of students of a course" << endl;
	cout << " 10. View attendance list of a course" << endl;
	cout << " 11. Create / update / delete / view all lecturers" << endl;
	cin >> ans;
	switch (ans)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	}
}

void Scoreboard()
{
	int ans;
	cout << "List:\n 1. Search and view scoreboard of a course\n 2. Export a scoreboard to a csv file.";
	cin >> ans;
	switch (ans)
	{
	case 1:
	case 2:
		break;
	}
}

void Attendance_list()
{
	int ans;
	cout << "List:\n 1. Search and view attendance list of a course\n 2. Export a attendance list to a csv file.";
	cin >> ans;
	switch (ans)
	{
	case 1:
		break;
	case 2:
		break;
	}
}

void staff_menu()
{
	int ans;
	cout << "List: \n";
	cout << " 1. class" << endl;
	cout << " 2. course" << endl;
	cout << " 3. Scoreboard" << endl;
	cout << " 4. Attendance_list" << endl;
	cin >> ans;
	switch (ans)
	{
	case 1:
		classes();
		break;
	case 2:
		courses();
		break;
	case 3:
		Scoreboard();
		break;
	case 4:
		Attendance_list();
		break;
	}
}

void lecturer_menu()
{
	int ans;
	cout << "List:\n 1. View list of courses in the current semester\n 2. View list of students of a course\n 3. View attendance list of a course\n 4. Edit an attendance\n 5. Import scoreboard of a course\n 6. Edit grade of a student\n 7. View a scoreboard\nwhat do you want to do : ";
	cin >> ans;
	switch (ans)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	}
}

void student_menu()
{
	int ans;
	cout << "List:\n 1. Check-in\n 2. View check - in result\n 3. View schedules\n 4. View your scores of a course.\nwhat do you want to do: ";
	cin >> ans;
	switch (ans)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}

//note
// giá trị trả về hàm login_account
//  staff => 0 role admin
//  lecturer => 1
//  student => -1
void menu()
{
	int ans;
	Login log_in;
	log_in.Load_password();
	int key;
	cout << "what do you want to do???\n 1. Login\n 2. Exit\n";
	cin >> ans;
	switch(ans)
	{
	case 1:
		cout << "Login to your account!" << endl;
		key = log_in.login_account();
		switch (key)
		{
		case 0:
			staff_menu();
			break;
		case 1:
			lecturer_menu();
			break;
		case -1:
			student_menu();
			break;
		}
		break;
	case 2:
		return;
	}
}