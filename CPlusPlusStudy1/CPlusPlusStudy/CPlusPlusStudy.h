#pragma once

/******************************* struct **************************************/
//Date structure
struct Date {

	short int month, day, year;
};

//Employee structure
struct Employee {
	int emplno;
	float salary;
	Date datehired;
};

/******************************* union **************************************/
//Declare the Holder structure
union Holder {
	char holdchar;
	short int holdint;
	long int holdlong;
	float holdfloat;
};

/*********************Function prototype************************/

///////////////////////// Caption 5 & 6 //////////////////////////
//scope
void Scope_study();
void LocalAndGlobal_variable();
void Static_variable();
int Gather();

//struct
void Struct_study();
void Struct_assign();
void Struct_initial();
void Struct_nest();
Date Struct_return();
void PrintDate(Date dt);

//union
void Union_study();
void Union_initial();
void DisplayHolder(Holder hld, char *tag);

///////////////////////// Caption 7 & 8 //////////////////////////
//hand
void Hand_study();
void Storage_study();
void release_hand();
