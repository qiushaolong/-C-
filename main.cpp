#include<iostream>
#include<string>

#include"staff_class.h"
#include"worker.h"
using namespace std;


int main()
{
	staff tf;
	int choice = 0;

	while (true)
	{
		tf.show_Menu();
		cout << "������ָ�" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1://���ְ��
			tf.Add_staff();
			break;

		case 2://���ְ��
			tf.show_Emp();
			break;

		case 3://ɾ��ְ��
			tf.del_Emp();
			break;

		case 4://�޸�ְ��
			tf.mod_Emp();
			break;

		case 5://����ְ��
			tf.Find_Emp();
			break;

		case 6://ְ������
			tf.sort_Emp();
			break;

		case 7://���
			tf.clear_Emp();
			break;

		case 8://�˳�ϵͳ
			tf.sxit_system();
			break;
		}
	}

	system("pause");
	return 0;
}

