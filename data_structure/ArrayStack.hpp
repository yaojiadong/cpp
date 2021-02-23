/*
 * ArrayStack.hpp
 *
 *  Created on: Feb 17, 2021
 *      Author: jiado
 */
#include "Exception.hpp"


/* Implement stack using array*/

template<class T>
class ArrayStack{
	constexpr static int DEFAULT_SIZE = 100; //has to be static member.constexpr needs to be checked at compile time
public:
	ArrayStack(int n=DEFAULT_SIZE):capacity{n},sz{0},arr{new T[n]}{}
	~ArrayStack(){delete[] arr;}

	void push(const T& elem){
		if(full()) throw StackFull("Push of full stack");
		arr[sz++] = elem;
	}

	void pop(){
		if(empty()) throw StackEmpty("Pop of empty stack");
		sz--;
	}

	const T& top() const{
		if(empty()) throw StackEmpty("Pop of empty stack");
		return arr[sz-1];
	}

	int size() const{
		return sz;
	}

	bool empty() const{
		return sz==0;
	}

	bool full() const{
		return sz==capacity;
	}

private:
	int capacity;
	int sz;
	T* arr;

};
