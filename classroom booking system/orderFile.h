#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalfile.h"
#include<string>
class OrderFile
{
public:
	OrderFile();
	void updateOrder();
	map<int,map<string, string>>m_orderData;
	int m_size;

};

