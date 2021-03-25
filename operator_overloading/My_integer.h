/*
 * my_integer.h
 *
 *  Created on: Mar 19, 2021
 *      Author: jiado
 */

#ifndef OPERATOR_OVERLOADING_MY_INTEGER_H_
#define OPERATOR_OVERLOADING_MY_INTEGER_H_

#include <iostream>
using namespace std;

class My_integer{
	friend ostream& operator<<(ostream& os,  const My_integer &myinte);
public:
	My_integer(int m = 0):m_Num{m}{}

	My_integer& operator++(){
		++m_Num;
		return *this;
	}

	My_integer operator++(int){
		My_integer temp = *this;
		++m_Num;
		return temp;
	}

	My_integer& operator+=(const My_integer& aint){
		this->m_Num += aint.m_Num;
		cout<<"operator+= single argument called\n";
		return *this;
	}

	 /*
	  * In class operator only has one argument.
	  * The left operand is the object of this class, the right operand is the argument.
	  * This operator might conflict with the friend operator if the second argument is the same.
	  * Error would be: ambiguous overload for 'operator+' (operand types are 'My_integer' and 'My_integer')
	  * */
	My_integer& operator+(const My_integer& aint){
		cout<<"operator+ single argument called\n";
		return (*this) += aint;
	}

	/*
	 * Define as a friend member function inside class. It can also be defined outside of the class without friend.
	 * Friend member function has two arguments. The first argument is the left operand, and second is the right operand.
	 * The second argument is of type const My_integer&, which is the same as operator defined above. Error: ambiguous overload for 'operator+'
	 * It could be solved by declaring the second argument : My_integer&.
	 * */
//	friend My_integer& operator+(My_integer& aint, const My_integer& bint){
//		aint.m_Num += bint.m_Num;
//		cout<<"operator+ double argument called\n";
//		return aint;
//	}

private:
	int m_Num;
};

/*
 * Definition outside of class, two arguments
 * */
ostream& operator<<(ostream& os,  const My_integer &myinte);


void test_operator_overloading();


#endif /* OPERATOR_OVERLOADING_MY_INTEGER_H_ */
