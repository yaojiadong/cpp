/*
 * lambda.cpp
 *
 *  Created on: Jan 17, 2021
 *      Author: jiado
 */

#include<iostream>
#include<memory>
#include"lambda.h"

using namespace std;

void test_lambda(){
	int x = 4;
	auto y = [&r = x, x = x + 1]() mutable -> int  //r by reference and x by value(copy)
	    {
	        r += 2;
	        x = x +1;
	        return x * x;
	    }(); // updates ::x to 6 and initializes y to 25.

	cout << x  <<'\n' << y << endl;


	auto p = std::make_unique<int>(1);
//	auto pp = std::make_shared<int>(6);


//	auto task1 = [=] { *p = 5; }; // ERROR: std::unique_ptr cannot be copied
	// vs.
	auto task2 = [p = std::move(p)] { return *p = 5;}; // OK: p is move-constructed into the closure object
	// the original p is empty after task2 is created

//	auto task3 = [pp = std::move(p)] { cout<< *pp << endl; return pp;}; // ERROR


	auto a = task2();
    auto newP = std::make_unique<int>(a);

	task2();

	cout << *newP << endl;
	cout << "the value of p is "<<*p << endl; // empty, deferencing?, not printing, and the following not be executed.
	cout << "Print p is done "<< endl;
}
