/*********************************************************/
/******************** Author: zihan **********************/
/******************** Date: 2019/7/13 ********************/
/******************** Version: 0.0.0.2 *******************/
/******************** Destination: For C++ study *********/
/******************** FileName: CPlusPlusStudy.cpp *******/
/*********************************************************/

#include "pch.h"
#include <iostream>
#include "CPlusPlusStudy.h"

/////////////////////////////////////////////////////////////////
//                    The main() function                      //
/////////////////////////////////////////////////////////////////
int main()
{
	std::cout << "\nThis is main() function\n";

	//Caption 5 & 6
	//Scope_study();
	//Struct_study();
	//Union_study();

	//Caption 7 & 8
	Hand_study();


	std::cout << "\n===================main() end===================\n";
	return 0;
}

/////////////////////////////////////////////////////////////////
//                        Caption 5 & 6                        //
/////////////////////////////////////////////////////////////////

/******************************* scope **************************************/
//scope

//A global variable
int amount = 123;
void Scope_study() {
	std::cout << "\nThis is Scope_study() function\n";

	//LocalAndGlobal_variable();
	Static_variable();

	std::cout << "\n===================Scope_study() end===================\n";
}

void LocalAndGlobal_variable() {
	std::cout << "\nThis is LocalAndGlobal_variable() function\n";

	//A local variable with the same
	//name as the global variable
	int amount = 456;

	//Display the value of the global value
	std::cout << ::amount;
	std::cout << ' ';

	//Display the value of the local variable
	std::cout << amount;

	std::cout << "\n===================LocalAndGlobal_variable() end===================\n";
}

//static variable
void Static_variable() {
	std::cout << "\nThis is Static_variable() function\n";

	int gwool = 0;
	while (gwool < 60) {
		gwool = Gather();
		std::cout << gwool << std::endl;
	}

	std::cout << "\n===================Static_variable() end===================\n";
}

//Return the current value of the wool
//static variable
//only the first time initial
int Gather() {
	std::cout << "\nThis is Gather() function\n";

	//A static local variable
	static int wool = 50;

	return ++wool;

	std::cout << "\n===================Gather() end===================\n";
}

/******************************* struct **************************************/
//struct
void Struct_study() {
	std::cout << "\nThis is Struct_study() function\n";

	//Struct_assign();
	//Struct_initial();
	//Struct_nest();
	Date dt = Struct_return();
	PrintDate(dt);

	std::cout << "\n===================Struct_study() end===================\n";
}

//Assign structure
void Struct_assign() {
	std::cout << "\nThis is Struct_assign() function\n";

	//A Date structure
	Date dt;

	//Assign values to the structure members.
	dt.day = 24;
	dt.month = 6;
	dt.year = 1940;

	//Display the structure
	std::cout << dt.month << '/' << dt.day << '/' << dt.year;

	std::cout << "\n===================Struct_assign() end===================\n";
}

//Initial structure
void Struct_initial() {
	std::cout << "\nThis is Struct_initial() function\n";

	//An initialed Date variable
	Date dt = {11, 17, 1941};

	//Display the structure
	std::cout << dt.month << '/' << dt.day << '/' << dt.year;

	std::cout << "\n===================Struct_initial() end===================\n";
}

//structure nesting
void Struct_nest() {
	std::cout << "\nThis is Struct_nest() function\n";

	//An initialized Employee structure
	Employee joe = { 123, 35500, {5, 17, 82} };

	//Display the Employee information
	std::cout << "Empl # : " << joe.emplno << std::endl
		<< "Salary: " << joe.salary << std::endl
		<< "Date hired: "
		<< joe.datehired.month << '/'
		<< joe.datehired.day << '/'
		<< joe.datehired.year << std::endl;

	std::cout << "\n===================Struct_nest() end===================\n";
}

//return a structure
Date Struct_return() {
	std::cout << "\nThis is Struct_return() function\n";

	Date dt;
	std::cout << "Enter date (mm dd yy): ";
	std::cin >> dt.month >> dt.day >> dt.year;
	

	std::cout << "\n===================Struct_return() end===================\n";

	return dt;
}

//accepts a structure
void PrintDate(Date dt) {
	std::cout << "\nThis is PrintDate(Date dt) function\n";

	std::cout << dt.month << '/';
	std::cout << dt.day << '/' << dt.year;

	std::cout << "\n===================PrintDate(Date dt) end===================\n";
}

/******************************* union **************************************/
void Union_study() {
	std::cout << "\nThis is Union_study() function\n";

	Union_initial();

	std::cout << "\n===================Union_study() end===================\n";
}

//initial union
void Union_initial() {
	std::cout << "\nThis is Union_initial() function\n";

	Holder hld;

	//Assign to first member
	hld.holdchar = 'X';
	char value_char[] = "char";
	DisplayHolder(hld, value_char);
	//Assign to second member
	hld.holdint = 12345;
	char value_int[] = "int";
	DisplayHolder(hld, value_int);
	//Assign to third member
	hld.holdlong = 7654321;
	char value_long[] = "long";
	DisplayHolder(hld, value_long);
	//Assign to fourth member
	hld.holdfloat = 1.23;
	char value_float[] = "float";
	DisplayHolder(hld, value_float);

	std::cout << "\n===================Union_initial() end===================\n";
}

//Display the current value of the Holder union
void DisplayHolder(Holder hld, char *tag) {
	std::cout << "\nThis is DisplayHolder(Holder hld, char *tag) function\n";

	std::cout << "---Initialized " << tag << "---"
		<< std::endl;
	std::cout << "holdchar " << hld.holdchar << std::endl;
	std::cout << "holdint " << hld.holdint << std::endl;
	std::cout << "holdlong " << hld.holdlong << std::endl;
	std::cout << "holdfloat " << hld.holdfloat << std::endl;

	std::cout << "\n===================DisplayHolder(Holder hld, char *tag) end===================\n";
}


/////////////////////////////////////////////////////////////////
//                        Caption 7 & 8                        //
/////////////////////////////////////////////////////////////////

/******************************* hand **************************************/
void Hand_study() {
	std::cout << "\nThis is Hand_study() function\n";

	//Storage_study();
	release_hand();

	std::cout << "\n===================Hand_study() end===================\n";
}

//allocate storage
int a = 0;           //global varieable, store in global/static storage area
void Storage_study() {
	std::cout << "\nThis is Storage_study() function\n";

	int b;          // local variable，store in stack
	int *p = new int();      //allocate by operational character "new"，store in heap
	static int d;            //static vareable，store in global/static storage area
	const int e = 0;         //constant，store in constant storage area
	delete p;                //release the storage of heap

	std::cout << "\n===================Storage_study() end===================\n";
}

void release_hand() {
	std::cout << "\nThis is release_hand() function\n";

	int *pCount = new int;
	std::cout << "Please input the length of the array : " << std::endl;
	std::cin >> *pCount;
	std::cout << "Please input the value of the array : " << std::endl;
	int *pArray = new int[*pCount];
	for (int i = 0; i < *pCount; i++) {
		std::cin >> pArray[i];
	}
	std::cout << "Array's value as below : \n" << std::endl;
	for (int j = 0; j < *pCount; j++) {
		std::cout << "pArray[" << j << "] = " << pArray[j] << "\t";
	}

	std::cout << std::endl;
	delete pCount;
	delete pArray;

	std::cout << "\n===================release_hand() end===================\n";
}

int a;   //定义一个变量
const int &b = a;    //定义一个上述变量的引用
a = 1;   //正确，可以修饰变量
b = 2;   //错误，不可以通过常饮用修改变量
