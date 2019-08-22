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
	strcpy_s(name, 10, na);          //���ö�������
	for (int i = 0; i < Maxbor; i++)
		borbook[i] = 0;        //���������鼮Ϊ��
}

void Reader::borrowbook(int bookid) {
	for (int i = 0; i < Maxbor; i++) {      //С����������Ŀ
		if (borbook[i] == 0) {
			borbook[i] = bookid;        //���������鼮��ͼ����
			return;
		}
	}
}

int Reader::retbook(int bookid) {
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] == bookid) {       //���ö��������鼮�ֶ��ж�Ӧ��ͼ����Ϊ��
			borbook[i] = 0;
			return 1;
		}
	}
	return 0;
}

void Reader::disp() {
	cout << setw(5) << no << setw(10) << name << "�����ţ�[";
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] != 0) {
			cout << borbook[i] << "|";
		}
	}
	cout << "]" << endl;
}