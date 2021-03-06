/*
 * DequeQueue.hpp
 *
 *  Created on: Feb 17, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_DEQUE_QUEUE_H_
#define DATA_STRUCTURE_DEQUE_QUEUE_H_

#include "Deque.h"

/* Implement a queue using deque, which uses doubly linked list.
 * This is called adapter design pattern
 * */

template<class T>
class Deque_queue{
public:
	Deque_queue():deque{}{}
	~Deque_queue(){}

	void push_back(const T& elem){
		deque.push_back(elem);
	}

	void pop_front(){
		if(empty()) throw QueueEmpty("Pop front of empty queue");
		deque.pop_front();
	}

	const T& back() const{
		if(empty()) throw QueueEmpty("Empty queue");
		return deque.back();
	}

	const T& front() const{
		if(empty()) throw QueueEmpty("Empty queue");
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

#endif /* DATA_STRUCTURE_DEQUE_QUEUE_H_ */
