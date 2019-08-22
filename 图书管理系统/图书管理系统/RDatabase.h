#pragma once
#include "Reader.h"
#include <iostream>
#include <fstream>
using namespace std;

#define Maxr 100
class RDatabase          //读者库类，实现建立读者的个人资料
{
public:
	RDatabase();   //构造函数，将reader.txt读到read[]中
	~RDatabase();      //析构函数，将read[]写到reader.txt文件中

public:
	void clear();          //删除所有读者信息
	int addreader(int n, char *na);       //添加读者时先查找是否存在
	Reader *query(int readerid);          //按编号查找
	void disp();         //输出所有读者信息
	void readerdata();        //读者库维护

private:
	int top;           //读者记录指针
	Reader read[Maxr];     //读者记录
};

