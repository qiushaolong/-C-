#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"worker.h"
using namespace std;

#define FILENAME "emFile.txt"

class staff
{
public:

	staff();

	void show_Menu();
	void sxit_system();

	int m_StaffNum;//��¼ְ������
	worker** m_StaffArray;//ְ������ָ��

	void Add_staff();

	void save();//�����ļ�

	bool m_FileIsEmpty;//�ļ��Ƿ�Ϊ��

	int get_EmpNum();//��ȡ�ļ�����

	void init_Emp();//��ʼ��Ա��

	void show_Emp();//��ʾԱ��

	int IsExist(int id);//�ж�ְ���Ƿ����

	void del_Emp();//ɾ��ְ��

	void mod_Emp();//�޸�ְ��
	void mod_Menu();

	void Find_Emp();//����ְ��

	void sort_Emp();//ְ������

	void clear_Emp();//ְ������

	~staff();

};
