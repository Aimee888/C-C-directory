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

int main()
{
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
			else if(j == num -1)//last number every line
				array_triangle[i][j] = array_triangle[i - 1][j-1];
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

