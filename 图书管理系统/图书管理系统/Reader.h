#pragma once
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define Maxbor 5
class Reader         //�����࣬ʵ�ֶԶ�����Ϣ������
{
public:
	Reader();
	~Reader();

private:
	int tag;          //ɾ����ǣ�1����ɾ��0��δɾ
	int no;           //���߱��
	char name[10];    //��������
	int borbook[Maxbor];    //����ͼ��

public:
	char *getname();        //��ȡ����
	int gettag();           //��ȡɾ�����
	int getno();            //��ȡ���߱��
	void setname(char na[]);      //��������
	void delreader();             //����ɾ����ǣ�1����ɾ��0��δɾ
	void addreader(int n, char *na);        //���Ӷ���
	void borrowbook(int bookid);          //�������
	int retbook(int bookid);              //�������
	void disp();             //����������Ϣ
};

