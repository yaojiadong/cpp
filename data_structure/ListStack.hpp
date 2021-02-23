/*
 * Stack.hpp
 *
 *  Created on: Feb 17, 2021
 *      Author: jiado
 */

//#include<exception>
#include"DLinkedList.hpp"
#include<string>
#include<stdexcept>
#include "Exception.hpp"

//using namespace std;

//class StackEmpty : public std::runtime_error{
//public:
//	//	const std::string what() const{ return "StackEmpty";}
//	StackEmpty(const std::string err): std::runtime_error(err){}
//};


/*
 * Implement a stack using linked list
 * */

template<class T>
class ListStack{

public:
//	Stack():sz{0},lst{}{}
	ListStack():sz{}{}
	~ListStack(){}


	void push(const T& elem){
		lst.push_back(elem);
		sz++;
	}

	void pop() {
		if(empty()) throw StackEmpty("Pop of empty stack");
		lst.pop_back();
		sz--;
	}

	const T& top() const{
		if(empty()) throw StackEmpty("Top of empty stack");
		return lst.back();
	}

	int size() const{
		return sz;
	}

	bool empty()const {
		return sz==0;
	}

private:
	DLinkedList<T> lst;
	int sz;

};


