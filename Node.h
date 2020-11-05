#pragma once
#include<cstdlib>
#include"data.h"
template <class T>
struct Node	{	// ���ݳ�Ա: 
		T data;												// ������ 
		Node<T>*next;										// ָ����
														// ���캯��: 
		Node();											// �޲����Ĺ��캯�� 
		Node(T e, Node<T>* link = NULL);  // ��֪����Ԫ��ֵ��ָ�뽨���ṹ
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