#include "pch.h"
#include "RDatabase.h"


RDatabase::RDatabase()
{
	Reader s;
	top = -1;
	fstream file("reader.txt", ios::in);       //打开一个输入文件
	while (1) {
		file.read((char*)&s, sizeof(s));
		if (!file) break;
		top++;
		read[top] = s;
	}
	file.close(); //关闭reader.txt
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

int RDatabase::addreader(int n, char *na) {      //添加读者时先查找是否存在
	Reader *p = query(n);        //首先查找读者
	if (p == NULL) {             //未找到该读者编号
		top++;
		read[top].addreader(n, na);
		return 1;
	}
	return 0;
}

void RDatabase::readerdata() {
	char choice = '1';       //定义变量
	char rname[20];
	int readerid;
	Reader *r;           //创建对象
	while (choice != '0') {
		cout << "\n\n\n**************    读者维护    **************" << endl << endl;
		cout << "\t\t1    新    增\n\t\t2    更    改\n\t\t3    删    除\n\t\t4    查    找\n\t\t5    显    示\n\t\t6    全    删\n\t\t0    退    出" << endl;
		cout << "请选择操作：";
		cin >> choice;     //输入选项
		switch (choice)
		{
		case '1':            //选择新增读者功能
			cout << "输入读者编号:" << endl;
			cin >> readerid;
			cout << "输入读者姓名:" << endl;
			cin >> rname;
			addreader(readerid, rname);      //调用addreader函数
			break;

		case '2':         //选择更改读者功能
			cout << "输入读者编号:" << endl;
			cin >> readerid;
			r = query(readerid);     //调用query函数
			if (r == NULL) {          //未找到该图书
				cout << " 该读者不存在 " << endl;
				break;
			}
			cout << "输入新的姓名:" << endl;
			cin >> rname;
			r->setname(rname);     //重新设置读者姓名
			break;

		case '3':           //选择删除读者功能
			cout << "请输入要删除的读者编号:" << endl;
			cin >> readerid;
			r = query(readerid);       //调用query函数
			if (r == NULL) {
				cout << " 该读者不存在" << endl;
				break;
			}
			r->delreader();         //删除读者
			break;

		case '4':            //选择查找读者功能
			cout << "请输入要查找的读者编号:" << endl;
			cin >> readerid;
			r = query(readerid);         //调用query函数
			if (r == NULL) {
				cout << " 该读者不存在" << endl;
				break;
			}
			r->disp();          //显示找到的读者信息
			break;

		case '5':                       //选择显示所有读者功能
			disp();
			break;

		case '6':       //选择全部删除读者功能
			clear();
			break;

		default:
			cout << "输入错误，请重新输入:";      //错误的输入
			break;
		}
	}
}
