/*
 * lambda.cpp
 *
 *  Created on: Jan 17, 2021
 *      Author: jiado
 */

#include<iostream>
#include"lambda.h"

using namespace std;

void test_lambda(){
	int x = 4;
	auto y = [&r = x, x = x + 1]() -> int  //r by reference and x by value(copy)
	    {
	        r += 2;
	        return x * x;
	    }(); // updates ::x to 6 and initializes y to 25.

	cout << x  <<'\n' << y << endl;
}
