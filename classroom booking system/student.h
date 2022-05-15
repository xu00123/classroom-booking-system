#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include"classroom.h"
#include"orderFile.h"
class Student:public Identity
{
public:
	Student();

	Student(int id, string name, string pword);

	virtual void operMenu();

	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();

	vector<ClassRoom> vClass;


	int m_Id;
};
