#include "pch.h"
#include <iostream>
using namespace std;

#define len 10  //define array length equal 10

//function prototype
void compare(int &a, int &b);

int break_node = 0;//when break_node is true, jump the loop

int main()
{
	//Bubble sort
	
	//define an array which length is 10
	int array_sort[len];

	//input array value
	cout << "Please input " << len << " number: " << endl;
	for (int i = 0; i < len; i++)
		cin >> array_sort[i];


	//start sort
	for (int m = len; m > 0; m--) {
		for (int j = 0; j < m - 1; j++) {
			compare(array_sort[j],array_sort[j+1]);
		}
		if (break_node) {
			break_node = 0;
		}
		else {//while no change data in inner loop, jump out the external loop
			break;
		}
	}

	//output sorted array(high-->low)
	cout << "Sorted array: " << endl;
	for (int k = 0; k < len; k++) {
		cout << array_sort[k] << " ";
	}
	cout << endl;
}

void compare(int &a, int &b) {
	if (a >= b);
	else {
		int temp;
		temp = a;
		a = b;
		b = temp;
		break_node++;
	}
}

