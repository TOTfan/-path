#pragma once
#include<iostream>
#include<iomanip>
#include"data.h"
using namespace std;
// �궨�� 
#define DEFAULT_SIZE 1000   // ȱʡԪ�ظ��� 

// ˳���ģ���������  
template <class ElemType>
class SqList
{

protected:
	// ˳�������ݳ�Ա 
	int length;																// ˳���ĵ�ǰ����  
	int maxLength;															// ˳����������� 
	ElemType* data;															// Ԫ�ش洢�ռ���׵�ַ  

public:
	// ˳���ĺ�����Ա 

	SqList(int size = DEFAULT_SIZE);										// ����һ���ձ�  

	SqList(ElemType v[], int n, int size = DEFAULT_SIZE);					// �������� v �����ݹ���˳���

	virtual ~SqList() {};													// �������� 

	int GetLength() const;													// ȡ˳�����   

	bool IsEmpty() const;													// �ж�˳����Ƿ�Ϊ�� 

	int Locate() const;														// Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��

	int Get(int i) const;													// ȡ˳����е� i ��Ԫ�ص�ֵ  

	int Set(int i);															// �޸�˳����е� i ��Ԫ�ص�ֵ 

	int Delete(int i);														// ɾ��˳����е� i ��Ԫ��   

	int Insert(int i);														// ��˳���� i ��λ�ò���Ԫ�� 

	void Show();															// ��ʾ˳�������Ԫ��

	void Sort();															// ��˳�����Ԫ�ذ�ѧ�Ż򼨵��С��������

	void Empty();															// ��ձ�����������

	bool check(ElemType i);													//���ѧ���Ƿ��ѱ�ʹ��
};

//����ձ�
template<class ElemType>
SqList<ElemType>::SqList(int size) {
	maxLength = size;
	length = 0;
	data =new ElemType [maxLength];
}

//���ݴ�����������Ϣ����˳���
template<class ElemType>
SqList<ElemType>::SqList(ElemType v[], int n, int size) {
	data = v;
	length = n;
	maxLength = size;
}

//��ȡ˳�����
template<class ElemType>
int SqList<ElemType>::GetLength() const{
	return length;
}

//�ж�˳����Ƿ�Ϊ�ձ�
template<class ElemType>
bool SqList<ElemType>::IsEmpty() const{
	if (length > 0) {												//˳�����Ϊ0ʱ��Ϊ�ձ�
		return false;
	}
	return true;
}

//Ԫ�ض�λ
template<class ElemType>
int SqList<ElemType>::Locate() const{

	int loc = 1;
	Data save;														//�洢ѧ��������Ԫ��λ��
	cin >> save.num;

	for (int i = 0; i < length; i++) {
		if (data[i].num == save.num) {								//���ҵ���ͬѧ��ʱ������λ����Ϣ
			cout << loc << endl;
			return loc;
		}
		loc++;
	}
		
	return -1;														//δ�ҵ�����ʧ����Ϣ

}

//��ȡָ��λ��Ԫ��
template<class ElemType>
int SqList<ElemType>::Get(int i) const{

	cout << "ѧ����ѧ��Ϊ:" << data[i-1].num << "\n����Ϊ:" << data[i-1].name << "\n����Ϊ:" << data[i-1].score<<endl;
	return 1;
}

//�޸�ָ��λ��Ԫ��
template<class ElemType>
int SqList<ElemType>::Set(int i) {

	Data save;														//�洢�����޸ĵ���Ϣ

	cout << "������ѧ��ѧ��:" ;
	cin >> save.num;
	cout << "������ѧ������:" ;
	cin >> save.name;
	cout << "������ѧ������:" ;
	cin >> save.score;

	data[i - 1].num = save.num;
	data[i - 1].name = save.name;
	data[i - 1].score = save.score;
	return 1;

}

//ɾ��ָ��λ��Ԫ��
template<class ElemType>
int SqList<ElemType>::Delete(int i) {

	data[i - 1].num = -1;															//��-1��Ϊ����ֵ
	data[i - 1].score = -1;
	length--;
	return 1;
}

//��ӻ���ָ��λ�ò���Ԫ��
template<class ElemType>
int SqList<ElemType>::Insert(int i) {
	Data save1;																//�洢����Ԫ����Ϣ

	//�ж�����λ����Ϣ�Ƿ����Ҫ��
	if (i<0 || i>length) {
		cout << "λ����Ϣ����" << endl;									
		return 0;
	}
	if (i + 1 > maxLength) {
		cout << "����ϵͳ���洢���ޣ�" << endl;
		return 0;
	}

	do {
		cout << "������ѧ��ѧ��:" ;							//ѭ��ֱ�������Ԫ�ط���Ҫ��
		cin >> save1.num;
		cout << "ѧ������:" ;
		cin >> save1.name;
		cout << "ѧ������:" ;
		cin >> save1.score;
	} while (!check(save1));

	//��Ӳ���
	if (i == length) {
		data[i] = save1;
		length++;
		return 1;
	}

	//�������
	for (int j=length; j>i;j--) {
		data[j] = data[j-1];
	}
	data[i] = save1;
	length++;
	return 1;

}

//��ʾ����Ԫ��
template<class ElemType>
void SqList<ElemType>::Show() {

	cout << "ѧ��" <<setw(8)<< "����" <<setw(8)<< "����" << endl;

	for (int i = 0; i < length; i++) {
		if(data[i].num!=-1)
		cout << data[i].num << setw(10)<<data[i].name << setw(9)<<data[i].score << endl;
	}

}

//��ѧ�Ż򼨵��С�����˳���Ԫ������
template<class ElemType>
void SqList<ElemType>::Sort() {

	Data save;														//�洢��Ϣ
	int loc;														//�洢��СԪ��λ��
	int sign;														//�ж��Ƿ���Ҫ���н�������
	int select;														//����ѡ������ʽ

	do {
		cout << "��ѡ������ʽ:\n1.ѧ��\n2.����" << endl;
		cin >> select;
		if (select != 1 && select != 2) {							//ѭ��ֱ���������Ҫ��
			cout << "����������������룡" << endl;	
		}
	} while (select != 1 && select!= 2);
	
	//ѡ������
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

//ͨ������ֵ���˳���
template<class ElemType>
void SqList<ElemType>::Empty() {
	for (int i = 0; i < length; i++) {
		data[i].num = -1;
	}
	length = 0;
	cout << "ѧ����Ϣ�����ɣ�" << endl;
}

//���ѧ���Ƿ�ʹ�ù�
template<class ElemType>
bool SqList<ElemType>::check(ElemType i) {

	for (int j = 0; j < length; j++) {
		if (i.num == data[j].num) {
			cout << "��ѧ���ѱ�ʹ�����������룡\n" << endl;
			return false;
		}
	}

	return true;

}