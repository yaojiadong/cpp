
/*
 * default_ctor.hpp
 *
 *  Created on: Nov 18, 2020
 *      Author: jiadong
 */

#ifndef DEFAULT_CTOR_HPP_
#define DEFAULT_CTOR_HPP_

#include <iostream>
#include <string>

class Ctor_v2 {
public:
  Ctor_v2(size_t length = 0) : _length{length}, _data{new int[length]} {
    for (size_t i = 0; i < _length; ++i) {
      _data[i] = 0;
    }
    std::cout << "Constructor\n";
  }

  Ctor_v2(const Ctor_v2 &ctor)
      : _length{ctor._length}, _data{new int[ctor._length]} {
    std::cout << "Copy constructor\n";
    std::copy(ctor._data, ctor._data + _length, _data);
  }

  Ctor_v2 &operator=(Ctor_v2 &ctor) {
    std::cout << "Copy assignment\n";
    if (this != &ctor) {
      delete[] _data;
      this->_length = ctor._length;
      _data = new int[_length];
      std::copy(ctor._data, ctor._data + _length, _data);
    }
    return *this;
  }

  Ctor_v2(Ctor_v2 &&ctor)
      : _length{std::move(ctor._length)}, _data{std::move(ctor._data)} {

    std::cout << "Move constructor\n";
    if (ctor._data == nullptr) {
      std::cout << "After Move constructor, data is nullptr\n";
    } else {
      std::cout << "After Move constructor, data is NOT nullptr\n";
      ctor._data = nullptr;
    }
  }

  Ctor_v2 &operator=(Ctor_v2 &&ctor) {
    std::cout << "Move assignment\n";
    this->_length = std::move(ctor._length);
    this->_data = std::move(ctor._data);
    ctor._data = nullptr;
    return *this;
  }

  ~Ctor_v2() {
    std::cout << "Destructor\n";
    if (_data != nullptr) {
      std::cout << "Deleting resouce\n";
      delete _data;
    }
  }

  void update_data(size_t pos, int a) {
    if (pos < this->_length) {
      this->_data[pos] = a;
    }
  }

  void print_data() {
    for (size_t i = 0; i < _length; ++i) {
      std::cout << _data[i] << std::endl;
    }
  }

private:
  size_t _length;
  int *_data;
};

#endif /* DEFAULT_CTOR_HPP_ */
