/*
 * problem.h
 *
 *  Created on: Mar 11, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_PROTOTYPE_PROBLEM_H_
#define DESIGN_PATTERN_PROTOTYPE_PROBLEM_H_

#include <iostream>
#include <memory>
#include <vector>
using namespace std;


/*
 * Show the difference in using row pointer and smart pointer.
 * Row pointer has covariance but smart pointer does not.
 * */
struct Base{

public:
	virtual shared_ptr<Base> clone() = 0;

	virtual ~Base(){}
};

struct Derived : Base{

public:
	Derived(int r = 0): radius{r}{}

	// problem: return type is shared_ptr<Base>. The object will be stored in a vector, but it cannot access other members in Derived.
	shared_ptr<Base> clone() override { return make_shared<Derived>(*this); }

	int get_radius() const {return radius;}

private:
	int radius;
};


struct Base2{

public:
	virtual Base2* clone() = 0;

	//	virtual int get_radius() const = 0;

	virtual ~Base2(){}
};

struct Derived2 : Base2{

public:
	Derived2(int r = 0): radius{r}{}

	// problem: return type is shared_ptr<Base>. The object will be stored in a vector, but it cannot access other members in Derived.
	Derived2(const Derived2& d){
		cout<<"copy ctor called\n";
		this->radius = d.radius;
	}

	Derived2*  clone()  { return new Derived2(*this); }

	int get_radius() const  {return radius;}

private:
	int radius;
};


void test_problem();




#endif /* DESIGN_PATTERN_PROTOTYPE_PROBLEM_H_ */
