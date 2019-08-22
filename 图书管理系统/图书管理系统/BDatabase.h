#pragma once
#include "Book.h"
#include <iostream>
#include <fstream>
using namespace std;

#define Maxb 100
class BDatabase         //图书库类，实现对图书的维护、查找、删除等
{
private:
	int top;     //图书记录指针
	Book book[Maxb];      //图书记录

	

public:
	BDatabase();
	~BDatabase();

	void clear();
	int addbook(int n, char *na);      //增加图书
	Book *query(int bookid);          //查找图书
	void bookdata();                  //图书库维护
	void disp();
};
