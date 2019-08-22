#pragma once
#include "Reader.h"
#include <iostream>
#include <fstream>
using namespace std;

#define Maxr 100
class RDatabase          //���߿��࣬ʵ�ֽ������ߵĸ�������
{
public:
	RDatabase();   //���캯������reader.txt����read[]��
	~RDatabase();      //������������read[]д��reader.txt�ļ���

public:
	void clear();          //ɾ�����ж�����Ϣ
	int addreader(int n, char *na);       //��Ӷ���ʱ�Ȳ����Ƿ����
	Reader *query(int readerid);          //����Ų���
	void disp();         //������ж�����Ϣ
	void readerdata();        //���߿�ά��

private:
	int top;           //���߼�¼ָ��
	Reader read[Maxr];     //���߼�¼
};

