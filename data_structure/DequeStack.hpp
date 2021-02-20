/*
 * DequeStack.hpp
 *
 *  Created on: Feb 17, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_DEQUESTACK_HPP_
#define DATA_STRUCTURE_DEQUESTACK_HPP_

#include"Deque.hpp"

/* Implement a stack using deque, which uses doubly linked list.
 * This is called adapter design pattern
 * */

template<class T>
class DequeStack{
public:
	DequeStack():deque{}{}
	~DequeStack(){}

	void push_back(const T& elem){
		deque.push_back(elem);
	}

	void pop_front(){
		if(empty()) throw StackEmpty("Pop front of empty stack");
		deque.pop_front();
	}

	const T& back() const{
		if(empty()) throw StackEmpty("Empty stack");
		return deque.back();
	}

	const T& front() const{
		if(empty()) throw StackEmpty("Empty stack");
		return deque.front();
	}

	int size() const{
		return deque.size();
	}

	bool empty() const{
		return deque.empty();
	}

private :
	Deque<T> deque;
};

#endif /* DATA_STRUCTURE_DEQUESTACK_HPP_ */
