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
			cout << "ע���ɹ�" << endl;
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
			cout << "ע���ɹ�" << endl;
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
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showClassroom();

		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pword;
	if (type == 1)
	{
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����:" << endl;
		cin >> id;
	}
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
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
				cout << "ѧ����¼��֤�ɹ�" << endl;
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
				cout << "��ʦ��֤�ɹ�" << endl;
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
				cout << "����Ա��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pword);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
	return;	
}
int main() 
{ 
	int select = 0;
	while (true)
	{
		cout << "====================== ��ӭ��������ԤԼϵͳ =====================" << endl;
		cout << endl << "�������������:" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|         1.ѧ������            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|         2.��    ʦ            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|         3.�� �� Ա            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|         0.��    ��            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������,������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0; }