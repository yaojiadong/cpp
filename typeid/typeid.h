/*
 * typeid.hpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */

#ifndef TYPEID_HPP_
#define TYPEID_HPP_

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Component {
public:
  Component(int aa = 0) : a{aa} {}

private:
  int a = 0;
};

class Ran {
public:
private:
};

void test_typeid();
void test_typeid_poly();

void f(Component s);

void g(string s);

#endif /* TYPEID_HPP_ */
