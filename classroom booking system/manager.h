#pragma once
#include<vector>
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"classroom.h"
class Manager:public Identity
{
public:
	Manager();
	Manager(string name, string pword);
	virtual void operMenu();
	void addPerson();
	void showPerson();
	void showClassroom();
	void clearFile();
	void initVector();
	vector<Student>vStu;
	vector<Teacher>vTea;
	bool checkRepeat(int id,int type);
	vector<ClassRoom>vClass;



};