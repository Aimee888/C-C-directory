#include "pch.h"
#include "BDatabase.h"

BDatabase:: BDatabase() {          //构造函数，将book.txt读到book[]中
	Book b;           //定义图书对象
	top = -1;         //初始化图书记录指针
	fstream file;
	//ifstream file;
	file.open("book.txt", ios::in);    //以读取方式打开数据文件book.txt
	//file.open("book.txt");    //以读取方式打开数据文件book.txt
	while (1) {          //读取数据文件book.txt中的图书记录
		file.read((char *)&b, sizeof(b));
		if (!file) break;
		top++;
		book[top] = b;
	}
	file.close();
}

BDatabase::~BDatabase() {           //析构函数，将book[]写到book.txt文件中
	fstream file("book.txt", ios::out);              //以写入方式打开数据文件book.txt
	//ofstream file("book.txt");              //以写入方式打开数据文件book.txt
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
	file.close();       //关闭文件
}

void BDatabase:: clear() {     //全删
	top = -1;
}

void BDatabase::disp() {
	for (int i = 0; i <= top; i++) {
		if (book[i].gettag() == 0) {
			book[i].disp();       //显示该图书记录
		}
	}
}

Book* BDatabase::query(int bookid) {   //查找图书
	for (int i = 0; i <= top; i++) {
		if (book[i].getno() == bookid && book[i].gettag() == 0) {
			return &book[i];         //返回查找结果
		}
	}
	return NULL;
}

int BDatabase::addbook(int n, char *na) {    //增加图书
	Book *p = query(n);         //查找是否有重复图书编号
	if (NULL == p) {        //该图书编号无重复
		top++;           //记录指针加1
		book[top].addbook(n, na);          //调用图书类的增加图书成员函数
		return 1;
	}
	return 0;       //该图书编号重复
}

void BDatabase::bookdata() {    //维护图书成员函数
	char choice = '1';      //定义变量
	char bname[40];
	int bookid;
	Book *b;          //创建图书对象
	while (choice != '0') {      //当输入不等于0时
		cout << "\n\n\n**************    图书维护    **************" << endl << endl;
		cout << "\t\t1    新    增\n\t\t2    更    改\n\t\t3    删    除\n\t\t4    查    找\n\t\t5    显    示\n\t\t6    全    删\n\t\t0    退    出" << endl;
		cout << "请选择操作：";
		cin >> choice;     //输入选项
		switch (choice)
		{
		case '1':            //选择新增图书功能
			cout << "输入图书编号:" << endl;
			cin >> bookid;
			cout << "输入图书书名:" << endl;
			cin >> bname;
			addbook(bookid,bname);      //调用addbook函数
			break;

		case '2':         //选择更改图书功能
			cout << "输入图书编号:" << endl;
			cin >> bookid;
			b = query(bookid);     //调用query函数
			if (b == NULL) {          //未找到该图书
				cout << " 该图书不存在 " << endl;
				break;
			}
			cout << "输入新的书名:" << endl;
			cin >> bname;
			b->setname(bname);     //重新设置图书名称
			break;

		case '3':           //选择删除图书功能
			cout << "请输入要删除的图书编号:" << endl;
			cin >> bookid;
			b = query(bookid);       //调用query函数
			if (b == NULL) {
				cout << " 该图书不存在" << endl;
				break;
			}
			b->delbook();         //删除图书
			break;

		case '4':            //选择查找图书功能
			cout << "请输入要查找的图书编号:" << endl;
			cin >> bookid;
			b = query(bookid);         //调用query函数
			if (b == NULL) {
				cout << " 该图书不存在" << endl;
				break;
			}
			b->disp();          //显示找到的图书信息
			break;

		case '5':                       //选择显示所有图书功能
			disp();
			break;

		case '6':       //选择全部删除图书功能
			clear();
			break;

		default:
			cout << "输入错误，请重新输入:";      //错误的输入
			break;
		}
	}
}