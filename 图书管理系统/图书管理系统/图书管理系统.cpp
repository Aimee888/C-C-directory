// 图书管理系统.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

#include "BDatabase.h"
#include "RDatabase.h"

int borrow();
int ret();

int main()               //main函数的实现，程序的主界面的引导
{
	char choice = '1';
	int bookid, readerid;
	RDatabase ReaderDB;
	Reader *r;
	BDatabase BookDB;
	Book *b;
	while (choice != '0') {
		cout << endl << endl << "********************    图 书 管 理 系 统    ********************\n\n\n";
		cout << "\t\t\t1    借    书\n\n\t\t\t2    还    书\n\n\t\t\t3    图  书  管  理\n\n\t\t\t4    读  者  管  理\n\n\t\t\t0    离    开" << endl;
		cout << endl << endl << "******************************************************************\n\n\n";
		cout << "请选择需要进行的操作序号：";
		cin >> choice;            //接收用户输入的选项
		switch (choice)
		{
		case '1':        //选择借书模块
			borrow();
			break;

		case '2':       //选择还书模块
			ret();
			break;

		case '3':      //选择图书管理模块
			BookDB.bookdata();
			break;

		case '4':     //选择读者管理模块
			ReaderDB.readerdata();
			break;

		default:
			cout << "输入错误，请重新输入：";
			break;
		}
	}
}

int borrow() {           //借书模块
	int bookid, readerid;          //定义变量
	RDatabase ReaderDB;            //创建对象
	Reader *r;                     //定义对象指针
	BDatabase BookDB;
	Book *b;
	cout << " 借书\n请输入读者编号:" << endl;
	cin >> readerid;
	cout << "请输入图书编号:" << endl;
	cin >> bookid;
	r = ReaderDB.query(readerid);           //按编号查找读者
	if (NULL == r) {                        //读者编号不存在
		cout << " 不存在该读者，不能借书" << endl;
		exit(0);         //正常结束程序
	}
	b = BookDB.query(bookid);              //按编号查找图书
	if (b == NULL) {                       //图书编号不存在
		cout << " 不存在该图书，不能借书" << endl;
		exit(0);
	}
	if (b->borrowbook() == 0) {           //是否借出
		cout << " 该图书已借出，不能借书" << endl;
		exit(0);
	}
	r->borrowbook(b->getno());              //结束
	cout << "借书成功！" << endl;
	return 0;
}

int ret() {              //还书模块
	int bookid, readerid;
	RDatabase ReaderDB;
	Reader *r;
	BDatabase BookDB;            //定义对象指针
	Book *b;
	cout << "还书\n请输入读者编号:";
	cin >> readerid;
	cout << "请输入图书编号:";
	cin >> bookid;
	r = ReaderDB.query(readerid);          //调用读者库的query函数
	if (r == NULL) {                       //未找到读者
		cout << " 不存在该读者，不能还书" << endl;
		exit(0);                   //正常退出
	}
	b = BookDB.query(bookid);        //调用图书库的query函数
	if (b == NULL) {                       //未找到读者
		cout << " 不存在该图书，不能还书" << endl;
		exit(0);                   //正常退出
	}
	b->retbook();             //图书类成员函数还书
	r->retbook(b->getno());         //读者类成员函数还书
	cout << "还书成功！" << endl;
}
