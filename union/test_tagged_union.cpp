/*
 * test_tagged_union.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */



#include <iostream>
#include "Tagged_union.h"

void test_tagged_union(){
	Tagged_union tu1, tu2;

	tu1.set_number(1);
	std::cout << tu1.number() << std::endl;
	tu1.set_text("Set text1");
	std::cout << tu1.text() << std::endl;

	tu2.set_number(2);
	std::cout << tu2.number() << std::endl;
	tu2.set_text("Set text2");
	std::cout << tu2.text() << std::endl;

	//copy constructor
	Tagged_union tu3 = tu1;

	try{
		std::cout << tu3.number() << std::endl;
	}catch(Tagged_union::Bad_entry& e ){
		e.what();
	}

	try{
		std::cout << tu3.text() << std::endl;
	}catch(Tagged_union::Bad_entry& e ){
		e.what();
	}

	//copy assignment
	tu2 = tu1;
	try{
		std::cout << tu2.number() << std::endl;
	}catch(Tagged_union::Bad_entry& e ){
		e.what();
	}

	try{
		std::cout << tu2.text() << std::endl;
	}catch(Tagged_union::Bad_entry& e ){
		e.what();
	}
}
