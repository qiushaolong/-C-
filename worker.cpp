#include"worker.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DepID = dId;
}

void Employee::showInfo()//��ʾxx
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDepName(this->m_DepID)
		<< "\t��λְ��" << this->getJob(this->m_DepID) << endl;
}

string worker::getDepName(int dId)
{
	switch (dId)
	{
	case 1:
		return string("Ա��");
	case 2:
		return string("����");
	case 3:
		return string("�ܲ�");
	}
}

string worker::getJob(int dId)
{
	switch (dId)
	{
	case 1:
		return string("��ɾ�����������");
	case 2:
		return string("����ϰ彻�������񣬲��·�����ͨԱ��");
	case 3:
		return string("����˾����");
	}
}

manager::manager(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DepID = dId;
}

void manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDepName(this->m_DepID)
		<< "\t��λְ��"<< this->getJob(this->m_DepID) << endl;
}

//string manager::getDepName()
//{
//	return string("����");
//}

boss::boss(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DepID = dId;
}

void boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDepName(this->m_DepID)
		<< "\t��λְ��" << this->getJob(this->m_DepID) << endl;
}

//string boss::getDepName()
//{
//	return string("�ܲ�");
//}
