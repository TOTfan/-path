#include<iostream>
#include"Node.h"
#include"data.h"
#include"LinkList.h"

using namespace std;

int main() {

	int selection;																	//����ѡ��
	LinkList<struct data> List;														//������������

	cout << "----------��ӭʹ��ѧ����Ϣ����ϵͳ----------"<<endl;

		do {
			cout << "��������ѡ����Ҫ�Ĺ��ܣ�\n1.���ѧ����Ϣ\n2.��ѯѧ����Ϣ\n3.�޸�ѧ����Ϣ\n4.ɾ��ѧ����Ϣ\n5.����ѧ����Ϣ\n6.��ʾ����ѧ����Ϣ\n7.ͳ��ѧ����Ϣ����\n8.ѧ����Ϣ����\n9.���ѧ����Ϣ" << endl;
			cin >> selection;
			switch (selection) {
			//���ѧ����Ϣ
			case 1: { 
				List.Insert(List.GetLength());
				break;
			}
			//��ѯѧ����Ϣ
			case 2:
			{
				int loc = 0;
				cout << "��������Ҫ���ҵ�ѧ��ѧ��:";
				loc=List.Locate();
				if (loc == -1) {
					cout << "�޸���Ϣ������ʧ�ܣ�" << endl;
					break;
				}
				List.Get(loc);
				break;
			}
			//����ѧ����Ϣ
			case 3: {
				int loc = 0;
				cout << "��������Ҫ�޸ĵ�ѧ��ѧ��:";
				loc = List.Locate();
				if (loc == -1) {
					cout << "�޸�ѧ����Ϣ���޷��޸ģ�" << endl;
					break;
				}
				List.Set(loc);
				break;
			}
			//ɾ��ѧ����Ϣ
			case 4: {
				int loc = 0;
				cout << "��������Ҫɾ����ѧ��ѧ��:";
				loc = List.Locate();
				if (loc == -1) {
					cout << "�޸�ѧ����Ϣ!�޷�ɾ����" << endl;
					break;
				}
				List.Delete(loc);
				break;
			}
			//����ѧ����Ϣ
			case 5: {
				int loc = 0;
				struct data save;
				cout << "��������Ҫ����λ��ǰ��ѧ��ѧ��:";
				loc = List.Locate();
				if (loc == -1) {
					cout << "�޸�ѧ����Ϣ������ʧ�ܣ�" << endl;
					break;
				}
				List.Insert(loc);
				break;
			}
			//��ʾ����ѧ����Ϣ
			case 6: {
				List.Show();
				break;
			}
			//ͳ��ѧ������
			case 7: {
				cout << "����ѧ������Ϊ:" << List.GetLength() << "��" << endl;
				break;
			}
			//ͨ��ѧ�Ż򼨵㰴��С�����ѧ����Ϣ��������
			case 8: {
				List.Sort();
				break;
			}
			//���ѧ����Ϣ
			case 9: {
				List.Empty();
				break;
			}

			default: {
				cout << "��������" << endl;
				break;
			}

			}
		} while (selection>=1&&selection<=9);
		return 0;
	}