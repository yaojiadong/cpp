/*
 * ExtendableArray.hpp
 *
 *  Created on: Feb 23, 2021
 *      Author: jiado
 */

#ifndef TREE_EXTENDABLEARRAY_HPP_
#define TREE_EXTENDABLEARRAY_HPP_

#include <exception>
#include <algorithm>

template<class T>
class ExtendableArray{
public:
	ExtendableArray(){}
	virtual ~ExtendableArray(){if(arr != nullptr) delete [] arr;}

	virtual int size() const{return n;}

	virtual int getCapacity() const{return capacity;}

	virtual bool empty() const {return n==0;}

	virtual T& operator[](int i) const {return arr[i];}//*(arr+i);}

	virtual T& at(int i){if(i>=n || i<0) throw std::runtime_error("Index out of bound"); return arr[i];}

	virtual void erase(int i){for(int j = i+1; j<n; ++j){arr[j-1]=arr[j];} --n;}

	virtual void insert(int i, const T & elem){

		if(n >= capacity) reserve(std::max(1,2*capacity));
		if(i>=capacity || i<0) throw std::runtime_error("Index out of bound"); // Implement Iterator to encapsulate index

		for(int j=n-1; j>=i;--j){
			arr[j+1] = arr[j];
		}
		arr[i] = elem;
		++n;
	}

	virtual void reserve(int N){
		if(capacity>N) return;
		T* A = new T [N];
		for(int i=0; i<n; ++i){
			A[i] = arr[i];
		}
		if(arr != nullptr) delete[] arr;
		arr = A;
		capacity = N;
	}

protected:
	T* arr {nullptr};
	int capacity {0};
	int n{0};

};


#endif /* TREE_EXTENDABLEARRAY_HPP_ */
