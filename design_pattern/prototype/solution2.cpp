/*
 * main.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

/*
 * Solution:
 * 2. Use row pointer in Base, and smart pointers elsewhere. Define an extra -impl member function to facilitate the return type as smart pointer
 */

#include <memory>
#include <iostream>

class Base{
public:
	virtual ~Base(){}
	virtual Base* clone_impl() const = 0;
};

class Derived : public Base
{
private:
	int n;
public:
	Derived(int num = 0):n{num}{}
	std::unique_ptr<Derived> clone() const {
		Derived* d = this->clone_impl();
		std::unique_ptr<Derived> p = std::make_unique<Derived>(*d);
		delete d;
		return p;
	}

	int get_value() const {return n;}

private:
	Derived* clone_impl() const override {return new Derived(*this);}
};


void test_prototype_2()
{
	std::unique_ptr<Derived> c = std::make_unique<Derived>(10);
	std::unique_ptr<Derived> cc = c->clone();
	std::cout << cc->get_value() << std::endl;

	Derived * p = c.get();
	std::unique_ptr<Derived> pp = p->clone();
	std::cout << pp->get_value() << std::endl;
}
