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
		cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|            1.����ԤԼ           |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|          2.�鿴�ҵ�ԤԼ         |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|          3.�鿴����ԤԼ         |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|            4.ȡ��ԤԼ           |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t|            0.ע����¼           |\n"; 
		cout << "\t\t|                                 |\n"; 
		cout << "\t\t ----------------------------------\n"; 
		cout << "��ѡ�����Ĳ����� " << endl;
	}

	void Student::applyOrder()
	{
		cout << "����ʱ��Ϊ��һ������" << endl;
		cout << "��ѡ��ʱ�䣺" << endl;
		cout << "1����һ" << endl;
		cout << "2���ܶ�" << endl;
		cout << "3������" << endl;
		cout << "4������" << endl;
		cout << "5������" << endl;
		int data = 0;
		int interval = 0;
		int room = 0;
		
		while (true)
		{
			cin >> data;
			if(data>=1&&data<=5) break;
			else
			{
				cout << "������������������" << endl;
			}
		}
		cout << "����������ԤԼʱ���" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
		while (true)
		{
			cin >> interval;
			if (interval >= 1 && interval <= 2) break;
			else
			{
				cout << "������������������" << endl;
			}
		}
		cout << "������ҪԤԼ�Ľ���" << endl;
		cout << "1��1�Ž���������" << vClass[0].m_cNum << endl;
		cout << "2��2�Ž���������" << vClass[1].m_cNum << endl;
		cout << "3��3�Ž���������" << vClass[2].m_cNum << endl;
		while (true)
		{
			cin >> room;
			if (room >= 1 && room <= 3) break;
			else
			{
				cout << "������������������" << endl;
			}
		}
		cout << "ԤԼ�ɹ��������" << endl;
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
			cout << "��ԤԼ��¼" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < of.m_size; i++)
		{
			if (atoi(of.m_orderData[i]["data"].c_str()) == this->m_Id)
			{
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"]<<" ";
				cout << "ʱ��:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")<<" ";
				cout << "���ң�" << of.m_orderData[i]["roomId"]<<" ";
				string status = "״̬:";
				if (of.m_orderData[i]["status"]=="1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "���δͨ����ԤԼʧ��";
				}
				else
				{
					status += "ԤԼ��ȡ��";
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
			cout << "��ԤԼ��¼" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < of.m_size; i++)
		{
			cout << i + 1 << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"] << " ";
			cout << "ʱ��:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"] << " ";
			cout << "������" << of.m_orderData[i]["stuName"] << " ";
			cout << "���ң�" << of.m_orderData[i]["roomId"] << " ";
			string status = "״̬:";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
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
			cout << "��ԤԼ��¼" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "����к�ԤԼ�ɹ��ļ�¼����ȡ��,������Ҫȡ���ļ�¼" << endl;

		vector<int>v;
		int index = 0;
		for (int i = 0; i < of.m_size; i++)
		{
			if (atoi(of.m_orderData[i]["status"].c_str()) == this->m_Id)
			{
				if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
				{
					v.push_back(i);
					cout << ++index << "��";
					cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"] << " ";
					cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")<<" ";
					cout << "���ң�" << of.m_orderData[i]["roomId"] << " ";
					string status = "״̬��";
					if (of.m_orderData[i]["status"] == "1")
					{
						status += "�����";
					}
					else
					{
						status += "ԤԼ�ɹ�";
					}
					cout << status << endl;
				}
			}
		}
		cout << "������Ҫȡ���ļ�¼��0������" << endl;
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
					cout << "��ȡ��ԤԼ" << endl;
					break;
				}
				
			}
			
			cout << "������������������" << endl;
		}
		
		system("pause");
		system("cls");

	}



