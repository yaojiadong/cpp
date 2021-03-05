/*
 * variant.cpp
 *
 *  Created on: Mar 5, 2021
 *      Author: jiado
 */


#include <vector>
#include <memory>
#include <variant>
#include <cassert>
#include <iostream>
#include "variant.h"
using namespace std;

/*
 * https://stackoverflow.com/questions/10744787/operator-must-take-exactly-one-argument
 *
 * Define the operator<< in class, the second argument is implicit (this).
 * Operator overloading is necessary for the std::variant.
 * The variant checks if all the types support certain operators.
 * */
template<class T>
class MyVector:public std::vector<T>{
public:
	ostream& operator<<(ostream&os){
		os<< vector<T>::size();
		return os;
	}
};

/*
 * Define it outside the class, pass vector as a second argument.
 * */
ostream& operator<<(ostream&os, vector<int> a){
	os<< a.size();
	return os;
}

void test_variant()
{
	std::variant<char, int, double,std::string,vector<int>, MyVector<int>> s = 'a';
	std::visit([](auto x){  std::cout << x << '\n';}, s);

	s = "Hellow";
	std::visit([](auto x){  std::cout << x << '\n';}, s);

	vector<int> vec;
	vec.push_back(10);
	s= vec;
	std::visit([](auto x){ std::cout << x  << '\n';}, s);

	MyVector<int> my_vec;
	my_vec.push_back(10);
	my_vec.push_back(100);
	s= my_vec;
	std::visit([](auto x){ std::cout << x  << '\n';}, s);


	using namespace std::literals;
	std::variant<std::string, void const*> y("abc");
	//casts to void const * when passed a char const *
	assert(std::holds_alternative<void const*>(y)); // succeeds
	y = "xyz"s;
	assert(std::holds_alternative<std::string>(y)); // succeeds

}

