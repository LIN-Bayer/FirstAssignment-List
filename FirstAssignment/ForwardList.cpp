//#include<iostream>
//using namespace std;
//#include"ForwardList.h"



////��ʾ�˵�
//template<typename t>
//void qgforwardlist<t>::showmenu()
//{
//	cout << "********************************" << endl;
//	cout << "*        1.��ʼ������          *" << endl;
//	cout << "*    2.���ص�һ��Ԫ�ص�����    *" << endl;
//	cout << "*    3.���ص�һ��Ԫ�ص�����    *" << endl;
//	cout << "*      4.�������в���Ԫ��      *" << endl;
//	cout << "*      5.ɾ�������е�Ԫ��      *" << endl;
//	cout << "*      6.����Ԫ���Ƿ����      *" << endl;
//	cout << "*       7.������Ԫ������       *" << endl;
//	cout << "*          8.��������          *" << endl;
//	cout << "*          9.�������          *" << endl;
//	cout << "*         10.����ת          *" << endl;
//	cout << "*         11.�����л�          *" << endl;
//	cout << "*      12.����ż�ڵ㷴ת       *" << endl;
//	cout << "*       13.�����м�ڵ�        *" << endl;
//	cout << "********************************" << endl;
//}
//
//
//
//
////��ʼ������
//template<typename t>
//qgforwardlist<t>::qgforwardlist()
//{
//    count = 0;//��ʼ��������
//    head = null;//��ͷ���Ϊ��
//	node * newnode=new node;//�����ڴ�
//	tail = newnode;
//	cout << "�밴��ʾ��ʼ������" << endl;
//	cout << "�������һ������(��0)��" << endl;
//	cin >> newnode->data;
//	while (newnode->data != 0)
//	{
//		count ++;
//		if (count == 1)
//		{
//			head = newnode;//ͷָ��ָ���׽ڵ�
//			newnode->next = null;//ʹ��ָ��Ϊ��
//			tail = newnode;//�����½ڵ�
//		}
//		else
//		{
//			newnode->next = null;//�½ڵ�ָ��Ϊ��
//			tail->next = newnode;//ԭ����β�ڵ�ָ���½ڵ�
//			tail = newnode;
//		}
//		newnode = new node;//�ٴθ��½ڵ�����µ��ڴ�ռ�
//		cout << "�������" << count+1 << "�����ݣ�(��ʾ�����롮0������ֹ����)" << endl;
//		cin >> newnode->data;
//		if (newnode->data == 0)
//		{
//			break;
//		}
//	}
//	delete(newnode);
//	system("pause");
//	system("cls");
//}
//
//
//
////��������
//template<typename t>
//qgforwardlist<t>::~qgforwardlist()
//{
//	node* p;
//	if (head == null)
//		return 0;
//	while (head)
//	{
//		p = head->next;
//		free(head);
//		head = p;
//	}
//	cout << "���������٣�" << endl;
//}
//
////���������һ��Ԫ�ص�����
//template<typename t>
//qgforwardlist<t>::t& qgforwardlist<t>::front()
//{
//	
//	if (count == 0)
//	{
//		cout << "�������������ȴ���һ������" << endl;
//	}
//	else
//	{
//		cout << "��һ��Ԫ��Ϊ��" << head->data << endl;
//		return head->data;
//		
//	}
//	system("pause");
//	system("cls");
//}
//
////�������������һ��Ԫ�ص�����
//template<typename t>
//qgforwardlist<t>::t& qgforwardlist<t>::back()
//{
//	if (count == 0)
//	{
//		cout << "�������������ȴ���һ������" << endl;
//	}
//	else
//	{
//		cout << "���һ��Ԫ��Ϊ��" << tail->data << endl;
//		return tail->data;
//		
//	}
//	system("pause");
//	system("cls");
//}
//
//
////�������һ��Ԫ��ǰ���Ԫ��e
//template<typename t>
//bool qgforwardlist<t>::push_front(t& e)
//{
//	node* newnode = new node;
//	newnode->data = e;
//	newnode->next = head;
//	head = newnode;
//	count ++;
//	cout << "����ɹ���" << endl;
//	return head;
//	delete(newnode);
//	system("pause");
//	system("cls");
//}
//
////ɾ�������һ��Ԫ��
//template<typename t>
//bool qgforwardlist<t>::pop_front()
//{
//	node<t>* p;
//	p = head;
//	head = head->next;
//	delete(p);
//	count --;
//	cout << "ɾ���ɹ���" << endl;
//	return 1;
//	system("pause");
//	system("cls");
//}
//
////���������һ��Ԫ�غ����Ԫ��e
//template<typename t>
//bool qgforwardlist<t>::push_back(t& e)
//{
//	node* p = new node;
//	p->data = e;
//	tail->next = p;
//	tail = tail->next;
//	tail->next = null;
//	count ++;
//	cout << "����ɹ���" << endl;
//	delete(p);
//	return 1;
//	system("pause");
//	system("cls");
//}
//
////ɾ���������һ��Ԫ��
//template<typename t>
//bool qgforwardlist<t>::pop_back()
//{
//	node* p,*pre=head;
//	p = tail;
//	for (unsigned int i = 1; i < count-1; i++)  //����forѭ����ָ��ָ�ڵ�index�������
//	{
//		pre = pre->next;
//	}
//	pre->next = tail;
//	tail = pre;
//	pre = null;
//	free(p);
//	count --;
//	cout << "ɾ���ɹ���" << endl;
//	return 1;
//	system("pause");
//	system("cls");
//}
//
////������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
//template<typename t>
//bool qgforwardlist<t>::insert(unsigned int index, t& e)
//{
//	node*p=head;
//	node* newnode = new node; //�����½���ڴ�
//	newnode->data = e;   //��e��ֵ����������
//	for (unsigned int i = 1; i <index; i++)  //����forѭ����ָ��ָ�ڵ�index�������
//	{
//		p = p->next;
//	}
//	newnode->next = p->next;  //�½���nextָ���index+1�����
//	p->next = newnode;   //��index������nextָ���½��
//	count ++;    //����ڵ�����
//	cout << "����ɹ���" << endl;
//	delete(newnode);
//	return head;
//	system("pause");
//	system("cls");
//}
//
////ɾ������λ��Ԫ��
//template<typename t>
//bool qgforwardlist<t>::erase(unsigned int index)
//{
//	node* p=head, * pre=p;
//	for (unsigned int i = 1; i < index; i++)
//	{
//		pre = p;
//		p = p->next;
//	}
//	pre->next = p->next;
//	free(p);
//	count --;
//	cout << "ɾ���ɹ���" << endl;
//	return 1;
//	system("pause");
//	system("cls");
//}
//
////�������
//template<typename t>
//bool qgforwardlist<t>::clear()
//{
//	node* p;
//	while (count != 0)
//	{
//		p = head;
//		head = head->next;
//		free(p);
//	}
//	p = head = null;
//	cout << "��������գ�" << endl;
//	return 1;
//	system("pause");
//	system("cls");
//}
//
////����Ԫ���Ƿ����
//template<typename t>
//bool qgforwardlist<t>::contain(t& e)
//{
//	node* p=head;
//	
//	for (int i = 1; i <= count; i++)
//	{
//		if (p->data == e)
//		{
//			cout << "���ڸ�Ԫ�أ�" << endl;
//			break;
//		}
//		else
//		{
//			if (i == count)
//			{
//				cout << "�鲻����Ԫ�أ�" << endl;
//				break;
//			}
//			p = p->next;
//		}
//	}
//	return 1;
//	system("pause");
//	system("cls");
//}
//
////����������Ԫ�ص�����
//template<typename t>
//unsigned int qgforwardlist<t>::size()
//{
//	cout <<"Ԫ������Ϊ��"<< count << endl;
//	return count;
//	system("pause");
//	system("cls");
//}
//
//
//
////��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
//template<typename t>
//bool qgforwardlist<t>::traverse(void (*visit)(t& e))
//{
//	node* p=head;
//	while (p != null)
//	{
//		(*visit)(p->data);
//		p = p->next;
//	}
//	cout << endl;
//	return 1; 
//	system("pause");
//	system("cls");
//}
//
//
////��ת����1234��ת����4321
////�ǵݹ�
//template<typename t>
//bool qgforwardlist<t>::reverse1()
//{
//	node*p1, *p2, *p3;
//	p2 = head;  //��pheadָ������ͷ
//	p3 = p1 = null;  //p1Ϊͷָ��֮ǰ�Ľڵ�
//	while (p2 != null)
//	{
//		p3 = p2->next;	//�ݴ���һ���ڵ��ָ��
//		p2->next = p1;	//��ת
//		p1 = p2;	//��һ�ڵ�ָ������
//		p2 = p3;	//��ǰ�ڵ�ָ������
//	}
//	head = p1;	//��ת�������ͷָ��Ϊ���һ����null�ڵ��ָ��
//
//	//��ӡ
//	node*p = head;
//	while (p != null && p->next != null)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << p->data << endl;
//
//	//�ڴ��ͷ�
//	delete head, p, p1, p2, p3;
//	head = p = p1 = p2 = p3 = null;
//
//    return 0;
//	
//}
////�ݹ�
//template<typename t>
//qgforwardlist<t>::node* qgforwardlist<t>::reverse2(qgforwardlist<t>::node<t>* node_ptr)
//{
//	if (node_ptr->next == null)
//	{
//		head = node_ptr;	//���һ���ڵ���Ϊ�µ�ͷ�ڵ�
//		return node_ptr;   //���һ���ڵ㷵��
//	}
//
//	node* next_node = reverse2(node_ptr->next);
//	next_node->next = node_ptr;
//	node_ptr->next = null;
//
//	return node_ptr;
//}
//
//
//
//
////�����л�
//template<typename t>
//bool qgforwardlist<t>::isloop()
//{
//	node* slow = head, * fast = head;//��ͷ��ʼ����
//	while (slow->next != null && fast->next->next != null) {
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast) 
//		{
//			return true;
//			break;
//		}
//		else
//		{
//			return false;
//		}
//	}
//}
//
//
//
//
//
////ż�ڵ㷴ת��1234��ת����2143
//template<typename t>
//bool qgforwardlist<t>::reverseeven()
//{
//	node* p1, * p2, * p3;
//	int i;
//	if (head == null || count == 1)
//	{
//		cout << "�����������޷�����ż�ڵ㷴ת��" << endl;
//	}
//	else if(count==2)
//	{
//		p1 = head;
//		p2 = head->next;
//		p1->next = null;
//		p2->next = p1;
//	}
//	else
//	{
//		node* p1 = head;
//		node* p2 = head->next;
//		node* p3 = p2->next;
//		head = head->next;
//		while (true) {
//			p2->next = p1;
//			if (p3->next != null && p3->next->next != null) //������ǰѭ��
//			{
//				p1->next = p3->next;
//				p1 = p3;
//				p2 = p1->next;
//				p3 = p3->next->next;
//			}
//			else if (p3->next == null)           //����β����������Ԫ�ظ���Ϊ������ֱ�Ӱ����һ��Ԫ�����ӵ�ĩβ
//			{
//				p3->next = p3;
//				break;
//			}
//			else if (p3->next->next == null)      //����β����������Ԫ�ظ���Ϊż�����������һ�������������ý�����null
//			{
//				p1->next = p3->next;
//				p3->next->next = p3;
//				p3->next = null;
//				break;
//			}
//		}
//	//��ӡ
//		node* p = head;
//		while (p != null && p->next != null)
//		{
//			cout << p->data << " ";
//			p = p->next;
//		}
//		cout << p->data << endl;
//
//		//�ڴ��ͷ�
//		delete head, p, p1, p2, p3;
//		head = p = p1 = p2 = p3 = null;
//
//		return 1;
//	}
//}
//
//
//
//
////�����м�ڵ�
//template<typename t>
//qgforwardlist<t>::t& qgforwardlist<t>::middleelem()
//{
//	node* slow = head, * fast = head;//��ͷ��ʼ����
//
//	while (fast != null && fast->next != null)
//	{
//		fast = fast->next;
//		if (fast != null && fast->next != null)
//		{
//			fast = fast->next;
//			slow = slow->next;
//		}
//		else
//		{
//			break;
//		}
//
//	}
//	cout << "�м�ڵ�ֵΪ��"<<slow->data << endl;
//	return slow->data;
//	
//}

