#include "pch.h"
#include "Book.h"

char* Book:: getname() {
	return name;     //获取姓名
}

int Book:: getno() {
	return no;       //获取图书编号
}

int Book:: gettag() {
	return tag;     //获取删除标记
}

void Book:: setname(char na[]) {
	strcpy_s(name, 20, na);              //设置书名
}

void Book:: delbook() {
	tag = 1;          //删除图书
}

void Book:: addbook(int n, char *na) {    //增加图书
	tag = 0;
	no = n;
	strcpy_s(name, 20, na);
	onshelf = 1;
}

int Book:: borrowbook() {    //借书操作
	if (onshelf == 1) {          //当前图书可借
		onshelf = 0;
		return 1;
	}
	return 0;
}

void Book:: retbook() {         //还书操作
	onshelf = 1;
}

void Book:: disp() {
	cout << setw(6) << no << setw(18) << name << setw(10) << (onshelf == 1 ? "可借" : "不可借") << endl;
	//cout << setw(6) << no << setw(18) << name << setw(10) << (onshelf == 1 ? "Yes" : "No") << endl;
}