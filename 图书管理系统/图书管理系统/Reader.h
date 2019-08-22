#pragma once
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define Maxbor 5
class Reader         //读者类，实现对读者信息的描述
{
public:
	Reader();
	~Reader();

private:
	int tag;          //删除标记，1：已删，0：未删
	int no;           //读者编号
	char name[10];    //读者姓名
	int borbook[Maxbor];    //所借图书

public:
	char *getname();        //获取姓名
	int gettag();           //获取删除标记
	int getno();            //获取读者编号
	void setname(char na[]);      //设置姓名
	void delreader();             //设置删除标记，1：已删，0：未删
	void addreader(int n, char *na);        //增加读者
	void borrowbook(int bookid);          //借书操作
	int retbook(int bookid);              //还书操作
	void disp();             //读出读者信息
};

