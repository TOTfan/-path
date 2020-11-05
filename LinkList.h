#pragma once
//LinkList.h 
#include<iostream>
#include<string>
#include<iomanip>
#include "Node.h"     
#include "data.h"
#define Maxsize 10000
using namespace std;
#define False 0
#define True 1

// 结点类 
template<class T>
class LinkList {														// 单链表类 template <class ElemType> class LinkList  { 
																		//protected:单链表的数据成员 
protected:															
	Node<T>* head;														// 头结点指针  
	int length;															// 单链表长度  

public:																	// 单链表的函数成员 

	LinkList();															// 无参数的构造函数 

	LinkList(int n, struct Node<T>* v[] = NULL);						// 有参数的构造函数  

	virtual ~LinkList() {};												// 析构函数  

	int GetLength() const;												// 求单链表长度   

	bool IsEmpty() const;												// 判断单链表是否为空  

	int Locate() const;													// 元素定位  

	int Get(int index) const;											// 求指定位置的元素  

	int Set(int index);													// 设置指定位置的元素值 

	int Delete(int index);												// 删除元素    

	int Insert(int index);												// 在指定位置插入元素

	void Show();														// 显示所有元素

	void Sort();														// 元素排序

	void Empty();														// 清空链表
														
};																		//};

//无参数的构造函数
template<class T>
LinkList<T>::LinkList() {

	head = new Node<T>;													//头结点分配内存，长度为0；
	head->next = NULL;
	length = 0;
}

//含参数的构造函数														//将传入的数组值连接到链表上
template<class T>
LinkList<T>::LinkList(int n,struct Node<T>* v[]) {
	Node<T>* node;
	node = new Node<T>;

	length = n;
	node = head;
	length = n;

	for (int i = 0; i < n; i++) {
		node->next = v[i];
		node = node->next;
	}

}

//求单链表长度
template<class T>
int LinkList<T>::GetLength() const{

	return length;

}

//判断是否为空表
template<class T>
bool LinkList<T>::IsEmpty() const{

	if (head->next == NULL) {
		cout << "该表为空链表" << endl;
		return false;
	}
	return true;

}

//通过学号查找学生信息位置
template<class T>
int LinkList<T>::Locate() const {

	int locate=0;														//元素位置值
	struct data save;													//保存输入的学号
	Node<struct data>* pNode;											//用于遍历链表
	cin >> save.num;
	pNode = (Node<struct data>*)head->next;

		while (pNode!=NULL&&pNode->data.num != save.num) {				//遍历链表
			pNode = pNode->next;
			locate++;
		}
		if (pNode == NULL) {											//遍历结束未查询到信息返回错误
			cout << "系统中无该信息！" << endl;
			return -1;
		}
			return locate;												//成功返回位置值
}

//获取指定位置元素值
template<class T>
int LinkList<T>::Get(int index) const {

	Node<struct data>*search;											//用于遍历链表
	search = (Node<struct data>*)head->next;

	while (index != 0&&search->next != NULL) {							//遍历链表查值
		search = search->next;
		index--;
	}
	if (index != 0) {
		cout << "输入信息有误！"<<endl;									//未到指定位置便遍历完链表
		return False;
	}

	cout << "查找到的信息为\n姓名：" << search->data.name << "\n学号:" << search->data.num << "\n绩点:" <<search->data.score<<"\n" <<endl;
	return True;
}

//修改指定位置元素值
template<class T>
int LinkList<T>::Set(int index) {

	Node<struct data>* search;											//用于遍历链表
	Node<struct data> save;												//存储用于修改的元素值
	search = (Node<struct data>*)head->next;

	cout << "请输入学号:";
	cin >> save.data.num;
	cout << "请输入姓名:";
	cin >> save.data.name;
	cout << "请输入绩点:";
	cin >> save.data.score;

	for (; index != 0&&search->next!=NULL; index--) {					//遍历链表
		search = search->next;
	}
	if (index != 0) {													//遍历完链表未到指定位置
		cout << "无法查找到需要修改的信息" << endl;
		return False;
	}
																		//修改元素值
	search->data.num = save.data.num;
	search->data.name=save.data.name;
	search->data.score = save.data.score;
	cout << endl;
	return True;

}

//删除指定位置元素
template<class T>
int LinkList<T>::Delete(int index) {

	Node<struct data>* search;											//用于遍历链表
	Node<struct data>* pNode;											//存储删除节点的下一个节点的信息
	pNode = new Node<struct data>;										
	search = (Node<struct data>*)head->next;

	if (index == 0) {													//当链表只有一个元素时的删除
		delete search->next;
		search->next = NULL;
		search = NULL;
		return 0;
	}

	for (; index != 1&&search->next!=NULL; index--) {					//链表多个元素时的删除
		search = search->next;
	}
	if (index != 1) {
		cout << "无法查找到需要修改的信息" << endl;
		return False;
	}

	pNode = search->next;												
	search->next = pNode->next;
	pNode->next = NULL;
	delete pNode;
	length--;
	cout << endl;
	return True;
}

//添加或在指定位置插入元素
template<class T>
int LinkList<T>::Insert(int index) {

	Node<struct data>* search;											//用于遍历链表
    struct data save;													//存储用于插入或添加的元素值
	Node<struct data>* pNode;											//作为新节点加入链表
	pNode = new Node<struct data>;

	cout << "请输入学号:";
	cin >> save.num;
	cout << "请输入姓名:";
	cin >> save.name;
	cout << "请输入绩点:";
	cin >> save.score;
	search = (Node<struct data>*)head;

	for (;index != 0&&search->next!=NULL; index--) {
		if (search->next->data.num == save.num) {
			cout << "该学号已使用过，请输入别的学号！" << endl;
			return False;
		}
		search = search->next;
	}
	if (index != 0) {													//遍历完链表未找到插入位置
		cout << "输入信息有误！" << endl;
		return False;
	}

	pNode->data.num = save.num;
	pNode->data.name = save.name;
	pNode->data.score = save.score;
	pNode->next = search->next;
	search->next = pNode;
	length++;
	cout << endl;
	return True;

}

//显示链表中所有学生信息
template<class T>
void LinkList<T>::Show() {
	Node<struct data>* search;
	search = (Node<struct data>*)head->next;
	cout << "学号" << setw(8) << "姓名" << setw(8) << "绩点" << endl;

	while (search != NULL) {
		cout << search->data.num << setw(10)<<search->data.name <<setw(9)<< search->data.score << endl;
		search = search->next;
	}
	cout << endl;

}

//对链表中元素进行排序
template<class T>
void LinkList<T>::Sort() {
	int select;															//用于选择排序方式
	int loc;															//确定最小值元素位置
	int sign = 0;														//判断排序是否需要进行交换
	struct data cmp;													//存储值用于比较
	Node<struct data>* search;
	search = (Node<struct data>*)head->next;
	struct data* save;
	save = new struct data[length];

	//选择排序方式
	do {
		cout << "请选择排序方式:\n1.学号\n2.绩点" << endl;
		cin >> select;
		if (select != 1 && select != 2) {
			cout << "输入错误！请重新输入！" << endl;
		}
	} while (select != 1 && select != 2);

	//将链表中元素全部存入结构体数组用于排序
	for (int i = 0; i < length; i++) {
		save[i].num = search->data.num;
		save[i].name = search->data.name;
		save[i].score = search->data.score;
		search = search->next;
	}

	//通过选择排序法进行排序
	if (select == 1) {
		for (int i = 0; i < length; i++) {
			cmp = save[i];
			loc = i;
			sign = 0;
			for (int j = i; j < length; j++) {
				if (cmp.num > save[j].num) {
					cmp=save[j];
					loc = j;
					sign = 1;
				}
			}
			if (sign) {
				save[loc] = save[i];
				save[i] = cmp;
			}
		}
		search = (Node<struct data>*)head->next;
		for (int i = 0; i < length; i++) {
			search->data = save[i];
			search = search->next;
		}
		}
	else {
		for (int i = 0; i < length; i++) {
			cmp = save[i];
			loc = i;
			sign = 0;
			for (int j = i; j < length; j++) {
				if (cmp.score > save[j].score) {
					cmp = save[j];
					loc = j;
					sign = 1;
				}
			}
			if (sign) {
				save[loc] = save[i];
				save[i] = cmp;
			}
		}
		search = (Node<struct data>*)head->next;
		for (int i = 0; i < length; i++) {
			search->data = save[i];
			search = search->next;
		}
	}

	cout << "排序完成！\n" << endl;

}

//清空链表
template<class T>
void LinkList<T>::Empty() {
	Node<struct data>*search;												//用于遍历链表
	Node<struct data>* pNode;												//用于进行节点内存删除
	search = (Node<struct data>*)head->next;

	while (search!=NULL) {
		pNode = search;
		search = search->next;
		delete pNode;
	}

	head->next = NULL;
	length = 0;
	cout << "清空学生信息完成！\n" << endl;

}
