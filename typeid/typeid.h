/*
 * typeid.hpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */

#ifndef TYPEID_HPP_
#define TYPEID_HPP_

#include<typeinfo>
#include<string>
#include<iostream>

using namespace std;

class Component{
public:

private:
	int a;

};

class Ran{
public:
private:

};

void test_typeid();
void test_typeid_poly();

void f(Component s);

void g(string s);

#endif /* TYPEID_HPP_ */
