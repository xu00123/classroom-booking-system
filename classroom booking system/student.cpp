#include"student.h"
#include<fstream>
#include"globalfile.h"
#include"classroom.h"
#include"manager.h"
#include"orderFile.h"
#include<vector>
	Student::Student()
	{

	}

	Student::Student(int id, string name, string pword)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_Pword = pword;

		ifstream ifs;
		ifs.open(CLASSROOM_FILE, ios::in);
		ClassRoom c;
		while (ifs >> c.m_cId && ifs >> c.m_cNum)
		{
			vClass.push_back(c);
		}
		ifs.close();
	}

	void Student::operMenu()
	{
		cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|            1.申请预约           |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|          2.查看我的预约         |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|          3.查看所有预约         |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|            4.取消预约           |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|            0.注销登录           |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t ----------------------------------\n"; 
		cout << "请选择您的操作： " << endl;
	}

	void Student::applyOrder()
	{
		cout << "开放时间为周一至周五" << endl;
		cout << "请选择时间：" << endl;
		cout << "1、周一" << endl;
		cout << "2、周二" << endl;
		cout << "3、周三" << endl;
		cout << "4、周四" << endl;
		cout << "5、周五" << endl;
		int data = 0;
		int interval = 0;
		int room = 0;
		
		while (true)
		{
			cin >> data;
			if(data>=1&&data<=5) break;
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入申请预约时间段" << endl;
		cout << "1、上午" << endl;
		cout << "2、下午" << endl;
		while (true)
		{
			cin >> interval;
			if (interval >= 1 && interval <= 2) break;
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入要预约的教室" << endl;
		cout << "1、1号教室容量：" << vClass[0].m_cNum << endl;
		cout << "2、2号教室容量：" << vClass[1].m_cNum << endl;
		cout << "3、3号教室容量：" << vClass[2].m_cNum << endl;
		while (true)
		{
			cin >> room;
			if (room >= 1 && room <= 3) break;
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "预约成功，审核中" << endl;
		ofstream ofs(ORDER_FILE, ios::app);
		ofs << "data:" << data << " ";
		ofs << "interval:" << interval << " ";
		ofs << "stuId:" << this->m_Id << " ";
		ofs << "stuName:" << this->m_Name << " ";
		ofs << "roomId:" << room << " ";
		ofs << "status:" << 1 << endl;
		ofs.close();
		system("pause");
		system("cls");
	}
	void Student::showMyOrder()
	{
		OrderFile of;
		if (of.m_size == 0)
		{
			cout << "无预约记录" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < of.m_size; i++)
		{
			if (atoi(of.m_orderData[i]["data"].c_str()) == this->m_Id)
			{
				cout << "预约日期：周" << of.m_orderData[i]["data"]<<" ";
				cout << "时段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")<<" ";
				cout << "教室：" << of.m_orderData[i]["roomId"]<<" ";
				string status = "状态:";
				if (of.m_orderData[i]["status"]=="1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "审核未通过，预约失败";
				}
				else
				{
					status += "预约已取消";
				}
				cout << status << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void Student::showAllOrder()
	{
		OrderFile of;
		if (of.m_size == 0)
		{
			cout << "无预约记录" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < of.m_size; i++)
		{
			cout << i + 1 << "、";
			cout << "预约日期：周" << of.m_orderData[i]["data"] << " ";
			cout << "时段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "学号：" << of.m_orderData[i]["stuId"] << " ";
			cout << "姓名：" << of.m_orderData[i]["stuName"] << " ";
			cout << "教室：" << of.m_orderData[i]["roomId"] << " ";
			string status = "状态:";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
		system("pause");
		system("cls");

	}
	void Student::cancelOrder()
	{
		OrderFile of;
		if (of.m_size == 0)
		{
			cout << "无预约记录" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "审核中和预约成功的记录可以取消,请输入要取消的记录" << endl;

		vector<int>v;
		int index = 0;
		for (int i = 0; i < of.m_size; i++)
		{
			if (atoi(of.m_orderData[i]["status"].c_str()) == this->m_Id)
			{
				if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
				{
					v.push_back(i);
					cout << ++index << "、";
					cout << "预约日期：周" << of.m_orderData[i]["data"] << " ";
					cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")<<" ";
					cout << "教室：" << of.m_orderData[i]["roomId"] << " ";
					string status = "状态：";
					if (of.m_orderData[i]["status"] == "1")
					{
						status += "审核中";
					}
					else
					{
						status += "预约成功";
					}
					cout << status << endl;
				}
			}
		}
		cout << "请输入要取消的记录，0代表返回" << endl;
		int select = 0;
		
		while (true)
		{
			cin >> select;
			if (select >= 0 && select <= v.size())
			{
				if (select == 0) break;
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "0";
					of.updateOrder();
					cout << "已取消预约" << endl;
					break;
				}
				
			}
			
			cout << "输入有误，请重新输入" << endl;
		}
		
		system("pause");
		system("cls");

	}



