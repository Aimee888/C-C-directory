#include "pch.h"
#include "Reader.h"



Reader::Reader()
{
}


Reader::~Reader()
{
}

char* Reader::getname() {
	return name;
}

int Reader::gettag() {
	return tag;
}

int Reader::getno() {
	return no;
}

void Reader::setname(char na[]) {
	strcpy_s(name, 10, na);
}

void Reader::delreader() {
	tag = 1;
}

void Reader::addreader(int n, char *na) {
	tag = 0;
	no = n;
	strcpy_s(name, 10, na);          //设置读者姓名
	for (int i = 0; i < Maxbor; i++)
		borbook[i] = 0;        //设置所借书籍为空
}

void Reader::borrowbook(int bookid) {
	for (int i = 0; i < Maxbor; i++) {      //小于最大借书数目
		if (borbook[i] == 0) {
			borbook[i] = bookid;        //设置所借书籍的图书编号
			return;
		}
	}
}

int Reader::retbook(int bookid) {
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] == bookid) {       //设置读者所借书籍字段中对应的图书编号为空
			borbook[i] = 0;
			return 1;
		}
	}
	return 0;
}

void Reader::disp() {
	cout << setw(5) << no << setw(10) << name << "借书编号：[";
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] != 0) {
			cout << borbook[i] << "|";
		}
	}
	cout << "]" << endl;
}