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
	cout << "请输入选项" << endl;
	cin >> choice;
	unsigned int index;
	switch (choice)
	{
	case 1:
		cout << "您已初始化成功！" << endl;
		break;
	case 2:          //返回第一个元素的引用
		qgforwardlist.front();
		break;
	case 3:         //返回最后一个元素的引用
		qgforwardlist.back();
		break;
	case 4:          //在链表中插入元素
	{
		int a;
		cout << "请输入要插入的位置" << endl;
		cin >> index;
		cout << "请输入要插入的内容：" << endl;
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
	case 5:          //删除链表中的元素
	{
		cout << "请输入要删除的位置" << endl;
		cin >> index;
		if (index == 1)    //头删
		{
			qgforwardlist.pop_front();
		}
		else if (index == qgforwardlist.size())     //尾删
		{
			qgforwardlist.pop_back();
		}
		else          //删除
		{
			qgforwardlist.erase(index);
		}
		break;
	}
	case 6:          //查找元素是否存在
	{
		int b;
		cout << "请输入元素：" << endl;
		cin >> b;
		int& e1 = b;
		qgforwardlist.contain(e1);
		break;
	}
	case 7:          //链表中元素数量 
		qgforwardlist.size();
		break;
	case 8:          //遍历链表
	{
		
		qgforwardlist.traverse(Print);
		break;
	}
	case 9:          //清空链表
		qgforwardlist.clear();
		break;
	case 10:        //链表反转
	{
		int a;
		cout << "输入‘1’选择非递归反转" << endl;
		cout << "输入‘2’选择递归反转" << endl;
		cin >> a;
		cout << "反转前为：" << endl;
		qgforwardlist.traverse(Print);
		cout << "反转后为：" << endl;
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
			cout << "输入错误，无法进行反转" << endl;
		}
		break;
	}
	case 11:        //链表判环
	{
		bool ret = qgforwardlist.isLoop();
		if (ret == 1)
		{
			cout << "链表内有环！" << endl;
		}
		else
		{
			cout << "链表内无环！" << endl;
		}
		break;
	}
	case 12:        //链表偶节点反转 
		qgforwardlist.reverseEven();
		break;
	case 13:        //返回中间节点
		qgforwardlist.middleElem();
		break;
	default:
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	return 0;
}