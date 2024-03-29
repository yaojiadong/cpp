/*
 * Vector.h
 *
 *  Created on: Feb 23, 2021
 *      Author: jiado
 */

#ifndef VECTOR_H_
#define VECTOR_H_

/*
 * The Vector class is used for Vector based binary tree.
 * */

#include "Extendable_array.h"

template <class T> class Vector : public Extendable_array<T> {
  using Extendable_array<T>::_capacity;
  using Extendable_array<T>::n;
  using Extendable_array<T>::arr;
  using Extendable_array<T>::reserve;

public:
  Vector() {}
  ~Vector() {}

  /*
   * The following three member functions are overridden.
   * The ExtendableArray and the Vector for binary tree have
   * different implementation in memory reservation, element insertion and
   * access. Note the usage of capacity and the size n.
   * */

  T &at(int i) const override {
    if (i >= _capacity || i < 0)
      throw std::runtime_error("Index out of bound");
    return arr[i];
  }

  void insert(int i, const T &elem) override {
    if (i >= _capacity)
      reserve(2 * _capacity + 1);
    arr[i] = elem;
    ++n;
  }

  void reserve(int N) override {
    if (_capacity > N)
      return;
    T *A = new T[N];
    for (int i = 0; i < _capacity; ++i) {
      A[i] = arr[i];
    }
    for (int i = _capacity; i < N; ++i) {
      A[i] = nullptr;
    }
    if (arr != nullptr)
      delete[] arr;
    arr = A;
    _capacity = N;
  }
};

#endif /* TREE_VECTOR_HPP_ */
