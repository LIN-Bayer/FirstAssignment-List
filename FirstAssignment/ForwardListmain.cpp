#include<iostream>
using namespace std;
#include"ForwardList.h"




int main()
{
	class QGForwardList<int> qgforwardlist;
	qgforwardlist.reverse2(qgforwardlist.get_head());
	qgforwardlist.traverse(Print);
	qgforwardlist.ShowMenu();
	int choice;
	cout << "������ѡ��" << endl;
	cin >> choice;
	unsigned int index;
	switch (choice)
	{
	case 1:
		cout << "���ѳ�ʼ���ɹ���" << endl;
		break;
	case 2:          //���ص�һ��Ԫ�ص�����
		qgforwardlist.front();
		break;
	case 3:         //�������һ��Ԫ�ص�����
		qgforwardlist.back();
		break;
	case 4:          //�������в���Ԫ��
	{
		int a;
		cout << "������Ҫ�����λ��" << endl;
		cin >> index;
		cout << "������Ҫ��������ݣ�" << endl;
		cin >> a;
		int& e = a;
		if (index == 1)
		{
			qgforwardlist.push_front(e);
		}
		else if (index == qgforwardlist.size())
		{
			qgforwardlist.push_back(e);
		}
		else
		{
			qgforwardlist.insert(index, e);
		}
		break;
	}
	case 5:          //ɾ�������е�Ԫ��
	{
		cout << "������Ҫɾ����λ��" << endl;
		cin >> index;
		if (index == 1)    //ͷɾ
		{
			qgforwardlist.pop_front();
		}
		else if (index == qgforwardlist.size())     //βɾ
		{
			qgforwardlist.pop_back();
		}
		else          //ɾ��
		{
			qgforwardlist.erase(index);
		}
		break;
	}
	case 6:          //����Ԫ���Ƿ����
	{
		int b;
		cout << "������Ԫ�أ�" << endl;
		cin >> b;
		int& e1 = b;
		qgforwardlist.contain(e1);
		break;
	}
	case 7:          //������Ԫ������ 
		qgforwardlist.size();
		break;
	case 8:          //��������
	{
		
		qgforwardlist.traverse(Print);
		break;
	}
	case 9:          //�������
		qgforwardlist.clear();
		break;
	case 10:        //����ת
	{
		int a;
		cout << "���롮1��ѡ��ǵݹ鷴ת" << endl;
		cout << "���롮2��ѡ��ݹ鷴ת" << endl;
		cin >> a;
		cout << "��תǰΪ��" << endl;
		qgforwardlist.traverse(Print);
		cout << "��ת��Ϊ��" << endl;
		if (a == 1)
		{
			qgforwardlist.reverse1();
		}
		else if (a == 2)
		{
			qgforwardlist.reverse2(qgforwardlist.get_head());
			qgforwardlist.traverse(Print);
		}
		else
		{
			cout << "��������޷����з�ת" << endl;
		}
		break;
	}
	case 11:        //�����л�
	{
		bool ret = qgforwardlist.isLoop();
		if (ret == 1)
		{
			cout << "�������л���" << endl;
		}
		else
		{
			cout << "�������޻���" << endl;
		}
		break;
	}
	case 12:        //����ż�ڵ㷴ת 
		qgforwardlist.reverseEven();
		break;
	case 13:        //�����м�ڵ�
		qgforwardlist.middleElem();
		break;
	default:
		cout << "������������������" << endl;
	}
	system("pause");
	return 0;
}