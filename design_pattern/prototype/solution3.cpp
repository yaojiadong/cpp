/*
 * solution3.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#define SOLUTION3

#include <memory>
using namespace std;

/*
 * The issue is that Base is not abstract and no override.
 *
 * https://stackoverflow.com/questions/6924754/return-type-covariance-with-smart-pointers
 *
 * */


/* Use covariance on raw pointers, and then wrap them */

#ifdef SOLUTION2

struct Base
{
private:
   virtual Base* doClone() const {return new Base(*this); }

public:
   shared_ptr<Base> Clone() const { return shared_ptr<Base>(doClone()); }

   virtual ~Base(){}
};

struct Derived : Base
{
private:
   virtual Derived* doClone() const { return new Derived(*this); }

public:
   shared_ptr<Derived> Clone() const { return shared_ptr<Derived>(doClone()); }
};


#elif defined SOLUTION3

/*Simulate covariance by casting*/
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
   virtual shared_ptr<Base> doClone() const { return make_shared<Derived>(*this);  }

public:
   shared_ptr<Derived> Clone() const { return static_pointer_cast<Derived>(doClone()); }
};

#endif
