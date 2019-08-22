#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class Book       //图书类，实现对图书的描述，图书的编号、书名、借出、还入等
{
private:
	int tag;           //删除标记，1：已删，0：未删
	int no;            //图书编号
	char name[20];     //书名
	int onshelf;       //是否可借，1：可借，2：不可借

public:
	Book() {}            //构造函数

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
