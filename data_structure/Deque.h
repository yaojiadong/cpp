/*
 * Deque.hpp
 *
 *  Created on: Feb 17, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_DEQUE_H_
#define DATA_STRUCTURE_DEQUE_H_

#include "Doubly_linked_list.h"
#include "Exception.h"
#include "Iterator_doubly_linked_list.h"

/* Implement deque using Doubly linked list*/

template<class T>
class Deque{
	using iterator = typename Iterator_doubly_linked_list<T>::Iterator;
public:
	Deque(int n=0):sz{n},lst{}{}
	~Deque(){}

	void push_back(const T& elem){
		lst.push_back(elem);
		sz++;
	}

	void push_front(const T& elem){
		lst.push_front(elem);
		sz++;
	}

	void pop_back(){
		if(empty()) throw DequeEmpty("Pop back of empty deque");
		lst.pop_back();
		sz--;
	}

	void pop_front(){
		if(empty()) throw DequeEmpty("Pop front of empty deque");
		lst.pop_front();
		sz--;
	}

	const T& back() const{
		if(empty()) throw DequeEmpty("Empty deque");
		return lst.back();
	}

	const T& front() const{
		if(empty()) throw DequeEmpty("Empty deque");
		return lst.front();
	}

	bool empty() const{
		return sz==0;
	}

	int size() const{
		return sz;
	}

	iterator begin(){
		return lst.begin();
	}

	iterator end(){
		return lst.end();
	}


private:

	int sz;
//	DLinkedList<T> lst;
	Iterator_doubly_linked_list<T> lst;

};


#endif /* DATA_STRUCTURE_DEQUE_H_ */
