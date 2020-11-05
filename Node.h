#pragma once
#include<cstdlib>
#include"data.h"
template <class T>
struct Node	{	// 数据成员: 
		T data;												// 数据域 
		Node<T>*next;										// 指针域
														// 构造函数: 
		Node();											// 无参数的构造函数 
		Node(T e, Node<T>* link = NULL);  // 已知数据元素值和指针建立结构
	};

template<class T>
Node<T>::Node() {
	next = NULL;
}

template<class T>
Node<T>::Node(T e,Node<T>*link) {
	data = e.data;
	next = link;
}