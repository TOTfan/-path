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

// ����� 
template<class T>
class LinkList {														// �������� template <class ElemType> class LinkList  { 
																		//protected:����������ݳ�Ա 
protected:															
	Node<T>* head;														// ͷ���ָ��  
	int length;															// ��������  

public:																	// ������ĺ�����Ա 

	LinkList();															// �޲����Ĺ��캯�� 

	LinkList(int n, struct Node<T>* v[] = NULL);						// �в����Ĺ��캯��  

	virtual ~LinkList() {};												// ��������  

	int GetLength() const;												// ��������   

	bool IsEmpty() const;												// �жϵ������Ƿ�Ϊ��  

	int Locate() const;													// Ԫ�ض�λ  

	int Get(int index) const;											// ��ָ��λ�õ�Ԫ��  

	int Set(int index);													// ����ָ��λ�õ�Ԫ��ֵ 

	int Delete(int index);												// ɾ��Ԫ��    

	int Insert(int index);												// ��ָ��λ�ò���Ԫ��

	void Show();														// ��ʾ����Ԫ��

	void Sort();														// Ԫ������

	void Empty();														// �������
														
};																		//};

//�޲����Ĺ��캯��
template<class T>
LinkList<T>::LinkList() {

	head = new Node<T>;													//ͷ�������ڴ棬����Ϊ0��
	head->next = NULL;
	length = 0;
}

//�������Ĺ��캯��														//�����������ֵ���ӵ�������
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

//��������
template<class T>
int LinkList<T>::GetLength() const{

	return length;

}

//�ж��Ƿ�Ϊ�ձ�
template<class T>
bool LinkList<T>::IsEmpty() const{

	if (head->next == NULL) {
		cout << "�ñ�Ϊ������" << endl;
		return false;
	}
	return true;

}

//ͨ��ѧ�Ų���ѧ����Ϣλ��
template<class T>
int LinkList<T>::Locate() const {

	int locate=0;														//Ԫ��λ��ֵ
	struct data save;													//���������ѧ��
	Node<struct data>* pNode;											//���ڱ�������
	cin >> save.num;
	pNode = (Node<struct data>*)head->next;

		while (pNode!=NULL&&pNode->data.num != save.num) {				//��������
			pNode = pNode->next;
			locate++;
		}
		if (pNode == NULL) {											//��������δ��ѯ����Ϣ���ش���
			cout << "ϵͳ���޸���Ϣ��" << endl;
			return -1;
		}
			return locate;												//�ɹ�����λ��ֵ
}

//��ȡָ��λ��Ԫ��ֵ
template<class T>
int LinkList<T>::Get(int index) const {

	Node<struct data>*search;											//���ڱ�������
	search = (Node<struct data>*)head->next;

	while (index != 0&&search->next != NULL) {							//���������ֵ
		search = search->next;
		index--;
	}
	if (index != 0) {
		cout << "������Ϣ����"<<endl;									//δ��ָ��λ�ñ����������
		return False;
	}

	cout << "���ҵ�����ϢΪ\n������" << search->data.name << "\nѧ��:" << search->data.num << "\n����:" <<search->data.score<<"\n" <<endl;
	return True;
}

//�޸�ָ��λ��Ԫ��ֵ
template<class T>
int LinkList<T>::Set(int index) {

	Node<struct data>* search;											//���ڱ�������
	Node<struct data> save;												//�洢�����޸ĵ�Ԫ��ֵ
	search = (Node<struct data>*)head->next;

	cout << "������ѧ��:";
	cin >> save.data.num;
	cout << "����������:";
	cin >> save.data.name;
	cout << "�����뼨��:";
	cin >> save.data.score;

	for (; index != 0&&search->next!=NULL; index--) {					//��������
		search = search->next;
	}
	if (index != 0) {													//����������δ��ָ��λ��
		cout << "�޷����ҵ���Ҫ�޸ĵ���Ϣ" << endl;
		return False;
	}
																		//�޸�Ԫ��ֵ
	search->data.num = save.data.num;
	search->data.name=save.data.name;
	search->data.score = save.data.score;
	cout << endl;
	return True;

}

//ɾ��ָ��λ��Ԫ��
template<class T>
int LinkList<T>::Delete(int index) {

	Node<struct data>* search;											//���ڱ�������
	Node<struct data>* pNode;											//�洢ɾ���ڵ����һ���ڵ����Ϣ
	pNode = new Node<struct data>;										
	search = (Node<struct data>*)head->next;

	if (index == 0) {													//������ֻ��һ��Ԫ��ʱ��ɾ��
		delete search->next;
		search->next = NULL;
		search = NULL;
		return 0;
	}

	for (; index != 1&&search->next!=NULL; index--) {					//������Ԫ��ʱ��ɾ��
		search = search->next;
	}
	if (index != 1) {
		cout << "�޷����ҵ���Ҫ�޸ĵ���Ϣ" << endl;
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

//��ӻ���ָ��λ�ò���Ԫ��
template<class T>
int LinkList<T>::Insert(int index) {

	Node<struct data>* search;											//���ڱ�������
    struct data save;													//�洢���ڲ������ӵ�Ԫ��ֵ
	Node<struct data>* pNode;											//��Ϊ�½ڵ��������
	pNode = new Node<struct data>;

	cout << "������ѧ��:";
	cin >> save.num;
	cout << "����������:";
	cin >> save.name;
	cout << "�����뼨��:";
	cin >> save.score;
	search = (Node<struct data>*)head;

	for (;index != 0&&search->next!=NULL; index--) {
		if (search->next->data.num == save.num) {
			cout << "��ѧ����ʹ�ù�����������ѧ�ţ�" << endl;
			return False;
		}
		search = search->next;
	}
	if (index != 0) {													//����������δ�ҵ�����λ��
		cout << "������Ϣ����" << endl;
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

//��ʾ����������ѧ����Ϣ
template<class T>
void LinkList<T>::Show() {
	Node<struct data>* search;
	search = (Node<struct data>*)head->next;
	cout << "ѧ��" << setw(8) << "����" << setw(8) << "����" << endl;

	while (search != NULL) {
		cout << search->data.num << setw(10)<<search->data.name <<setw(9)<< search->data.score << endl;
		search = search->next;
	}
	cout << endl;

}

//��������Ԫ�ؽ�������
template<class T>
void LinkList<T>::Sort() {
	int select;															//����ѡ������ʽ
	int loc;															//ȷ����СֵԪ��λ��
	int sign = 0;														//�ж������Ƿ���Ҫ���н���
	struct data cmp;													//�洢ֵ���ڱȽ�
	Node<struct data>* search;
	search = (Node<struct data>*)head->next;
	struct data* save;
	save = new struct data[length];

	//ѡ������ʽ
	do {
		cout << "��ѡ������ʽ:\n1.ѧ��\n2.����" << endl;
		cin >> select;
		if (select != 1 && select != 2) {
			cout << "����������������룡" << endl;
		}
	} while (select != 1 && select != 2);

	//��������Ԫ��ȫ������ṹ��������������
	for (int i = 0; i < length; i++) {
		save[i].num = search->data.num;
		save[i].name = search->data.name;
		save[i].score = search->data.score;
		search = search->next;
	}

	//ͨ��ѡ�����򷨽�������
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

	cout << "������ɣ�\n" << endl;

}

//�������
template<class T>
void LinkList<T>::Empty() {
	Node<struct data>*search;												//���ڱ�������
	Node<struct data>* pNode;												//���ڽ��нڵ��ڴ�ɾ��
	search = (Node<struct data>*)head->next;

	while (search!=NULL) {
		pNode = search;
		search = search->next;
		delete pNode;
	}

	head->next = NULL;
	length = 0;
	cout << "���ѧ����Ϣ��ɣ�\n" << endl;

}
