/*
	Author : Aimee
	Date : 2019/7/18

	version : 1.0.0.1
	Destination : Sort the name string
*/

#include "pch.h"
#include <iostream>
using namespace std;

#define len_num 20
#define len_name 20

int main()
{
	bool tag_exit = false;
	char name_array[len_num][len_name];
	cout << "Please enter names, ending with # : \n";
	char name[len_name];
	//input the first name
	cin >> name;
	//Assign the name to name_array
	for (int j = 0; j < len_name; j++) {
		name_array[0][j] = name[j];
	}
	int i;//This number use to get how many names have been input
	for (i = 1; i < len_num; i++) {//circle the name array line
		char name[len_name];
		cin >> name;
		if (strcmp(name, "#") == 0)//Jump out circle when meet "#"
			break;
		
		int k = 0;//This number is to get insertion point 
		for (; k < i; k++) {
			int cmp = strcmp(name, name_array[k]);
			if (cmp < 0) {//reurn k as input name lower than the name at k
				break;
			}
		}
		
		for (int m = i; m > k; m--) {//behind k move the name to next
			strcpy_s(name_array[m], len_name, name_array[m-1]);
		}

		//set the name at k is just input name
		for (int j = 0; j < len_name; j++) {//Assign the name to name_array
			name_array[k][j] = name[j];
		}
	}
	//out put the sorted name
	for (int n = 0; n < i; n++) {
		cout << name_array[n] << endl;
	}
	

}
