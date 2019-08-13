// IsPrimeNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

#include <cmath>

bool IsPrimeNumber(int num);

int main()
{
    cout << "——判断是否是素数——" << endl; 
	int num = 0;
	cout << "请输入一个正整数：" << endl;
	cin >> num;
	while (num > 0) {
		if (IsPrimeNumber(num)) {
			cout << num << "是一个素数" << endl;
		}
		else {
			cout << num << "不是一个素数" << endl;
		}
		cout << endl << "请输入一个正整数：" << endl;
		cin >> num;
		if (num == 0) {
			break;
		}
	}

	return 0;
}

bool IsPrimeNumber(int num) {
	if (1 == num || 2 == num) {
		return true;
	}

	int s = static_cast<int>(sqrt(num));          //求平方根
	for (int i = 2; i <= s; i++) {//从2开始遍历，直到平方根
		if ((num % i) == 0) {        //如果可以整除，则不是素数
			return false;
		}
	}
	return true;
}

