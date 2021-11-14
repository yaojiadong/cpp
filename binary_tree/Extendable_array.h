/*
 * Extendable_array.h
 *
 *  Created on: Feb 23, 2021
 *      Author: jiado
 */

#ifndef EXTENDABLE_ARRAY_H_
#define EXTENDABLE_ARRAY_H_

#include <algorithm>
#include <exception>

template <class T> class Extendable_array {
public:
  Extendable_array() {}
  virtual ~Extendable_array() {
    if (arr != nullptr)
      delete[] arr;
  }

  virtual int size() const { return n; }

  virtual int capacity() const { return this->_capacity; }

  virtual bool empty() const { return n == 0; }

  virtual T &operator[](int i) const { return arr[i]; } //*(arr+i);}

  virtual T &at(int i) const {
    if (i >= n || i < 0)
      throw std::runtime_error("Index out of bound");
    return arr[i];
  }

  virtual void erase(int i) {
    for (int j = i + 1; j < n; ++j) {
      arr[j - 1] = arr[j];
    }
    --n;
  }

  virtual void insert(int i, const T &elem) {

    if (n >= _capacity)
      reserve(std::max(1, 2 * _capacity));
    if (i >= _capacity || i < 0)
      throw std::runtime_error(
          "Index out of bound"); // Implement Iterator to encapsulate index

    for (int j = n - 1; j >= i; --j) {
      arr[j + 1] = arr[j];
    }
    arr[i] = elem;
    ++n;
  }

  virtual void reserve(int N) {
    if (_capacity > N)
      return;
    T *A = new T[N];
    for (int i = 0; i < n; ++i) {
      A[i] = arr[i];
    }
    if (arr != nullptr)
      delete[] arr;
    arr = A;
    _capacity = N;
  }

protected:
  T *arr{nullptr};
  int _capacity{0};
  int n{0};
};

#endif /* EXTENDABLE_ARRAY_H_ */
