/*********************************************************/
/******************** Author: Aimee **********************/
/******************** Date: 2019/7/11 ********************/
/******************** Version: 0.0.0.1 *******************/
/******************** Destination: For C++ study *********/
/******************** FileName: CPlusPlusStudy.cpp *******/
/*********************************************************/

#include "pch.h"
#include <iostream>


/*********************Function definition************************/
//variable
void Variable_study();
void Bool_study();
void Char_study();
void Wchar_t_study();
void Int_study();
void Float_study();

//constant
void Constant_study();

//operator
void Operator_study();

void Assign_study();
void assign_common_study();
void assign_expression_study();
void MoreVariable_assign();
void Complex_assign();

void DecrementAndIncreament_study();

void Conditional_study();

void Comma_study();

/////////////////////////////////////////////////////////////////
//                    The main() function                      //
/////////////////////////////////////////////////////////////////
int main()
{
	std::cout << "\nThis is main() function\n";

	//Variable_study();
	//Constant_study();
	Operator_study();

	std::cout << "\n===================main() end===================\n";
	return 0;
}

/******************************* variable **************************************/
//variable
void Variable_study() {
	std::cout << "\nThis is Variable_study() function\n";

	Bool_study();
	Char_study();
	Wchar_t_study();
	Int_study();
	Float_study();

	std::cout << "\n===================Variable_study() end===================\n";
}

//bool variable
void Bool_study() {
	std::cout << "\nThis is Bool_study() function\n";

	bool senior;    //bool variable
	senior = true;  //set to true

	//Test the senior variable
	if (senior)
		std::cout << "variable senior's value is true\n";
	else {
		std::cout << "\aError";//"\a" make computer product voice.
		system("pause");
	}

	std::cout << "\n===================Bool_study() end===================\n";
}

//char variable
void Char_study() {
	std::cout << "\nThis is Char_study() function\n";

	char c;            //char variable
	c = 'b';           //assign 'b'
	std::cout << c;    //display 'b'
	c = 'y';           //assign 'y'
	std::cout << c;    //dispaly 'y'
	c = 'e';           //assign 'e'
	std::cout << c;    //display 'e'

	std::cout << "\n===================Char_study() end===================\n";
}

//wchar_t variable
void Wchar_t_study() {
	std::cout << "\nThis is Wchar_t_study() function\n";

	wchar_t wc;          //wide char variable
	wc = 'b';            //assign 'b' to wc
	std::wcout << wc;    //display 'b'
	wc = 'y';            //assgin 'y' to wc
	std::wcout << wc;    //display 'y'
	wc = 'e';            //assign 'e' to wc

	std::cout << "\n===================Wchar_t_study() end===================\n";
}

//int variable
void Int_study() {
	std::cout << "\nThis is Int_study() function\n";

	int Amount;               //an int variable
	Amount = 123;             //assign a value
	std::cout << Amount;      //display the int

	std::cout << "\n===================Int_study() end===================\n";
}

//float variable
void Float_study() {
	std::cout << "\nThis is Float_study() function\n";

	float realValue;        //a float variable
	realValue = 1.2;       //assign a value //warning C4305: '=': truncation from 'double' to 'float'
	std::cout << realValue; //display the float

	std::cout << "\n===================Float_study() end===================\n";
}

/********************************* constant **************************************/
//constant
void Constant_study() {
	std::cout << "\nThis is Constant_study() function\n";

	std::cout <<
		"This is the beginning of a very long message \n"
		"that spans severral lines of code. \n"
		"This format allows a program to build long \n"
		"string constants without going past the \n"
		"program editor's right margin. \n";

	std::cout << "\n===================Constant_study() end===================\n";
}

/************************************** operator *********************************/
//operator
void Operator_study() {
	std::cout << "\nThis is Operator_study() function\n";

	//Assign_study();
	//DecrementAndIncreament_study();
	//Conditional_study();
	Comma_study();

	std::cout << "\n===================Operator_study() end===================\n";
}

/////////////////assignment statement operator
void Assign_study() {
	std::cout << "\nThis is Assign_study() function\n";

	//assign_common_study();
	//assign_expression_study();
	//MoreVariable_assign();
	Complex_assign();

	std::cout << "\n===================Assign_study() end===================\n";
}

//common_assign
void assign_common_study() {
	std::cout << "\nThis is assign_common_study() function\n";

	//Declare three integers
	int HourlyRate;
	int HoursWorked;
	int GrossPay;

	//Assign values to the integers
	HourlyRate = 15;
	HoursWorked = 40;
	GrossPay = HourlyRate * HoursWorked;

	//Display the variables on the screen.
	std::cout << HourlyRate;
	std::cout << ' ';
	std::cout << HoursWorked;
	std::cout << ' ';
	std::cout << GrossPay;

	std::cout << "\n===================assign_common_study() end===================\n";
}

//expression_assign
void assign_expression_study() {
	std::cout << "\nThis is assign_expression_study() function\n";

	int Celsius, Fahrenheit;

	//Prompt for Fahrenheit temperature
	std::cout << "\nEnter temperature as degrees Fahrenheit: ";

	//Read Fahrenheit tempersture from keyboard
	std::cin >> Fahrenheit;

	//Compute Celsius
	Celsius = 5 * (Fahrenheit - 32) / 9;

	//Display the result
	std::cout << "Temperature is ";
	std::cout << Celsius;
	std::cout << " degrees Celsius";

	std::cout << "\n===================assign_expression_study() end===================\n";
}

//continuity_assgin
void MoreVariable_assign() {
	std::cout << "\nThis is MoreVariable_assign() function\n";

	unsigned int This, That, Those;

	//Assign the same value to three variables
	This = That = Those = 66000;

	//Dispaly three ubsigned ints
	std::cout << This;
	std::cout << ' ';
	std::cout << That;
	std::cout << ' ';
	std::cout << Those;

	std::cout << "\n===================MoreVariable_assign() end===================\n";
}

//complex_assign
void Complex_assign() {
	std::cout << "\nThis is Complex_assign() function\n";

	long Total, SubTotal, Detail;

	//Initial values
	Total = 10000;
	SubTotal = 90;
	Detail = 5;
	SubTotal *= Detail;        //compute SubTotal
	Total += SubTotal;         //compute Total

	//Dispaly all three
	std::cout << Total;
	std::cout << ' ';
	std::cout << SubTotal;
	std::cout << ' ';
	std::cout << Detail;

	std::cout << "\n===================Complex_assign() end===================\n";
}

//////////////////decrement and increment
void DecrementAndIncreament_study() {
	std::cout << "\nThis is DecrementAndIncreament_study() function\n";

	int Ctr, OldCtr, NewCtr;

	//Make the assignments
	OldCtr = 123;           //OldCtr is 123
	NewCtr = ++OldCtr;      //NewCtr is 124, OldCtr is 124
	Ctr = NewCtr--;         //Ctr is 124, NewCtr is 123

	//Display the results
	std::cout << OldCtr;
	std::cout << ' ';
	std::cout << NewCtr;
	std::cout << ' ';
	std::cout << Ctr;

	std::cout << "\n===================DecrementAndIncreament_study() end===================\n";
}

//////////////////conditional operator
void Conditional_study() {
	std::cout << "\nThis is Conditional_study() function\n";

	float Dues;        //dues amount

	//Read the dues
	std::cout << "Enter dues amount: ";
	std::cin >> Dues;

	//Are the dues paid on time?
	std::cout << "On time?(y/n)";
	char yn;
	std::cin >> yn;
	bool Overdue;                 //true if overdue, false if on time
	Overdue = yn != 'y';
	float AmountDue;              //amount to be computed

	//Use conditional operator to compute
	AmountDue = Overdue ? Dues * 1.10 : Dues;

	//Display the dues amount
	std::cout << "Amount due: ";
	std::cout << AmountDue;

	std::cout << "\n===================Conditional_study() end===================\n";
}

//////////////////comma operator
void Comma_study() {
	std::cout << "\nThis is Comma_study() function\n";

	int Val, Amt, Tot, Cnt;
	Amt = 30;
	Tot = 12;
	Cnt = 46;

	//Compute Val = rightmost expression
	//Val = (Amt++, --Tot, Cnt + 3);

	//Compute Val = leftmost expression
	Val = Amt++, --Tot, Cnt + 3;

	//Display the result
	std::cout << Val;

	std::cout << "\n===================Comma_study() end===================\n";
}

/******************************* key words **************************************/
//C++ key words
//asm				do				inline				short				typeid
//auto				double			int					signed				typename
//bool				dynamic_cast	long				sizeof				union
//break				else			mutable				static				unsigned
//case				enum			namespace			static_cast			using
//catch				explicit		new					struct				virtual
//char				extern			operator			weitch				void
//class				false			private				template			volatile
//const				float			protected			this				wchar_t
//const_cast		for				public				throw				while
//continue			friend			register			true
//default			goto			reinterpret_cast	try
//delete			if				return				typedef

//C++ international key words
//and				bitor			or					xor_e
//and_eq			compl			or_eq				not_eq
//bitand			not				xor

