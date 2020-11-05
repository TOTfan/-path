#pragma once
#include<iostream>
#include<iomanip>
#include"data.h"
using namespace std;
// 宏定义 
#define DEFAULT_SIZE 1000   // 缺省元素个数 

// 顺序表模板类的申明  
template <class ElemType>
class SqList
{

protected:
	// 顺序表的数据成员 
	int length;																// 顺序表的当前长度  
	int maxLength;															// 顺序表的最大容量 
	ElemType* data;															// 元素存储空间的首地址  

public:
	// 顺序表的函数成员 

	SqList(int size = DEFAULT_SIZE);										// 构造一个空表  

	SqList(ElemType v[], int n, int size = DEFAULT_SIZE);					// 根据数组 v 的内容构造顺序表

	virtual ~SqList() {};													// 析构函数 

	int GetLength() const;													// 取顺序表长度   

	bool IsEmpty() const;													// 判断顺序表是否为空 

	int Locate() const;														// 元素定位，求指定元素在顺序表中的位置

	int Get(int i) const;													// 取顺序表中第 i 个元素的值  

	int Set(int i);															// 修改顺序表中第 i 个元素的值 

	int Delete(int i);														// 删除顺序表中第 i 个元素   

	int Insert(int i);														// 在顺序表第 i 个位置插入元素 

	void Show();															// 显示顺序表所有元素

	void Sort();															// 对顺序表中元素按学号或绩点从小到大排序

	void Empty();															// 清空表中所有数据

	bool check(ElemType i);													//检查学号是否已被使用
};

//构造空表
template<class ElemType>
SqList<ElemType>::SqList(int size) {
	maxLength = size;
	length = 0;
	data =new ElemType [maxLength];
}

//根据传入的数组等信息构造顺序表
template<class ElemType>
SqList<ElemType>::SqList(ElemType v[], int n, int size) {
	data = v;
	length = n;
	maxLength = size;
}

//获取顺序表长度
template<class ElemType>
int SqList<ElemType>::GetLength() const{
	return length;
}

//判断顺序表是否为空表
template<class ElemType>
bool SqList<ElemType>::IsEmpty() const{
	if (length > 0) {												//顺序表长度为0时即为空表
		return false;
	}
	return true;
}

//元素定位
template<class ElemType>
int SqList<ElemType>::Locate() const{

	int loc = 1;
	Data save;														//存储学号来查找元素位置
	cin >> save.num;

	for (int i = 0; i < length; i++) {
		if (data[i].num == save.num) {								//当找到相同学号时，返回位置信息
			cout << loc << endl;
			return loc;
		}
		loc++;
	}
		
	return -1;														//未找到返回失败信息

}

//获取指定位置元素
template<class ElemType>
int SqList<ElemType>::Get(int i) const{

	cout << "学生的学号为:" << data[i-1].num << "\n姓名为:" << data[i-1].name << "\n绩点为:" << data[i-1].score<<endl;
	return 1;
}

//修改指定位置元素
template<class ElemType>
int SqList<ElemType>::Set(int i) {

	Data save;														//存储用于修改的信息

	cout << "请输入学生学号:" ;
	cin >> save.num;
	cout << "请输入学生姓名:" ;
	cin >> save.name;
	cout << "请输入学生绩点:" ;
	cin >> save.score;

	data[i - 1].num = save.num;
	data[i - 1].name = save.name;
	data[i - 1].score = save.score;
	return 1;

}

//删除指定位置元素
template<class ElemType>
int SqList<ElemType>::Delete(int i) {

	data[i - 1].num = -1;															//赋-1作为特征值
	data[i - 1].score = -1;
	length--;
	return 1;
}

//添加或在指定位置插入元素
template<class ElemType>
int SqList<ElemType>::Insert(int i) {
	Data save1;																//存储新增元素信息

	//判断输入位置信息是否符合要求
	if (i<0 || i>length) {
		cout << "位置信息有误！" << endl;									
		return 0;
	}
	if (i + 1 > maxLength) {
		cout << "超出系统最大存储上限！" << endl;
		return 0;
	}

	do {
		cout << "请输入学生学号:" ;							//循环直到输入的元素符合要求
		cin >> save1.num;
		cout << "学生姓名:" ;
		cin >> save1.name;
		cout << "学生绩点:" ;
		cin >> save1.score;
	} while (!check(save1));

	//添加操作
	if (i == length) {
		data[i] = save1;
		length++;
		return 1;
	}

	//插入操作
	for (int j=length; j>i;j--) {
		data[j] = data[j-1];
	}
	data[i] = save1;
	length++;
	return 1;

}

//显示所有元素
template<class ElemType>
void SqList<ElemType>::Show() {

	cout << "学号" <<setw(8)<< "姓名" <<setw(8)<< "绩点" << endl;

	for (int i = 0; i < length; i++) {
		if(data[i].num!=-1)
		cout << data[i].num << setw(10)<<data[i].name << setw(9)<<data[i].score << endl;
	}

}

//按学号或绩点从小到大对顺序表元素排序
template<class ElemType>
void SqList<ElemType>::Sort() {

	Data save;														//存储信息
	int loc;														//存储最小元素位置
	int sign;														//判断是否需要进行交换操作
	int select;														//用于选择排序方式

	do {
		cout << "请选择排序方式:\n1.学号\n2.绩点" << endl;
		cin >> select;
		if (select != 1 && select != 2) {							//循环直到输入符合要求
			cout << "输入错误！请重新输入！" << endl;	
		}
	} while (select != 1 && select!= 2);
	
	//选择排序法
	if (select == 1) {

		for (int i = 0; i < length; i++) {
			save = data[i];
			loc = i;
			sign = 0;

			for (int j = i; j < length; j++) {
				if (save.num > data[j].num) {
					save = data[j];
					loc = j;
					sign = 1;
				}
			}

			if (sign) {
				data[loc] = data[i];
				data[i] = save;
			}

		}
	}

	else {

		for (int i = 0; i < length; i++) {
			save = data[i];
			loc = i;
			sign = 0;

			for (int j = i; j < length; j++) {
				if (save.score > data[j].score) {
					save = data[j];
					loc = j;
					sign = 1;
				}
			}

			if (sign) {
				data[loc] = data[i];
				data[i] = save;
			}

		}
	}
}

//通过特征值清空顺序表
template<class ElemType>
void SqList<ElemType>::Empty() {
	for (int i = 0; i < length; i++) {
		data[i].num = -1;
	}
	length = 0;
	cout << "学生信息清空完成！" << endl;
}

//检查学号是否被使用过
template<class ElemType>
bool SqList<ElemType>::check(ElemType i) {

	for (int j = 0; j < length; j++) {
		if (i.num == data[j].num) {
			cout << "该学号已被使用请重新输入！\n" << endl;
			return false;
		}
	}

	return true;

}