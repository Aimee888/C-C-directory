#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class Book       //ͼ���࣬ʵ�ֶ�ͼ���������ͼ��ı�š�����������������
{
private:
	int tag;           //ɾ����ǣ�1����ɾ��0��δɾ
	int no;            //ͼ����
	char name[20];     //����
	int onshelf;       //�Ƿ�ɽ裬1���ɽ裬2�����ɽ�

public:
	Book() {}            //���캯��

	char *getname();

	int getno();

	int gettag();

	void setname(char na[]);

	void delbook();

	void addbook(int n, char *na);

	int borrowbook();

	void retbook();

	void disp();
};
