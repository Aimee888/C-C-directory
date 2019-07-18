#include "pch.h"
#include <iostream>
using namespace std;

#define len 10  //定义数组长度

//函数定义
void compare(int &a, int &b);

int main()
{
	//冒泡排序
	
	//定义一个长度为10输入数组
	int array_sort[len];

	//输入排序前数组
	for (int i = 0; i < len; i++)
		cin >> array_sort[i];


	//排序
	for (int m = len; m > 0; m--) {
		for (int j = 0; j < 9; j++) {
			compare(array_sort[j],array_sort[j+1]);
		}
	}

	//输出排序后的数组
	for (int k = 0; k < len; k++) {
		cout << array_sort[k] << endl;
	}
}

void compare(int &a, int &b) {
	if (a >= b);
	else {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
}

