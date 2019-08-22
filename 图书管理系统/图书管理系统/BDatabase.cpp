#include "pch.h"
#include "BDatabase.h"

BDatabase:: BDatabase() {          //���캯������book.txt����book[]��
	Book b;           //����ͼ�����
	top = -1;         //��ʼ��ͼ���¼ָ��
	fstream file;
	//ifstream file;
	file.open("book.txt", ios::in);    //�Զ�ȡ��ʽ�������ļ�book.txt
	//file.open("book.txt");    //�Զ�ȡ��ʽ�������ļ�book.txt
	while (1) {          //��ȡ�����ļ�book.txt�е�ͼ���¼
		file.read((char *)&b, sizeof(b));
		if (!file) break;
		top++;
		book[top] = b;
	}
	file.close();
}

BDatabase::~BDatabase() {           //������������book[]д��book.txt�ļ���
	fstream file("book.txt", ios::out);              //��д�뷽ʽ�������ļ�book.txt
	//ofstream file("book.txt");              //��д�뷽ʽ�������ļ�book.txt
	for (int i = 0; i <= top; i++) {
		if (book[i].gettag() == 0) {
			file.write((char*)&book[i], sizeof(book[i]));
			//file << book[i].gettag();
			//file.write("", 3);
			//file << book[i].getno();
			//file.write("", 3);
			//file.write(book[i].getname(), 20);
			//file.write("", 4);
		}	
	}
	file.close();       //�ر��ļ�
}

void BDatabase:: clear() {     //ȫɾ
	top = -1;
}

void BDatabase::disp() {
	for (int i = 0; i <= top; i++) {
		if (book[i].gettag() == 0) {
			book[i].disp();       //��ʾ��ͼ���¼
		}
	}
}

Book* BDatabase::query(int bookid) {   //����ͼ��
	for (int i = 0; i <= top; i++) {
		if (book[i].getno() == bookid && book[i].gettag() == 0) {
			return &book[i];         //���ز��ҽ��
		}
	}
	return NULL;
}

int BDatabase::addbook(int n, char *na) {    //����ͼ��
	Book *p = query(n);         //�����Ƿ����ظ�ͼ����
	if (NULL == p) {        //��ͼ�������ظ�
		top++;           //��¼ָ���1
		book[top].addbook(n, na);          //����ͼ���������ͼ���Ա����
		return 1;
	}
	return 0;       //��ͼ�����ظ�
}

void BDatabase::bookdata() {    //ά��ͼ���Ա����
	char choice = '1';      //�������
	char bname[40];
	int bookid;
	Book *b;          //����ͼ�����
	while (choice != '0') {      //�����벻����0ʱ
		cout << "\n\n\n**************    ͼ��ά��    **************" << endl << endl;
		cout << "\t\t1    ��    ��\n\t\t2    ��    ��\n\t\t3    ɾ    ��\n\t\t4    ��    ��\n\t\t5    ��    ʾ\n\t\t6    ȫ    ɾ\n\t\t0    ��    ��" << endl;
		cout << "��ѡ�������";
		cin >> choice;     //����ѡ��
		switch (choice)
		{
		case '1':            //ѡ������ͼ�鹦��
			cout << "����ͼ����:" << endl;
			cin >> bookid;
			cout << "����ͼ������:" << endl;
			cin >> bname;
			addbook(bookid,bname);      //����addbook����
			break;

		case '2':         //ѡ�����ͼ�鹦��
			cout << "����ͼ����:" << endl;
			cin >> bookid;
			b = query(bookid);     //����query����
			if (b == NULL) {          //δ�ҵ���ͼ��
				cout << " ��ͼ�鲻���� " << endl;
				break;
			}
			cout << "�����µ�����:" << endl;
			cin >> bname;
			b->setname(bname);     //��������ͼ������
			break;

		case '3':           //ѡ��ɾ��ͼ�鹦��
			cout << "������Ҫɾ����ͼ����:" << endl;
			cin >> bookid;
			b = query(bookid);       //����query����
			if (b == NULL) {
				cout << " ��ͼ�鲻����" << endl;
				break;
			}
			b->delbook();         //ɾ��ͼ��
			break;

		case '4':            //ѡ�����ͼ�鹦��
			cout << "������Ҫ���ҵ�ͼ����:" << endl;
			cin >> bookid;
			b = query(bookid);         //����query����
			if (b == NULL) {
				cout << " ��ͼ�鲻����" << endl;
				break;
			}
			b->disp();          //��ʾ�ҵ���ͼ����Ϣ
			break;

		case '5':                       //ѡ����ʾ����ͼ�鹦��
			disp();
			break;

		case '6':       //ѡ��ȫ��ɾ��ͼ�鹦��
			clear();
			break;

		default:
			cout << "�����������������:";      //���������
			break;
		}
	}
}