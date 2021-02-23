/*
 * Vector.hpp
 *
 *  Created on: Feb 23, 2021
 *      Author: jiado
 */

#ifndef TREE_VECTOR_HPP_
#define TREE_VECTOR_HPP_


#include "ExtendableArray.hpp"

template<class T>
class Vector:public ExtendableArray<T>{
	using ExtendableArray<T>::capacity;
	using ExtendableArray<T>::n;
	using ExtendableArray<T>::arr;
	using ExtendableArray<T>::reserve;

public:

	Vector(){}
	~Vector(){}

	void insert(int i, const T & elem) override{
		if(i >= capacity) reserve(2*capacity+1);
		arr[i] = elem;
		++n;
	}

//	void reserve(int N) override{
//		if(capacity>N) return;
//		T* A = new T[N];
//		for(int i=0; i<n; ++i){
//			A[i] = arr[i];
//		}
//		if(arr != nullptr) delete[] arr;
//		arr = A;
//		capacity = N;
//	}

};


#endif /* TREE_VECTOR_HPP_ */
