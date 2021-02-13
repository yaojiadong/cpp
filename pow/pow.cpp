/*
 * pow.cpp
 *
 *  Created on: 2021.2.7
 *      Author: jiado
 */


#include"pow.h"
#include<iostream>

int pow(int x, int y){
	if(y > 0)
		return x*pow(x,--y);
	else
		return 1;

}


void test_pow(){
	std::cout<< pow(3,3)<<std::endl;
}
