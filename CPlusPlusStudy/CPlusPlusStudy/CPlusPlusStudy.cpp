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
void Variable_study();
void Bool_study();
void Char_study();
void Wchar_t_study();
void Int_study();
void Float_study();

/////////////////////////////////////////////////////////////////
//                    The main() function                      //
/////////////////////////////////////////////////////////////////
int main()
{
	std::cout << "\nThis is main() function\n";
	Variable_study();
	return 0;
}

//variable
void Variable_study() {
	std::cout << "\nThis is Variable_study() function\n";
	Bool_study();
	Char_study();
	Wchar_t_study();
	Int_study();
	Float_study();
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
}

//int variable
void Int_study() {
	std::cout << "\nThis is Int_study() function\n";
	int Amount;               //an int variable
	Amount = 123;             //assign a value
	std::cout << Amount;      //display the int
}

//float variable
void Float_study() {
	std::cout << "\nThis is Float_study() function\n";
	float realValue;        //a float variable
	realValue = 1.2;       //assign a value //warning C4305: '=': truncation from 'double' to 'float'
	std::cout << realValue; //display the float
}

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

