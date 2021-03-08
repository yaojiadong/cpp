/*
 * main.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

/*
 *
 * https://stackoverflow.com/questions/6924754/return-type-covariance-with-smart-pointers
 *
 *
 * Solution:
 * 2. Use row pointer in Base, and smart pointers elsewhere. Define an extra -impl member function to facilitate
 * the use of covariance on raw pointers, and then wrap them.
 *
 * Name hiding (i.e. when declaring a name in a derived class, this name hides all the symbols with the same name in the base class),
 * we hide (not override) the clone() member function to return a smart pointer of the exact type we wanted.
 */

#include <memory>
#include <iostream>

class Base{
public:
	virtual ~Base(){}
	std::unique_ptr<Base> clone() const{
		Base* d = this->clone_impl();
		std::unique_ptr<Base> p = std::make_unique<Base>(*d);
		delete d;
		return p;
	}

private:
	virtual Base* clone_impl() const {return new Base(*this); }
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
