/*
 * test_operator_overloading.cpp
 *
 *  Created on: Mar 19, 2021
 *      Author: jiado
 */


#include "My_integer.h"


ostream& operator<<(ostream& os,  const My_integer &myinti){
	cout << myinti.m_Num;
	return os;
}


void test_operator_overloading(){

	My_integer aInit{2};
	My_integer bInit{3};
	My_integer cInit{4};
	My_integer dInit{4};

//	MyInteger myInit = aInit + bInit;
//	MyInteger myInit = aInit + bInit + cInit;
	aInit += bInit + cInit + dInit;

	cout << aInit <<endl;
}

