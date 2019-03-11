#include "meatball.h"

//Login
Login::Login()
{
	a->head = NULL;
	a->tail = NULL;
}
NodeAccount* Login::CreateNodeAccount(Account a)
{
	NodeAccount* p = new NodeAccount;
	p->x = a;
	p->next = NULL;
	return p;
}
void Login::InsertTailAccount(NodeAccount* p)
{
	if (a->head == NULL && a->tail == NULL)
	{
		a->tail = p;
		a->head = a->tail;
	}
	else
	{
		a->tail->next = p;
		a->tail = p;
	}
}
int Login::GetSizePassword()
{
	NodeAccount* p = a->head;
	int number = 1;
	if (p == NULL)
		return 0;
	while (p->next != NULL)
	{
		p = p->next;
		number++;
	}
	return number;
}
void Login::DeleteTailPassword()
{
	NodeAccount* p = a->head;
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	NodeAccount* t = p->next;
	p->next = NULL;
	delete t;
}
Account Login::GetAccount(int i)
{
	NodeAccount* p = a->head;
	int number = 0;
	while (p != NULL)
	{
		if (number == i)
		{
			return p->x;
		}
		p = p->next;
		number++;
	}
	return p->x;
}
void Login::Change_password()
{
	char new_password[10], password_cmp[10];
	do
	{
		cout << "Enter your new password: ";
		cin >> new_password;
		cout << "Confirm password: ";
		cin >> password_cmp;
		clear();
	} while (_stricmp(new_password, password_cmp));
	NodeAccount* p = a->head;
	int number = 0;
	while (p != NULL)
	{
		if (number == token)
		{
			p->x._password = new_password;
			break;
		}
		p = p->next;
		number++;
	}
	Save_data();
}
void Login::Save_data()
{
	ofstream fout;
	fout.open("password.csv");
	fout << "account,password" << endl;
	for (int i = 0; i < GetSizePassword(); i++)
	{
		Account a = GetAccount(i);
		fout << a._account << "," << a._password << endl;
	}
	fout.close();
}
int Login::login_account()
{
	char account_[10], password_[10]; //biến nhập tài khoản
	cout << "Please input your account:";
	cin >> account_;
	for (int i = 0; i < GetSizePassword(); i++)
	{
		if (account_ == GetAccount(i)._account)
		{
			token = i;
			cout << "Please input your password:";
			cin >> password_;
			if (password_ == GetAccount(i)._password)
			{
				if (_stricmp(account_, "99999") == -1)
				{
					return -1;
				}
				else
				{
					if (_stricmp(account_, "admin") == 0)
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
	char c[50]; //rác
	fin.getline(c, 100);
	while (!fin.eof())
	{
		getline(fin, b._account, ',');
		getline(fin, b._password, '\n');
		NodeAccount* c = CreateNodeAccount(b);
		InsertTailAccount(c);
	}
	DeleteTailPassword();
	fin.close();
}
//các hàm cho môn học
Courses::~Courses()
{
}
Courses::Courses()
{
	all_courses->head = NULL;
	all_courses->tail = NULL;
}
NodeCourses* Courses::CreateNodeCourses(Course a)
{
	NodeCourses* p = new NodeCourses;
	p->x = a;
	p->next = NULL;
	return p;
}
void Courses::InsertTailCourses(NodeCourses* p)
{
	if (all_courses->head == NULL && all_courses->tail == NULL)
	{
		all_courses->tail = p;
		all_courses->head = all_courses->tail;
	}
	else
	{
		all_courses->tail->next = p;
		all_courses->tail = p;
	}
}
int Courses::GetSizeCourses()
{
	NodeCourses* p = all_courses->head;
	int number = 1;
	if (p == NULL)
		return 0;
	while (p->next != NULL)
	{
		p = p->next;
		number++;
	}
	return number;
}
void Courses::DeleteTailCourses()
{
	NodeCourses* p = all_courses->head;
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	NodeCourses* t = p->next;
	p->next = NULL;
	delete t;
}
Course Courses::GetCourses(int i)
{
	NodeCourses* p = all_courses->head;
	int number = 0;
	while (p != NULL)
	{
		if (number == i)
		{
			return p->x;
		}
		p = p->next;
		number++;
	}
	return p->x;
}
//các hàm cho lớp
Class::Class()
{
	all_classes->head = NULL;
	all_classes->tail = NULL;
}

Class::~Class()
{
	delete all_classes;
}
NodeClass* Class::CreatNodeClass(Student a)
{
	NodeClass* p = new NodeClass;
	p->x = a;
	p->next = NULL;
	return p;
}
void Class::InsertTail(NodeClass* p)
{
	if (all_classes->head == NULL && all_classes->tail == NULL)
	{
		all_classes->tail = p;
		all_classes->head = all_classes->tail;
	}
	else
	{
		all_classes->tail->next = p;
		all_classes->tail = p;
	}
}
Student InputStudent()
{
	Student a; //biến tạm
	cout << "Please input student ID you want put into:";
	cin >> a.student_ID;
	cout << "Please input student last name you want put into:";
	cin >> a.firstname;
	cout << "Please input student first name you want put into:";
	cin >> a.lastname;
	cout << "Please input student sex you want put into:";
	cin >> a.gender;
	cout << "Please input student day of birth you want put into:";
	cin >> a.DoB.day;
	cout << "Please input student month of birth you want put into:";
	cin >> a.DoB.month;
	cout << "Please input student year of birth you want put into:";
	cin >> a.DoB.year;
	return a;
}
void Class::ChangeStudent(Student a, int i)
{
	NodeClass* p = all_classes->head;
	int number = 0;
	while (p != NULL)
	{
		if (number == i)
		{
			p -> x = a;
		}
		p = p->next;
		number++;
	}
}
void Class::DeleteStudent(int i)
{
	NodeClass* p = all_classes->head;
	int number = 0;
	while (p->next != NULL)
	{
		if (number + 1 == i)
		{
			break;
		}
		p = p->next;
		number++;
	}
	NodeClass* t = p->next;
	p->next = t->next;
	delete t;
}
void control::DataStudentAdd()
{
	Student a = InputStudent(); //biến tạm
	char s[10]; //chuỗi để nhập tên lớp vào
	cout << "Please input class of student you want add (example CLC1 or clc1):";
	cin >> s;
	bool b;
	switch (s[3])
	{
	case 49:a.number = K18[0].GetSize() + 1;
		b = K18[0].AddStudent(a);
		break;
	case 50:a.number = K18[1].GetSize() + 1;
		b = K18[1].AddStudent(a);
		break;
	case 51:a.number = K18[2].GetSize() + 1;
		b = K18[2].AddStudent(a);
		break;
	case 52:a.number = K18[3].GetSize() + 1;
		b = K18[3].AddStudent(a);
		break;
	case 53:a.number = K18[4].GetSize() + 1;
		b = K18[4].AddStudent(a);
		break;
	case 54:a.number = K18[5].GetSize() + 1;
		b = K18[5].AddStudent(a);
		break;
	default: b = false;
	}
	if (b)
	{
		cout << "That class had that student before! or name of class you input error";
	}
	else
	{
		cout << "students were add to that class";
	}
}
int control::FindStudent(int SttClass,int id)
{
	for (int i = 0; i < K18[SttClass].GetSize(); i++)
	{
		Student a;
		a = K18[SttClass].GetStudent(i);
		if (id == a.student_ID)
		{
			id = i;
			break;
		}
	}
	return -1;
}
void control::EditStudent()
{
	char s[10]; //chuỗi để nhập tên lớp vào
	int b;
	do
	{
		cout << "Please input class of student you want edit (example CLC1 or clc1):";
		cin >> s;
		switch (s[3])
		{
		case 49: b = 0;
			break;
		case 50: b = 1;
			break;
		case 51: b = 2;
			break;
		case 52: b = 3;
			break;
		case 53: b = 4;
			break;
		case 54: b = 5;
			break;
		default: b = 10;
		}
	} while (b == 10);
	Student a;
	int c;
	cout << "Please input student ID you want look for:";
	cin >> c;
	int index;
	for (int i = 0; i < K18[b].GetSize(); i++)
	{
		index = FindStudent(b, c);
		if (index > 0)
			break;
	}
	a = InputStudent();
	K18[b].ChangeStudent(a, index);
}
void control::RemoveStudent()
{
	char s[10]; //chuỗi để nhập tên lớp vào
	cout << "Please input class of student you want edit (example CLC1 or clc1):";
	cin >> s;
	int b;
	switch (s[3])
	{
	case 49: b = 0;
		break;
	case 50: b = 1;
		break;
	case 51: b = 2;
		break;
	case 52: b = 3;
		break;
	case 53: b = 4;
		break;
	case 54: b = 5;
		break;
	}
	Student a;
	int c;
	cout << "Please input student ID you want remove:";
	cin >> c;
	int index;
	for (int i = 0; i < K18[b].GetSize(); i++)
	{
		index = FindStudent(b, c);
		if (index > 0)
			break;
	}
	K18[b].DeleteStudent(index);
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
	a.number = GetSize() + 1;
	if (similar == false)
	{
		NodeClass*p = CreatNodeClass(a);
		InsertTail(p);
	}
	return similar;
}
int Class::GetSize()
{
	NodeClass* p = all_classes->head;
	int number = 1;
	if (p == NULL)
		return 0;
	while (p->next != NULL)
	{
		p = p->next;
		number++;
	}
	return number;
}
Student Class::GetStudent(int i)
{
	NodeClass* p = all_classes->head;
	int number = 0;
	while (p != NULL)
	{
		if (number == i)
		{
			return p->x;
		}
		p = p->next;
		number++;
	}
	return p->x;
}
//các hàm quản lý cho admin
void control::load_student()
{
	for (int i = 0; i < 6; i++)
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
void control::ChangeClass()
{
	char s1[10]; //chuỗi để nhập tên lớp vào
	int d;
	do
	{
		cout << "Please input class of student you want change class(example CLC1 or clc1):";
		cin >> s1;
		switch (s1[3])
		{
		case 49: d = 0;
			break;
		case 50: d = 1;
			break;
		case 51: d = 2;
			break;
		case 52: d = 3;
			break;
		case 53: d = 4;
			break;
		case 54: d = 5;
			break;
		default: d = 10;
		}
	} while (d == 10);
	int c; //tạm chứa index của người muốn chuyển đis
	cout << "Please input student ID you want look for:";
	cin >> c;
	Student a;
	for (int i = 0; i < K18[d].GetSize(); i++)
	{
		a = K18[d].GetStudent(i);
		if (c == a.student_ID)
		{
			c = i;
			break;
		}
	}
	char s2[10]; //chuỗi để nhập tên lớp vào
	int b;
	do
	{
		cout << "Please input class you want this student move in (example CLC1 or clc1):";
		cin >> s2;
		switch (s2[3])
		{
		case 49: b = 0;
			break;
		case 50: b = 1;
			break;
		case 51: b = 2;
			break;
		case 52: b = 3;
			break;
		case 53: b = 4;
			break;
		case 54: b = 5;
			break;
		default: b = 10;
		}
	} while (b == 10);
	if (K18[b].AddStudent(a))
	{
		cout << s2 << " had this student before so change class is impossible" << endl;
	}
	else
	{
		K18[d].DeleteStudent(c);
	}
}
void control::List_Classes()
{
	cout << "List of classes:" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << ". ";
		cout << "clc" << i + 1 << endl;
	}
}
void control::List_Student()
{
	char s2[10];
	int b;
	do
	{
		cout << "Please input class print list of student (example CLC1 or clc1):";
		cin >> s2;
		switch (s2[3])
		{
		case 49: b = 0;
			break;
		case 50: b = 1;
			break;
		case 51: b = 2;
			break;
		case 52: b = 3;
			break;
		case 53: b = 4;
			break;
		case 54: b = 5;
			break;
		default: b = 10;
		}
	} while (b == 10);
	Student a;
	cout << "List of student:" << endl;
	for (int i = 0; i < K18[b].GetSize(); i++)
	{
		a = K18[b].GetStudent(i);
		cout << a.number << "," << a.student_ID << "," << a.lastname << "," << a.firstname << "," << a.gender << "," << a.DoB.day << "-" << a.DoB.month << "-" << a.DoB.year << endl;
	}
}
void control::save_student()
{
	for (int i = 0; i < 6; i++)
	{
		char * ptr = file_name[i];
		ofstream fout;
		fout.open(ptr);
		fout << head << endl;
		Student a;
		int b = K18[i].GetSize();
		for (int k = 0; k < b; k++)
		{
			a = K18[i].GetStudent(k);
			fout << a.number << "," << a.student_ID << "," << a.lastname << "," << a.firstname << "," << a.gender << "," << a.DoB.day << "-" << a.DoB.month << "-" << a.DoB.year << endl;
		}
		fout.close();
	}
}

//hàm ngoài
void clear()
{
	system("cls");
}

void classes()
{
	int ans;
	control key;
	int quit = 0;
	do
	{
		clear();
		key.load_student();
		cout << "List:\n 1. Import students of a class\n 2. Manually add a new student to a class\n 3. Edit an existing student\n 4. Remove a student\n 5. Move students\n 6. View list of classes\n 7. View list of students in a class\n 8. Eixt\nwhat do you want to do : ";
		cin >> ans;
		switch (ans)
		{
		case 1:
			break;
		case 2:key.DataStudentAdd();
			break;
		case 3:key.EditStudent();
			break;
		case 4:key.RemoveStudent();
			break;
		case 5:key.ChangeClass();
			break;
		case 6:key.List_Classes();
			break;
		case 7:key.List_Student();
			break;
		case 8:quit = 1;
			break;
		}
		key.save_student();
	} while (quit != 1);
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
	cout << "List:" << endl;
	cout << " 1. Search and view scoreboard of a course" << endl;
	cout << " 2. Export a scoreboard to a csv file." << endl;
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
	cout << "List:" << endl;
	cout << " 1. Search and view attendance list of a course" << endl;
	cout << " 2. Export a attendance list to a csv file." << endl;

	cin >> ans;
	switch (ans)
	{
	case 1:
		break;
	case 2:
		break;
	}
}

// Menu
void staff_menu(Login &log_in)
{
	int ans;
	cout << "List:" << endl;
	cout << " 1. class" << endl;
	cout << " 2. course" << endl;
	cout << " 3. Scoreboard" << endl;
	cout << " 4. Attendance_list" << endl;
	cout << " 5. Change pasword" << endl;
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
	case 5:
		log_in.Change_password();
		break;
	}
}

void lecturer_menu(Login &log_in)
{
	int ans;
	cout << "List:" << endl;
	cout << " 1. View list of courses in the current semester" << endl;
	cout << " 2. View list of students of a course" << endl;
	cout << " 3. View attendance list of a course" << endl;
	cout << " 4. Edit an attendance" << endl;
	cout << " 5. Import scoreboard of a course" << endl;
	cout << " 6. Edit grade of a student" << endl;
	cout << " 7. View a scoreboard" << endl;
	cout << " 8. Change pasword" << endl;
	cout << "what do you want to do : ";
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
		log_in.Change_password();
		break;
	}
}

void student_menu(Login &log_in)
{
	int ans;
	cout << "List:" << endl;
	cout << " 1. Check - in" << endl;
	cout << " 2. View check - in result" << endl;
	cout << " 3. View schedules" << endl;
	cout << " 4. View your scores of a course." << endl;
	cout << " 5. Change pasword" << endl;
	cout << "what do you want to do: ";
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
		log_in.Change_password();
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
	switch (ans)
	{
	case 1:
		cout << "Login to your account!" << endl;
		key = log_in.login_account();
		switch (key)
		{
		case 0:
			staff_menu(log_in);
			break;
		case 1:
			lecturer_menu(log_in);
			break;
		case -1:
			student_menu(log_in);
			break;
		}
		break;
	case 2:
		return;
	}
}
