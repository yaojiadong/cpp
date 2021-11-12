/*
 * template_alias.hpp
 *
 *  Created on: Nov 20, 2020
 *      Author: jiadong
 */

#ifndef TEMPLATE_ALIAS_HPP_
#define TEMPLATE_ALIAS_HPP_

#include<iostream>

template<int>
struct int_exact_traits{
	using type = int;
};

template<>
struct int_exact_traits<8>{
	using type = char;
//	using type = double;
};

template<int N>
using int_exact = typename int_exact_traits<N>::type;


void test_template_alias();


#endif /* TEMPLATE_ALIAS_HPP_ */
