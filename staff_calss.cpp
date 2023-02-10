#include"staff_class.h"


staff::staff()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;

		this->m_StaffNum = 0;
		this->m_StaffArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;//����һ��
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;

		this->m_StaffNum = 0;
		this->m_StaffArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//��¼�ļ�����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_StaffNum = num;

	this->m_StaffArray = new worker * [this->m_StaffNum];

	this->init_Emp();

	for (int i = 0; i < this->m_StaffNum; i++)
	{
		cout << "  ְ����ţ� " << this->m_StaffArray[i]->m_ID
			<< "  ְ�������� " << this->m_StaffArray[i]->m_name
			<< "  ���ű�ţ� " << this->m_StaffArray[i]->m_DepID << endl;
	}
}

staff::~staff() 
{
	if (this->m_StaffArray != NULL)
	{
		delete[] this->m_StaffArray;
		this->m_StaffArray = NULL;
	}
}


void staff::show_Menu()
{
	cout << "\t        \t" << endl;
	cout << "\t1.����ְ����Ϣ\t" << endl;
	cout << "\t2.��ʾְ����Ϣ\t" << endl;
	cout << "\t3.ɾ����ְְ��\t" << endl;
	cout << "\t4.�޸�ְ����Ϣ\t" << endl;
	cout << "\t5.����ְ����Ϣ\t" << endl;
	cout << "\t6.���ձ������\t" << endl;
	cout << "\t7.��������ĵ�\t" << endl;
	cout << "\t8.�˳��������\t" << endl;
	cout << "\t        \t" << endl;
}

void staff::sxit_system()
{
	cout << "�˳�����" << endl;
	system("pause");
	exit(0);
}

void staff::Add_staff()
{
	int add_num = 0;
	cout << "���������ְ��������" << endl;
	cin >> add_num;

	if (add_num > 0)
	{
		int newSize = this->m_StaffNum + add_num ;//�¿ռ��С

		worker ** newSpace = new worker * [newSize + 4];//�����¿ռ�

		if (this->m_StaffArray != NULL)
		{
			for (int i = 0; i < this->m_StaffNum; i++)
			{
				newSpace[i] = this->m_StaffArray[i];
			}
		}

		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int dSlect;

			cout << "�������" << i + 1 << "��ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSlect;

			worker* worker = NULL;
			switch (dSlect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_StaffNum + i] = worker;
			

		}
		delete[] this->m_StaffArray;

		this->m_StaffArray = newSpace;

		this->m_StaffNum = newSize;

		cout << "�ɹ����" << add_num << "����ְ��" << endl;

		this->save();

		this->m_FileIsEmpty = false;

	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

void staff::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_StaffNum; i++)
	{
		ofs << this->m_StaffArray[i]->m_ID << " "
			<< this->m_StaffArray[i]->m_name << " "
			<< this->m_StaffArray[i]->m_DepID << endl;
	}

	ofs.close();
}


int staff::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num =  0 ;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}


void staff::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* worker = NULL;

		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}else if (dId == 2)
		{
			worker = new manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new boss(id, name, dId);
		}

		this->m_StaffArray[index] = worker;
		index++;
	}
	ifs.close();

}

void staff::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_StaffNum; i++)
		{
			this->m_StaffArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}


int staff::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_StaffNum; i++)
	{
		if (this->m_StaffArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
		
	}
	return index;
}

void staff::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ��ְ���ı��:" << endl;

		int id = 0;

		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_StaffNum - 1; i++)
			{
				this->m_StaffArray[i] = this->m_StaffArray[i + 1];
			}

			this->m_StaffNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

void staff::mod_Menu()
{
	cout << "\t        \t" << endl;
	cout << "  \t1.�޸�ְ�����\t" << endl;
	cout << "  \t2.�޸�ְ������\t" << endl;
	cout << "  \t3.�޸�ְ������\t" << endl;
	cout << "  \t4.����\t" << endl;
	cout << "  \t5.�˳��޸�\t" << endl;
	cout << "  \t        \t" << endl;
}
void staff::mod_Emp()
{
	int mod_id;
	string mod_name;
	int mod_dId;
	int mod_choic = 0;
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸�ְ���ı��:" << endl;

		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			while (mod_choic != 5)
			{
				this->m_StaffArray[index]->showInfo();
				this->mod_Menu();

				cout << "\t��ѡ��\t" << endl;
				cin >> mod_choic;

				switch (mod_choic)
				{
				case 1:
				{
					cout << "�������µı��:" << endl;
					cin >> mod_id;
					this->m_StaffArray[index]->m_ID = mod_id;
					system("cls");
					break;
				}
				case 2:
				{
					cout << "�������µ�����:" << endl;
					cin >> mod_name;
					this->m_StaffArray[index]->m_name = mod_name;
					system("cls");
					break;
				}
				break;
				case 3:
				{
					cout << "�������µĲ���:" << endl;
					cin >> mod_dId;
					this->m_StaffArray[index]->m_DepID = mod_dId;
					system("cls");
					break;
				}
				case 4:
				{
					this->save();
					cout << "����ɹ�" << endl;
					system("cls");
					break;
				}

				}
			}

		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

void staff::Find_Emp()
{
	int f_id;
	string f_name;

	int f_choice = 0;
	
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������ѯ�ķ�ʽ��1.��� 2.����" << endl;
		cin >> f_choice;

		switch (f_choice)
		{
		case 1:
		{
			cout << "��������:" << endl;
			cin >> f_id;
			int index = this->IsExist(f_id);
			if (index != -1)
			{
				this->m_StaffArray[index]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ�δ�ҵ���ְ��" << endl;
			}

			break;
		}
		case 2:
		{
			cout << "����������:" << endl;
			cin >> f_name;

			int index = -1;

			for (int i = 0; i < this->m_StaffNum; i++)
			{
				if (this->m_StaffArray[i]->m_name == f_name)
				{
					index = i;
					break;
				}
			}
			if (index != -1)
			{
				this->m_StaffArray[index]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ�δ�ҵ���ְ��" << endl;
			}

			break;
		}

		}

	}
	system("pause");
	system("cls");
}

void staff::sort_Emp()
{
	int s_choice;
	int s_index = 0;
	worker* temp;

	cout << "�������������ͣ�1.������� 2.��Ž���" << endl;
	cin >> s_choice;

	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_StaffNum; i++)
		{
			s_index = i;

			for (int j = i+1; j < this->m_StaffNum; j++)
			{
				if (s_choice == 1)
				{
					if (this->m_StaffArray[s_index]->m_ID > this->m_StaffArray[j]->m_ID)
					{
						s_index = j;
					}
				}
				else
				{
					if (this->m_StaffArray[s_index]->m_ID <  this->m_StaffArray[j]->m_ID)
					{
						s_index = j;
					}
				}
				
			}
			
			temp = this->m_StaffArray[i];
			this->m_StaffArray[i] = this->m_StaffArray[s_index];
			this->m_StaffArray[s_index] = temp;
		}

		this->save();
		this->show_Emp();
	}
	//system("pause");
	system("cls");
}

void staff::clear_Emp()
{
	cout << "ȷ����գ�1.��� 2.����" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_StaffArray != NULL)
		{
			for (int i = 0; i < this->m_StaffNum; i++)
			{
				delete this->m_StaffArray[i];
				this->m_StaffArray[i] = NULL;
			}

			delete[] this->m_StaffArray;

			this->m_StaffArray = NULL;
			this->m_StaffNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

