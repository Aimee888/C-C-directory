/*
	Author: Aimee
	Date : 2019/7/18
	Destination : Pascal's triangle 
	Description : 1. Input a number
	              2. Out put Pascal's triangle

	e.g. if you input a 5
	show:
	    1
	   1 1
	  1 2 1
	 1 3 3 1
	1 4 6 4 1
*/

#include "pch.h"
#include <iostream>
using namespace std;


#include <iomanip>

void Method_one();
void Method_two();

int main()
{
	//Method_one();
	Method_two();
}

void Method_one() {
	int num;
	cout << "Please input line number of Pascal's triangle(1~10) : " << endl;
	cin >> num;
	cout << endl;
	int array_triangle[20][20] = {};//the number should large than input value, of cause equal is more perfect, but array length should be constance
	array_triangle[0][0] = 1;

	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0)//first number every line
				array_triangle[i][j] = array_triangle[i - 1][j];
			else if (j == num - 1)//last number every line
				array_triangle[i][j] = array_triangle[i - 1][j - 1];
			else
				array_triangle[i][j] = array_triangle[i - 1][j] + array_triangle[i - 1][j - 1];
		}
	}


	for (int m = 0; m < num; m++) {
		cout << setw(num - m);
		for (int n = 0; n < num; n++) {
			if (array_triangle[m][n] != 0) {
				cout << array_triangle[m][n] << " ";
			}
		}
		cout << endl;
	}
}

void Method_two() {
	cout << "Please input line number of Pascal's triangle(1~10) : " << endl;
	int n = 0;
	cin >> n;

	int a[20] = { 0 }, b[20] = {0};    //定义两个辅助数组
	int *last = a;     //定义指向数组的指针
	int *current = b;
	for (int i = 0; i < n; i++) {
		current[0] = 1;    //第一个元素为1
		current[i] = 1;    //最后一个元素为1

		for (int j = 1; j < i; j++) {  //对于每行中的其他元素
			current[j] = last[j] + last[j - 1];     //等于上一行中两个相邻元素的和
		}

		for (int j = 0; j < n - i - 1; j++) {    //对于每一行前面的空格
			cout << ' ';     //输出前导的空格
		}

		for (int j = 0; j <= i; j++) { //对于当前行中的每一个元素
			cout << current[j] << ' ';   //输出
		}

		cout << endl;   //换行

		int * temp = current;   //完成本行的计算，改变指针的指向
		current = last;
		last = temp;
	}

	cout << endl;
}

