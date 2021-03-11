/*
 * test_problem.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: jiado
 */


#include "test_problem.h"

void test_problem(){
	vector<shared_ptr<Base>> vec;
	shared_ptr<Base> p = make_shared<Derived>();
	// not possible to get the radius in Derived, because get_radius() is not in Base. No inheritance.
	//	cout << p->get_radius() << endl;
	//	vec.push_back(p);
	//	cout << vec[0]->get_radius()<< endl;

	vector<Base2*> vec2;
	Base2* b = new Derived2;
	vec2.push_back(b);
	Base2* bb = vec2.back();
	Derived2* dd = (Derived2*)bb->clone();
	cout << dd->get_radius();
	delete b;
	delete dd;
}
