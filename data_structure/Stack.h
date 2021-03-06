/*
 * Stack.hpp
 *
 *  Created on: Feb 17, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_STACK_H_
#define DATA_STRUCTURE_STACK_H_

#include "Deque.h"

template<class T, class Container=Deque<T>>
class Stack{
public:
	Stack():container{}{}
	~Stack(){}

	void push_back(const T& elem){
		container.push_back(elem);
	}

	void pop_front(){
		if(empty()) throw StackEmpty("Pop front of empty stack");
		container.pop_front();
	}

	const T& back() const{
		if(empty()) throw StackEmpty("Empty stack");
		return container.back();
	}

	const T& front() const{
		if(empty()) throw StackEmpty("Empty stack");
		return container.front();
	}

	int size() const{
		return container.size();
	}

	bool empty() const{
		return container.empty();
	}

private :
	Container container;
};

#endif /* DATA_STRUCTURE_STACK_H_ */
