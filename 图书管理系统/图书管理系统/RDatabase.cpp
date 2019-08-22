#include "pch.h"
#include "RDatabase.h"


RDatabase::RDatabase()
{
	Reader s;
	top = -1;
	fstream file("reader.txt", ios::in);       //��һ�������ļ�
	while (1) {
		file.read((char*)&s, sizeof(s));
		if (!file) break;
		top++;
		read[top] = s;
	}
	file.close(); //�ر�reader.txt
}


RDatabase::~RDatabase()
{
	fstream file("reader.txt", ios::out);
	for (int i = 0; i <= top; i++) {
		if (read[i].gettag() == 0) {
			file.write((char*)&read[i], sizeof(read[i]));
		}
	}
	file.close();
}

void RDatabase::clear() {
	top = -1;
}

void RDatabase::disp() {
	for (int i = 0; i <= top; i++) {
		read[i].disp();
	}
}

Reader* RDatabase::query(int readerid) {
	for (int i = 0; i <= top; i++) {
		if (read[i].getno() == readerid && read[i].gettag() == 0) {
			return &read[i];
		}
	}
	return NULL;
}

int RDatabase::addreader(int n, char *na) {      //��Ӷ���ʱ�Ȳ����Ƿ����
	Reader *p = query(n);        //���Ȳ��Ҷ���
	if (p == NULL) {             //δ�ҵ��ö��߱��
		top++;
		read[top].addreader(n, na);
		return 1;
	}
	return 0;
}

void RDatabase::readerdata() {
	char choice = '1';       //�������
	char rname[20];
	int readerid;
	Reader *r;           //��������
	while (choice != '0') {
		cout << "\n\n\n**************    ����ά��    **************" << endl << endl;
		cout << "\t\t1    ��    ��\n\t\t2    ��    ��\n\t\t3    ɾ    ��\n\t\t4    ��    ��\n\t\t5    ��    ʾ\n\t\t6    ȫ    ɾ\n\t\t0    ��    ��" << endl;
		cout << "��ѡ�������";
		cin >> choice;     //����ѡ��
		switch (choice)
		{
		case '1':            //ѡ���������߹���
			cout << "������߱��:" << endl;
			cin >> readerid;
			cout << "�����������:" << endl;
			cin >> rname;
			addreader(readerid, rname);      //����addreader����
			break;

		case '2':         //ѡ����Ķ��߹���
			cout << "������߱��:" << endl;
			cin >> readerid;
			r = query(readerid);     //����query����
			if (r == NULL) {          //δ�ҵ���ͼ��
				cout << " �ö��߲����� " << endl;
				break;
			}
			cout << "�����µ�����:" << endl;
			cin >> rname;
			r->setname(rname);     //�������ö�������
			break;

		case '3':           //ѡ��ɾ�����߹���
			cout << "������Ҫɾ���Ķ��߱��:" << endl;
			cin >> readerid;
			r = query(readerid);       //����query����
			if (r == NULL) {
				cout << " �ö��߲�����" << endl;
				break;
			}
			r->delreader();         //ɾ������
			break;

		case '4':            //ѡ����Ҷ��߹���
			cout << "������Ҫ���ҵĶ��߱��:" << endl;
			cin >> readerid;
			r = query(readerid);         //����query����
			if (r == NULL) {
				cout << " �ö��߲�����" << endl;
				break;
			}
			r->disp();          //��ʾ�ҵ��Ķ�����Ϣ
			break;

		case '5':                       //ѡ����ʾ���ж��߹���
			disp();
			break;

		case '6':       //ѡ��ȫ��ɾ�����߹���
			clear();
			break;

		default:
			cout << "�����������������:";      //���������
			break;
		}
	}
}
