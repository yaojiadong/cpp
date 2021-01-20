/*
 * main.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */

#include<vector>
#include<utility>
#include<memory>
#include<iostream>


//#include "typeid/typeid.hpp"
//#include "template/templates.hpp"
//#include "ctor/default_ctor.hpp"
//#include "template/template_alias.hpp"
//#include "tic-tac-toe/Tic-Tac-Toe.h"
#include"lambda/lambda.h"
#include"rvalue/rvalue.h"
#include "parameter_pack_auto/par_pack_auto.h"

using namespace std;

#if __cplusplus
#endif


int main(){

//	test_typeid();
//	test_typeid_poly();

//	test_templates();
//	X x;

//	test template alias


//	int_exact<8> a = 7;
//
//	cout<< typeid(a).name()<<endl;
//
//	decltype(a) x = 'a';
//


//	test_rvalue();
//	test_lambda();


	test_par_pack_auto();
	return 0;
}

