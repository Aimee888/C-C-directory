// Fibonacci_study.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "method.h"
using namespace std;

bool isZero(int x);
bool isZero(double x);
bool isZero(char x);
void isZero_start();

typedef bool(*FUN_PTR) (int a, int b);

//bool less(int a, int b);
//bool big(int a, int b);
void sort(int ary[], int n, FUN_PTR pf);

int main()
{
	cout << "——使用函数指针确定排序标准——" << endl;
	int ary[3] = {5, 3, 6};

	bool less(int a, int b);     //声明函数less
	sort(ary, 3, &less);         //使用less回调函数，从大到小排列数组

	for (int i = 0; i < 3; i++) {
		cout << ary[i] << ' ';
	}
	cout << endl;

	bool big(int a, int b);      //声明函数big
	sort(ary, 3, &big);          //使用big回调函数，从小到大排列数组

	for (int i = 0; i < 3; i++) {
		cout << ary[i] << ' ';
	}
	cout << endl;

	return 0;
}

void sort(int ary[], int n, FUN_PTR pf) {
	for (int i = 0; i < n - 1; i++) {
		int index = i;
		int val = ary[i];
		for (int j = i + 1; j < n; j++) {
			if (pf(val, ary[j])) {
				val = ary[j];
				index = j;
			}
		}
		if (val != ary[i]) {
			ary[index] = ary[i];
			ary[i] = val;
		}
	}
}

bool less(int a, int b) {
	return a < b;
}

bool big(int a, int b) {
	return a > b;
}


void isZero_start()
{
	cout << "Is zero?" << endl;
	cout << 1 << '\t' << isZero(1) << endl;
	cout << 0 << '\t' << isZero(0) << endl;
	cout << 1.0 << '\t' << isZero(1.0) << endl;
	cout << 1e-5 << '\t' << isZero(1e-5) << endl;
	cout << 1e-7 << '\t' << isZero(1e-7) << endl;
	cout << 'a' << '\t' << isZero('a') << endl;
	cout << '0' << '\t' << isZero('0') << endl;
}

bool isZero(int x) {
	return 0 == x;
}

bool isZero(double x) {
	return -1e-6 < x && x < 1e-6;
}

bool isZero(char x) {
	return '0' == x;
}

void smallest() {
	int x = 0, y = 0;
	cout << "请输入两个整数：" << endl;
	cin >> x;
	cin >> y;
	cout << "最小值：" << min(x, y) << endl;
}

int Fibonacci(int n) {
	if (1 == n || 2 == n) {
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void Fibonacci_test() {
	cout << "Fibonacci数列中的第n个数： " << endl;
	int n = 0;        //变量n
	cout << "请输入n：";
	cin >> n;
	while (0 < n) {
		cout << "F(" << n << ") == " << Fibonacci(n) << endl << endl;
		cout << "请输入n：";
		cin >> n;
	}
	cout << "Hello World!\n";
}



