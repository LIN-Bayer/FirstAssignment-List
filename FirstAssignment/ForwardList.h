/**
 * ����:QG
 **/

#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__

#include<iostream>
using namespace std;

/*
 * ��������
 */
template<typename T>
class QGForwardList {
public:
	struct Node {
		/* ��������ڵ�Ķ��� */
		T data; // ��ʾ������
		Node* next;  // ��ʾָ���򣬴洢��һ���ڵ��λ��
	};

protected:

	Node* head;
	Node* tail;
	int count;

public:

	//��ȡͷ���
	Node* get_head()
	{
		return head;
	}

	/*
	 * ��ʾ�˵�
	 */
	void ShowMenu();

	/*
	 * ��ʼ������
	 */
	QGForwardList();

	/*
	 * ��������
	 */
	~QGForwardList();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	T& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	T& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(T& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(T& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(T& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(T& e));

	/*
	 * ��ת����1234��ת����4321
	 */
	bool reverse1();//�ǵݹ�
	Node* reverse2(Node* node_ptr); //�ݹ�

	/*
	 * �����л�
	 */
	bool isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	bool reverseEven();

	/*
	 * �����м�ڵ�
	 */
	T& middleElem();
};


//ForwardList.cpp

//��ʾ�˵�
template<typename T>
void QGForwardList<T>::ShowMenu() {
	cout << "********************************" << endl;
	cout << "*        1.��ʼ������          *" << endl;
	cout << "*    2.���ص�һ��Ԫ�ص�����    *" << endl;
	cout << "*    3.���ص�һ��Ԫ�ص�����    *" << endl;
	cout << "*      4.�������в���Ԫ��      *" << endl;
	cout << "*      5.ɾ�������е�Ԫ��      *" << endl;
	cout << "*      6.����Ԫ���Ƿ����      *" << endl;
	cout << "*       7.������Ԫ������       *" << endl;
	cout << "*          8.��������          *" << endl;
	cout << "*          9.�������          *" << endl;
	cout << "*         10.����ת          *" << endl;
	cout << "*         11.�����л�          *" << endl;
	cout << "*      12.����ż�ڵ㷴ת       *" << endl;
	cout << "*       13.�����м�ڵ�        *" << endl;
	cout << "********************************" << endl;
}




//��ʼ������
template<typename T>
QGForwardList<T>::QGForwardList() {
	count = 0;//��ʼ��������
	head = NULL;//��ͷ���Ϊ��
	Node* newnode = new Node;//�����ڴ�
	tail = newnode;
	cout << "�밴��ʾ��ʼ������" << endl;
	cout << "�������һ������(��0)��" << endl;
	cin >> newnode->data;
	while (newnode->data != 0) {
		count++;
		if (count == 1) {
			head = newnode;//ͷָ��ָ���׽ڵ�
			newnode->next = NULL;//ʹ��ָ��Ϊ��
			tail = newnode;//�����½ڵ�
		}
		else {
			newnode->next = NULL;//�½ڵ�ָ��Ϊ��
			tail->next = newnode;//ԭ����β�ڵ�ָ���½ڵ�
			tail = newnode;
		}
		newnode = new Node;//�ٴθ��½ڵ�����µ��ڴ�ռ�
		cout << "�������" << count + 1 << "�����ݣ�(��ʾ�����롮0������ֹ����)" << endl;
		cin >> newnode->data;
		if (newnode->data == 0) {
			break;
		}
	}
	delete(newnode);
	system("pause");
	system("cls");
}



//��������
template<typename T>
QGForwardList<T>::~QGForwardList() {
	Node* p;
	if (head != NULL) {
		while (head) {
			p = head->next;
			free(head);
			head = p;
		}
	}
	cout << "���������٣�" << endl;
}

//���������һ��Ԫ�ص�����
template<typename T>
T& QGForwardList<T>::front() {

	if (count == 0) {
		cout << "�������������ȴ���һ������" << endl;
	}
	else {
		cout << "��һ��Ԫ��Ϊ��" << head->data << endl;
		return head->data;

	}
	system("pause");
	system("cls");
}

//�������������һ��Ԫ�ص�����
template<typename T>
T& QGForwardList<T>::back() {
	if (count == 0) {
		cout << "�������������ȴ���һ������" << endl;
	}
	else {
		cout << "���һ��Ԫ��Ϊ��" << tail->data << endl;
		return tail->data;

	}
	system("pause");
	system("cls");
}


//�������һ��Ԫ��ǰ���Ԫ��e
template<typename T>
bool QGForwardList<T>::push_front(T& e) {
	Node* newnode = new Node;
	newnode->data = e;
	newnode->next = head;
	head = newnode;
	count++;
	cout << "����ɹ���" << endl;
	return head;
	delete(newnode);
	system("pause");
	system("cls");
}

//ɾ�������һ��Ԫ��
template<typename T>
bool QGForwardList<T>::pop_front() {
	Node* p;
	p = head;
	head = head->next;
	delete(p);
	count--;
	cout << "ɾ���ɹ���" << endl;
	return 1;
	system("pause");
	system("cls");
}

//���������һ��Ԫ�غ����Ԫ��e
template<typename T>
bool QGForwardList<T>::push_back(T& e) {
	Node* p = new Node;
	p->data = e;
	tail->next = p;
	tail = tail->next;
	tail->next = NULL;
	count++;
	cout << "����ɹ���" << endl;
	delete(p);
	return 1;
	system("pause");
	system("cls");
}

//ɾ���������һ��Ԫ��
template<typename T>
bool QGForwardList<T>::pop_back() {
	Node* p, * pre = head;
	p = tail;
	for (unsigned int i = 1; i < count - 1; i++)  //����forѭ����ָ��ָ�ڵ�index�������
	{
		pre = pre->next;
	}
	pre->next = tail;
	tail = pre;
	pre = NULL;
	free(p);
	count--;
	cout << "ɾ���ɹ���" << endl;
	return 1;
	system("pause");
	system("cls");
}

//������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
template<typename T>
bool QGForwardList<T>::insert(unsigned int index, T& e) {
	Node* p = head;
	Node* newnode = new Node; //�����½���ڴ�
	newnode->data = e;   //��e��ֵ����������
	for (unsigned int i = 1; i < index; i++)  //����forѭ����ָ��ָ�ڵ�index�������
	{
		p = p->next;
	}
	newnode->next = p->next;  //�½���nextָ���index+1�����
	p->next = newnode;   //��index������nextָ���½��
	count++;    //����ڵ�����
	cout << "����ɹ���" << endl;
	delete(newnode);
	return head;
	system("pause");
	system("cls");
}

//ɾ������λ��Ԫ��
template<typename T>
bool QGForwardList<T>::erase(unsigned int index) {
	Node* p = head, * pre = p;
	for (unsigned int i = 1; i < index; i++) {
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	free(p);
	count--;
	cout << "ɾ���ɹ���" << endl;
	return 1;
	system("pause");
	system("cls");
}

//�������
template<typename T>
bool QGForwardList<T>::clear() {
	Node* p, * q;
	if (head == NULL)
		return 0;
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = NULL;
	cout << "��������գ�" << endl;
	return 1;
	system("pause");
	system("cls");
}

//����Ԫ���Ƿ����
template<typename T>
bool QGForwardList<T>::contain(T& e) {
	Node* p = head;

	for (int i = 1; i <= count; i++) {
		if (p->data == e) {
			cout << "���ڸ�Ԫ�أ�" << endl;
			break;
		}
		else {
			if (i == count) {
				cout << "�鲻����Ԫ�أ�" << endl;
				break;
			}
			p = p->next;
		}
	}
	return 1;
	system("pause");
	system("cls");
}

//����������Ԫ�ص�����
template<typename T>
unsigned int QGForwardList<T>::size() {
	cout << "Ԫ������Ϊ��" << count << endl;
	return count;
	system("pause");
	system("cls");
}



template<typename T>
void Print(T& e) {
	cout << e << " ";
}


//��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
template<typename T>
bool QGForwardList<T>::traverse(void (*visit)(T& e)) {
	Node* p = head;
	while (p != NULL) {
		(*visit)(p->data);
		p = p->next;
	}
	cout << endl;
	return 1;
	system("pause");
	system("cls");
}


//��ת����1234��ת����4321
//�ǵݹ�
template<typename T>
bool QGForwardList<T>::reverse1() {
	Node* p1, * p2, * p3;
	p2 = head;  //��pheadָ������ͷ
	p3 = p1 = NULL;  //p1Ϊͷָ��֮ǰ�Ľڵ�
	while (p2 != NULL) {
		p3 = p2->next;	//�ݴ���һ���ڵ��ָ��
		p2->next = p1;	//��ת
		p1 = p2;	//��һ�ڵ�ָ������
		p2 = p3;	//��ǰ�ڵ�ָ������
	}
	head = p1;	//��ת�������ͷָ��Ϊ���һ����NULL�ڵ��ָ��

	//��ӡ
	Node* p = head;
	while (p != NULL && p->next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;

	//�ڴ��ͷ�
	delete head, p, p1, p2, p3;
	head = p = p1 = p2 = p3 = NULL;

	return 0;

}


//�ݹ�
template<typename T>
typename QGForwardList<T>::Node* QGForwardList<T>::reverse2(typename QGForwardList<T>::Node* node_ptr) {
	if (node_ptr->next == NULL) {
		head = node_ptr;	//���һ���ڵ���Ϊ�µ�ͷ�ڵ�
		return node_ptr;   //���һ���ڵ㷵��
	}

	Node* next_node = reverse2(node_ptr->next);
	next_node->next = node_ptr;
	node_ptr->next = NULL;

	return node_ptr;
}


//�����л�
template<typename T>
bool QGForwardList<T>::isLoop() {
	Node* slow = head, * fast = head;//��ͷ��ʼ����
	while (slow->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
			break;
		}
		else {
			return false;
		}
	}
}


//ż�ڵ㷴ת��1234��ת����2143
template<typename T>
bool QGForwardList<T>::reverseEven() {
	Node* p1, * p2, * p3;
	int i;
	if (head == NULL || count == 1) {
		cout << "�����������޷�����ż�ڵ㷴ת��" << endl;
	}
	else if (count == 2) {
		p1 = head;
		p2 = head->next;
		p1->next = NULL;
		p2->next = p1;
	}
	else {
		Node* p1 = head;
		Node* p2 = head->next;
		Node* p3 = p2->next;
		head = head->next;
		while (true) {
			p2->next = p1;
			if (p3->next != NULL && p3->next->next != NULL) //������ǰѭ��
			{
				p1->next = p3->next;
				p1 = p3;
				p2 = p1->next;
				p3 = p3->next->next;
			}
			else if (p3->next == NULL)           //����β����������Ԫ�ظ���Ϊ������ֱ�Ӱ����һ��Ԫ�����ӵ�ĩβ
			{
				p3->next = p3;
				break;
			}
			else if (p3->next->next == NULL)      //����β����������Ԫ�ظ���Ϊż�����������һ�������������ý�����NULL
			{
				p1->next = p3->next;
				p3->next->next = p3;
				p3->next = NULL;
				break;
			}
		}
		//��ӡ
		Node* p = head;
		while (p != NULL && p->next != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data << endl;

		//�ڴ��ͷ�
		head = p = p1 = p2 = p3 = NULL;
		delete head, p, p1, p2, p3;

		return 1;
	}
}




//�����м�ڵ�
template<typename T>
T& QGForwardList<T>::middleElem() {
	Node* slow = head, * fast = head;//��ͷ��ʼ����

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next;
		if (fast != NULL && fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
		else {
			break;
		}

	}
	cout << "�м�ڵ�ֵΪ��" << slow->data << endl;
	return slow->data;

}


#endif
