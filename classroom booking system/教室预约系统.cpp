#include<iostream>
#include<string>
#include "identity.h"
using namespace std;
#include<fstream>
#include "globalfile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
}
}
void studentMenu(Identity* &student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void managerMenu(Identity* &manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看教室" << endl;
			man->showClassroom();

		}
		else if (select == 4)
		{
			cout << "清空预约" << endl;
			man->clearFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void loginIn(string fileName, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pword;
	if (type == 1)
	{
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pword;
	if (type == 1)
	{
		int fId;
		string fName;
		string fPword;
		while (ifs >> fId && ifs >> fName && ifs >> fPword)
		{
			if (fId == id && fName == name && fPword == pword)
			{
				cout << "学生登录验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pword);
				studentMenu(person);
				return;

			}
		}
		
	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPword;
		while (ifs >> fId && ifs >> fName && ifs >> fPword)
		{
			if (id == fId && name == fName && pword == fPword)
			{
				cout << "教师验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pword);
				teacherMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		string fName;
		string fPword;
		while (ifs >> fName && ifs >> fPword)
		{
			if (name == fName && pword == fPword)
			{
				cout << "管理员登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pword);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
	return;	
}
int main() 
{ 
	int select = 0;
	while (true)
	{
		cout << "====================== 欢迎来到教室预约系统 =====================" << endl;
		cout << endl << "请输入您的身份:" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|         1.学生代表            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|         2.老    师            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|         3.管 理 员            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|         0.退    出            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误,请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0; }