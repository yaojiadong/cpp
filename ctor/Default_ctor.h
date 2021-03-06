/*
 * default_ctor.hpp
 *
 *  Created on: Nov 18, 2020
 *      Author: jiadong
 */

#ifndef DEFAULT_CTOR_HPP_
#define DEFAULT_CTOR_HPP_

class X{
public:

//	X(){}

//	X():a{},b{}{}
	X(int a_value = 0, int b_value=2):a{a_value},b{b_value}{}

	X(const X&);


private:
	 int a ;
	 int b;
};



#endif /* DEFAULT_CTOR_HPP_ */
