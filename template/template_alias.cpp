/*
 * tempate_alisa.cpp
 *
 *  Created on: Jan 20, 2021
 *      Author: jiadong
 */


#include "template_alias.hpp"
#include<typeinfo>

void test_template_alias(){

	int_exact<8> a = 7;
	int_exact<9> b = 6;

	std::cout<< typeid(a).name()<<std::endl;
	std::cout<< typeid(b).name()<<std::endl;


	static_assert(std::is_same<decltype(a),int_exact<8>>::value, "a is not int_exact<8>");
//	static_assert(std::is_same<decltype(a),int_exact<6>>::value, "a is not int_exact<8>");
}
