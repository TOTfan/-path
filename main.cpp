#include<iostream>
#include"Node.h"
#include"data.h"
#include"LinkList.h"

using namespace std;

int main() {

	int selection;																	//功能选择
	LinkList<struct data> List;														//创建操作对象

	cout << "----------欢迎使用学生信息管理系统----------"<<endl;

		do {
			cout << "输入数字选择需要的功能：\n1.添加学生信息\n2.查询学生信息\n3.修改学生信息\n4.删除学生信息\n5.插入学生信息\n6.显示所有学生信息\n7.统计学生信息个数\n8.学生信息排序\n9.清空学生信息" << endl;
			cin >> selection;
			switch (selection) {
			//添加学生信息
			case 1: { 
				List.Insert(List.GetLength());
				break;
			}
			//查询学生信息
			case 2:
			{
				int loc = 0;
				cout << "请输入需要查找的学生学号:";
				loc=List.Locate();
				if (loc == -1) {
					cout << "无该信息！查找失败！" << endl;
					break;
				}
				List.Get(loc);
				break;
			}
			//更新学生信息
			case 3: {
				int loc = 0;
				cout << "请输入需要修改的学生学号:";
				loc = List.Locate();
				if (loc == -1) {
					cout << "无该学生信息！无法修改！" << endl;
					break;
				}
				List.Set(loc);
				break;
			}
			//删除学生信息
			case 4: {
				int loc = 0;
				cout << "请输入需要删除的学生学号:";
				loc = List.Locate();
				if (loc == -1) {
					cout << "无该学生信息!无法删除！" << endl;
					break;
				}
				List.Delete(loc);
				break;
			}
			//插入学生信息
			case 5: {
				int loc = 0;
				struct data save;
				cout << "请输入需要插入位置前的学生学号:";
				loc = List.Locate();
				if (loc == -1) {
					cout << "无该学生信息！插入失败！" << endl;
					break;
				}
				List.Insert(loc);
				break;
			}
			//显示所有学生信息
			case 6: {
				List.Show();
				break;
			}
			//统计学生人数
			case 7: {
				cout << "表中学生人数为:" << List.GetLength() << "人" << endl;
				break;
			}
			//通过学号或绩点按从小到大对学生信息进行排序
			case 8: {
				List.Sort();
				break;
			}
			//清空学生信息
			case 9: {
				List.Empty();
				break;
			}

			default: {
				cout << "输入有误！" << endl;
				break;
			}

			}
		} while (selection>=1&&selection<=9);
		return 0;
	}