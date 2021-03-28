/**
 * 作者:QG
 **/

#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__

#include<iostream>
using namespace std;

/*
 * 单向链表
 */
template<typename T>
class QGForwardList {
public:
	struct Node {
		/* 用于链表节点的定义 */
		T data; // 表示数据域
		Node* next;  // 表示指针域，存储下一个节点的位置
	};

protected:

	Node* head;
	Node* tail;
	int count;

public:

	//获取头结点
	Node* get_head()
	{
		return head;
	}

	/*
	 * 显示菜单
	 */
	void ShowMenu();

	/*
	 * 初始化链表
	 */
	QGForwardList();

	/*
	 * 销毁链表
	 */
	~QGForwardList();

	/*
	 * 返回链表中第一个元素的引用
	 */
	T& front();

	/*
	 * 返回链表中最后一个元素的引用
	 */
	T& back();

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(T& e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(T& e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(T& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(T& e));

	/*
	 * 反转链表，1234反转后变成4321
	 */
	bool reverse1();//非递归
	Node* reverse2(Node* node_ptr); //递归

	/*
	 * 链表判环
	 */
	bool isLoop();

	/*
	 * 偶节点反转，1234反转后变成2143
	 */
	bool reverseEven();

	/*
	 * 返回中间节点
	 */
	T& middleElem();
};


//ForwardList.cpp

//显示菜单
template<typename T>
void QGForwardList<T>::ShowMenu() {
	cout << "********************************" << endl;
	cout << "*        1.初始化链表          *" << endl;
	cout << "*    2.返回第一个元素的引用    *" << endl;
	cout << "*    3.返回第一个元素的引用    *" << endl;
	cout << "*      4.在链表中插入元素      *" << endl;
	cout << "*      5.删除链表中的元素      *" << endl;
	cout << "*      6.查找元素是否存在      *" << endl;
	cout << "*       7.链表中元素数量       *" << endl;
	cout << "*          8.遍历链表          *" << endl;
	cout << "*          9.清空链表          *" << endl;
	cout << "*         10.链表反转          *" << endl;
	cout << "*         11.链表判环          *" << endl;
	cout << "*      12.链表偶节点反转       *" << endl;
	cout << "*       13.返回中间节点        *" << endl;
	cout << "********************************" << endl;
}




//初始化链表
template<typename T>
QGForwardList<T>::QGForwardList() {
	count = 0;//初始化链表长度
	head = NULL;//让头结点为空
	Node* newnode = new Node;//开辟内存
	tail = newnode;
	cout << "请按提示初始化链表：" << endl;
	cout << "请输入第一个数据(非0)：" << endl;
	cin >> newnode->data;
	while (newnode->data != 0) {
		count++;
		if (count == 1) {
			head = newnode;//头指针指向首节点
			newnode->next = NULL;//使得指向为空
			tail = newnode;//加入新节点
		}
		else {
			newnode->next = NULL;//新节点指针为空
			tail->next = newnode;//原来的尾节点指向新节点
			tail = newnode;
		}
		newnode = new Node;//再次给新节点分配新的内存空间
		cout << "请输入第" << count + 1 << "个数据：(提示，输入‘0’可终止输入)" << endl;
		cin >> newnode->data;
		if (newnode->data == 0) {
			break;
		}
	}
	delete(newnode);
	system("pause");
	system("cls");
}



//销毁链表
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
	cout << "链表已销毁！" << endl;
}

//返回链表第一个元素的引用
template<typename T>
T& QGForwardList<T>::front() {

	if (count == 0) {
		cout << "不存在链表！请先创建一个链表" << endl;
	}
	else {
		cout << "第一个元素为：" << head->data << endl;
		return head->data;

	}
	system("pause");
	system("cls");
}

//返回链表中最后一个元素的引用
template<typename T>
T& QGForwardList<T>::back() {
	if (count == 0) {
		cout << "不存在链表！请先创建一个链表" << endl;
	}
	else {
		cout << "最后一个元素为：" << tail->data << endl;
		return tail->data;

	}
	system("pause");
	system("cls");
}


//在链表第一个元素前添加元素e
template<typename T>
bool QGForwardList<T>::push_front(T& e) {
	Node* newnode = new Node;
	newnode->data = e;
	newnode->next = head;
	head = newnode;
	count++;
	cout << "插入成功！" << endl;
	return head;
	delete(newnode);
	system("pause");
	system("cls");
}

//删除链表第一个元素
template<typename T>
bool QGForwardList<T>::pop_front() {
	Node* p;
	p = head;
	head = head->next;
	delete(p);
	count--;
	cout << "删除成功！" << endl;
	return 1;
	system("pause");
	system("cls");
}

//在链表最后一个元素后添加元素e
template<typename T>
bool QGForwardList<T>::push_back(T& e) {
	Node* p = new Node;
	p->data = e;
	tail->next = p;
	tail = tail->next;
	tail->next = NULL;
	count++;
	cout << "插入成功！" << endl;
	delete(p);
	return 1;
	system("pause");
	system("cls");
}

//删除链表最后一个元素
template<typename T>
bool QGForwardList<T>::pop_back() {
	Node* p, * pre = head;
	p = tail;
	for (unsigned int i = 1; i < count - 1; i++)  //利用for循环让指针指在第index个结点上
	{
		pre = pre->next;
	}
	pre->next = tail;
	tail = pre;
	pre = NULL;
	free(p);
	count--;
	cout << "删除成功！" << endl;
	return 1;
	system("pause");
	system("cls");
}

//在链表的第index + 1个元素前插入元素e
template<typename T>
bool QGForwardList<T>::insert(unsigned int index, T& e) {
	Node* p = head;
	Node* newnode = new Node; //开辟新结点内存
	newnode->data = e;   //把e赋值进数据域里
	for (unsigned int i = 1; i < index; i++)  //利用for循环让指针指在第index个结点上
	{
		p = p->next;
	}
	newnode->next = p->next;  //新结点的next指向第index+1个结点
	p->next = newnode;   //第index个结点的next指向新结点
	count++;    //链表节点增加
	cout << "插入成功！" << endl;
	delete(newnode);
	return head;
	system("pause");
	system("cls");
}

//删除任意位置元素
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
	cout << "删除成功！" << endl;
	return 1;
	system("pause");
	system("cls");
}

//清空链表
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
	cout << "链表已清空！" << endl;
	return 1;
	system("pause");
	system("cls");
}

//查找元素是否存在
template<typename T>
bool QGForwardList<T>::contain(T& e) {
	Node* p = head;

	for (int i = 1; i <= count; i++) {
		if (p->data == e) {
			cout << "存在该元素！" << endl;
			break;
		}
		else {
			if (i == count) {
				cout << "查不到该元素！" << endl;
				break;
			}
			p = p->next;
		}
	}
	return 1;
	system("pause");
	system("cls");
}

//返回链表中元素的数量
template<typename T>
unsigned int QGForwardList<T>::size() {
	cout << "元素数量为：" << count << endl;
	return count;
	system("pause");
	system("cls");
}



template<typename T>
void Print(T& e) {
	cout << e << " ";
}


//遍历链表, 对每个元素调用visit指向的函数
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


//反转链表，1234反转后变成4321
//非递归
template<typename T>
bool QGForwardList<T>::reverse1() {
	Node* p1, * p2, * p3;
	p2 = head;  //将phead指向链表头
	p3 = p1 = NULL;  //p1为头指针之前的节点
	while (p2 != NULL) {
		p3 = p2->next;	//暂存下一个节点的指针
		p2->next = p1;	//反转
		p1 = p2;	//上一节点指针右移
		p2 = p3;	//当前节点指针右移
	}
	head = p1;	//反转后的链表头指针为最后一个非NULL节点的指针

	//打印
	Node* p = head;
	while (p != NULL && p->next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;

	//内存释放
	delete head, p, p1, p2, p3;
	head = p = p1 = p2 = p3 = NULL;

	return 0;

}


//递归
template<typename T>
typename QGForwardList<T>::Node* QGForwardList<T>::reverse2(typename QGForwardList<T>::Node* node_ptr) {
	if (node_ptr->next == NULL) {
		head = node_ptr;	//最后一个节点会成为新的头节点
		return node_ptr;   //最后一个节点返回
	}

	Node* next_node = reverse2(node_ptr->next);
	next_node->next = node_ptr;
	node_ptr->next = NULL;

	return node_ptr;
}


//链表判环
template<typename T>
bool QGForwardList<T>::isLoop() {
	Node* slow = head, * fast = head;//从头开始出发
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


//偶节点反转，1234反转后变成2143
template<typename T>
bool QGForwardList<T>::reverseEven() {
	Node* p1, * p2, * p3;
	int i;
	if (head == NULL || count == 1) {
		cout << "不存在链表，无法进行偶节点反转！" << endl;
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
			if (p3->next != NULL && p3->next->next != NULL) //正常往前循环
			{
				p1->next = p3->next;
				p1 = p3;
				p2 = p1->next;
				p3 = p3->next->next;
			}
			else if (p3->next == NULL)           //到达尾部，且链表元素个数为奇数，直接把最后一个元素连接到末尾
			{
				p3->next = p3;
				break;
			}
			else if (p3->next->next == NULL)      //到达尾部，且链表元素个数为偶数，进行最后一步互换，并设置结束符NULL
			{
				p1->next = p3->next;
				p3->next->next = p3;
				p3->next = NULL;
				break;
			}
		}
		//打印
		Node* p = head;
		while (p != NULL && p->next != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data << endl;

		//内存释放
		head = p = p1 = p2 = p3 = NULL;
		delete head, p, p1, p2, p3;

		return 1;
	}
}




//返回中间节点
template<typename T>
T& QGForwardList<T>::middleElem() {
	Node* slow = head, * fast = head;//从头开始出发

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
	cout << "中间节点值为：" << slow->data << endl;
	return slow->data;

}


#endif
