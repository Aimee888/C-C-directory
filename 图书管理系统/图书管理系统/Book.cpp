#include "pch.h"
#include "Book.h"

char* Book:: getname() {
	return name;     //��ȡ����
}

int Book:: getno() {
	return no;       //��ȡͼ����
}

int Book:: gettag() {
	return tag;     //��ȡɾ�����
}

void Book:: setname(char na[]) {
	strcpy_s(name, 20, na);              //��������
}

void Book:: delbook() {
	tag = 1;          //ɾ��ͼ��
}

void Book:: addbook(int n, char *na) {    //����ͼ��
	tag = 0;
	no = n;
	strcpy_s(name, 20, na);
	onshelf = 1;
}

int Book:: borrowbook() {    //�������
	if (onshelf == 1) {          //��ǰͼ��ɽ�
		onshelf = 0;
		return 1;
	}
	return 0;
}

void Book:: retbook() {         //�������
	onshelf = 1;
}

void Book:: disp() {
	cout << setw(6) << no << setw(18) << name << setw(10) << (onshelf == 1 ? "�ɽ�" : "���ɽ�") << endl;
	//cout << setw(6) << no << setw(18) << name << setw(10) << (onshelf == 1 ? "Yes" : "No") << endl;
}