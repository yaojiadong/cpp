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

/*Lambda capture this by value*/
/*
 * An example of where this is problematic is asynchronous code
 * using callbacks that require an object to be available, potentially
 * past its lifetime. *this (C++17) will now make a copy of the
 * current object, while this (C++11) continues to capture by reference.*/
void lambda_copy_ref(){
	struct MyObj {
	  int value {123};
	  auto getValueCopy() {
	    return [*this] { return value; }; //returns a lambda
	  }
	  auto getValueRef() {
	    return [this] { return value; }; //returns a lambda
	  }
	};
	MyObj mo;
	auto valueCopy = mo.getValueCopy();
	auto valueRef = mo.getValueRef();
	mo.value = 321;
	cout<< "the copy of object "<<valueCopy()<<endl; // 123
	cout<< "the ref of object "<<valueRef() <<endl; // 321
}

void test_lambda(){
	int x = 4;

	//r by reference and x by value(copy). LHS x is local, private and immutable
	auto y = [&r = x, x = x + 1]() mutable -> int{
		r += 3;
		x = x +1; // LHS x is read-only, change is only possible when mutable
		return x*x ;
	}(); // updates ::x to 7 and initializes y to 36.

	cout << x  <<'\n' << y << endl;


	auto p = std::make_unique<int>(1);
	auto pp = std::make_shared<int>(6);


	//	auto task1 = [=] { *p = 5; }; // ERROR: std::unique_ptr cannot be copied
	// vs.
	auto task2 = [q = std::move(p)] { return *q = 5;};
	// OK: p is move-constructed into the closure object
	// the original p is empty after task2 is created

	//p points to empty, deferencing?, not printing
	//the following statements not be executed if the next statement exists.
//	cout << "the value of p is "<<*p << endl;


	auto a = task2(); // a is 5 of type int
	auto newP = std::make_unique<int>(a);
	cout <<"the p value is "<< *newP << endl;


	// p is already empty after task2();
	auto task3 = [pp] { cout<< "the value before task3 is " <<*pp << endl; return *pp = (*pp+1);};
	auto b = task3();
	cout << "the value after task3 is "<< b << endl;


	auto p3=std::make_unique<int>(10);
	// ERROR if return p.
//	auto task4 = [p = std::move(p3)] (){
//		cout<< "the value before task4 is " <<*p << endl; *p = *p+1; return p;
//	};
	auto task4 = [p = std::move(p3)] (){
		cout<< "the value before task4 is " <<*p << endl; return *p+1;
	};
	auto c = task4();
	cout << "the value after task4 is "<< c << endl;



	auto task5 = [] (auto p){
		cout<< "the value before task5 is " <<*p << endl; *p +=1; return p;
	};
	auto d = task5(pp);
	cout << "the value after task5 is "<< *d << endl;

	//return a sum
	constexpr auto add = [](int x, int y) {
	  return  x+y ;
	};

	static_assert(add(1, 2) == 3);

	//return a lambda of the sum
	constexpr auto add_more = [](int x, int y) {
	  auto L = [=] { return x; };
	  auto R = [=] { return y; };
	  return [=] { return L() + R(); };
	};
	//add_more returns a lambda, so add_more(1,2) is a lambda.
	//execution of lambda is add_more(1,2)();
	//if above function return [=]{...}(); then the function is called and return a value.
	static_assert(add_more(1, 2)() == 3);


	lambda_copy_ref();
}
