/*
 * solution3.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#define SOLUTION3_1

#include <memory>
using namespace std;

/*
 * https://stackoverflow.com/questions/6924754/return-type-covariance-with-smart-pointers
 *
 * */


/* Use covariance on raw pointers, and then wrap them
 * doClone() is overridden. Clone() is not.
 *  */

#ifdef SOLUTION3_1

struct Base{

private:
	virtual Base* doClone() const {return new Base(*this); }

public:
	shared_ptr<Base> Clone() const {
		Base* d = this->doClone();
		std::shared_ptr<Base> p = std::make_shared<Base>(*d);
		delete d;
		return p;
	}

	virtual ~Base(){}
};

struct Derived : Base{

private:
	virtual Derived* doClone() const override { return new Derived(*this); }

public:
	shared_ptr<Derived> Clone() const {
		Derived* d = this->doClone();
		std::shared_ptr<Derived> p = std::make_shared<Derived>(*d);
		delete d;
		return p;
	}
};


#elif defined SOLUTION3_2

/*
 * Simulate covariance by casting.
 * doClone() is overridden. Clone() is not.
 * */
struct Base
{
private:
	virtual shared_ptr<Base> doClone() const { return make_shared<Base>(*this); }

public:
	shared_ptr<Base> Clone() const { return doClone(); }

	virtual ~Base(){}
};

struct Derived : Base
{
private:
	virtual shared_ptr<Base> doClone() const override { return make_shared<Derived>(*this);  }

public:
	shared_ptr<Derived> Clone() const { return static_pointer_cast<Derived>(doClone()); }
};

#endif
