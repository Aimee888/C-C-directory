#pragma once
#include "Book.h"
#include <iostream>
#include <fstream>
using namespace std;

#define Maxb 100
class BDatabase         //ͼ����࣬ʵ�ֶ�ͼ���ά�������ҡ�ɾ����
{
private:
	int top;     //ͼ���¼ָ��
	Book book[Maxb];      //ͼ���¼

	

public:
	BDatabase();
	~BDatabase();

	void clear();
	int addbook(int n, char *na);      //����ͼ��
	Book *query(int bookid);          //����ͼ��
	void bookdata();                  //ͼ���ά��
	void disp();
};
