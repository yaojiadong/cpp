/*
 * template.hpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */

#ifndef TEMPLATES_HPP_
#define TEMPLATES_HPP_

#include <iostream>

void test_templates();

enum Variant{
	DDM,
	PDM
};

template<Variant T>
struct Data{
	void start();
	int a;
};



template<> struct Data<DDM>{
	void start(){ std::cout<<"start"<<"\n";}
	int a;
};




#endif /* TEMPLATES_HPP_ */
