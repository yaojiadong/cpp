/*
 * rvalue.cpp
 *
 *  Created on: Jan 17, 2021
 *      Author: jiado
 */

/*
 * Please be aware of the difference between is_lvalue_reference<T> and is_lvalue_reference<decltype<t>>.
 * In the template, T is deduced based on the function argument, whereas the value category of t is always lvalue in f2 and
 * forward<int>(t) and move(t) are always rvalue.
 *
 * */



#include <iostream>
#include <type_traits>

class A {};


template <typename T>
T f0(T& t) {  //<-----this is a universal reference
	std::cout<< "f0 lvalue"<<'\n';

	// take T as template argument, it is type int, so not rvalue, not lvalue.
//	std::cout << "is_lvalue reference:" << std::is_lvalue_reference<T>::value << std::endl;
	std::cout << "is_lvalue reference:" << std::is_lvalue_reference<T>::value << std::endl;
	std::cout << "is_rvalue reference:" << std::is_rvalue_reference<T>::value << std::endl;
	std::cout << "is_reference:"        << std::is_reference<T>::value        << std::endl;
	return t;
}

template <typename T>
T f0(T&&t) {  //<-----this is a universal reference
	std::cout<< "f0 rvalue"<<'\n';
	std::cout << "is_lvalue reference:" << std::is_lvalue_reference<T>::value << std::endl;
	std::cout << "is_rvalue reference:" << std::is_rvalue_reference<T>::value << std::endl;
	std::cout << "is_reference:"        << std::is_reference<T>::value        << std::endl;
	return t;
}

template <typename T>
T f1(T& t) {  //<-----this is a universal reference
	std::cout<< "f1 lvalue"<<'\n';

	// take T as template argument, it is type int, so not rvalue, not lvalue.
//	std::cout << "is_lvalue reference:" << std::is_lvalue_reference<T>::value << std::endl;
	std::cout << "is_lvalue reference:" << std::is_lvalue_reference<decltype(t)>::value << std::endl;
	std::cout << "is_rvalue reference:" << std::is_rvalue_reference<decltype(t)>::value << std::endl;
	std::cout << "is_reference:"        << std::is_reference<decltype(t)>::value        << std::endl;
	return t;
}

template <typename T>
T f1(T&&t) {  //<-----this is a universal reference
	std::cout<< "f1 rvalue"<<'\n';
	std::cout << "is_lvalue reference:" << std::is_lvalue_reference<decltype(t)>::value << std::endl;
	std::cout << "is_rvalue reference:" << std::is_rvalue_reference<decltype(t)>::value << std::endl;
	std::cout << "is_reference:"        << std::is_reference<decltype(t)>::value        << std::endl;
	return t;
}

void f2(int&&t) {  //<-----this is a universal reference
	std::cout<< "f2 rvalue"<<'\n';
	std::cout << "is_lvalue reference:" << std::is_lvalue_reference<decltype(t)>::value << std::endl;
	std::cout << "is_rvalue reference:" << std::is_rvalue_reference<decltype(t)>::value << std::endl;
	std::cout << "is_reference:"        << std::is_reference<decltype(t)>::value        << std::endl;


	f1(std::forward<int>(t));  	// T is deduced as int for f(T&&), type int is not rvalue, nor lvalue, t is rvalue
	f1(std::move(t));			// T is deduced as int for f(T&&), type int is not rvalue, nor lvalue, t is rvalue
	f1(t);						// T is deduced as int for f(T&),  type int is not rvalue, nor lvalue, t is lvalue
								//if f1(T&) not exist, then f1(t) will call f1(T&&), T is deduced as int&, type int& is lvalue, t is lvalue


	f0(std::forward<int>(t));  	// T is deduced as int for f(T&&), type int is not rvalue, nor lvalue, t is rvalue
	f0(std::move(t));			// T is deduced as int for f(T&&), type int is not rvalue, nor lvalue, t is rvalue
	f0(t);						// T is deduced as int for f(T&),  type int is not rvalue, nor lvalue, t is lvalue
								//if f0(T&) not exist, then f0(t) will call f0(T&&), T is deduced as int&, type int& is lvalue, t is lvalue
}




void test_rvalue()
{

	f2(5);
	std::cout << std::boolalpha;
	std::cout << std::is_lvalue_reference<A>::value << '\n';		// A is not lvalue
	std::cout << std::is_rvalue_reference<A>::value << '\n';		// A is not rvalue
	std::cout << std::is_lvalue_reference<A&>::value << '\n';		// A& is lvalue
	std::cout << std::is_rvalue_reference<A&&>::value << '\n';		// A&& is rvalue
	std::cout << std::is_lvalue_reference<int>::value << '\n';    	// int is not lvalue
	std::cout << std::is_rvalue_reference<int>::value << '\n';		// int is not rvalue
	std::cout << std::is_lvalue_reference<int&>::value << '\n';		// int& is lvalue
	std::cout << std::is_rvalue_reference<int&&>::value << '\n'; 	// int&& is rvalue

}


