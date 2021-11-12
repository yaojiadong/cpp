#pragma once

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
#include <vector>

class Ctor_v3 {
public:
  Ctor_v3() { std::cout << "Constructor\n"; }

  Ctor_v3(const Ctor_v3 &ctor) : _data{ctor._data} {
    std::cout << "Copy constructor\n";
  }

  Ctor_v3 &operator=(const Ctor_v3 &ctor) {
    std::cout << "Copy assignment\n";
    if (this != &ctor) {
      _data.clear();
      _data = ctor._data;
    }
    return *this;
  }

  Ctor_v3(Ctor_v3 &&ctor) noexcept : _data{std::move(ctor._data)} {
    std::cout << "Move constructor\n";
    if (ctor._data.empty() == true) {
      std::cout << "After Move constructor, data is empty\n";
    } else {
      std::cout << "After Move constructor, data is NOT empty\n";
    }
  }

  Ctor_v3 &operator=(Ctor_v3 &&ctor) noexcept {
    std::cout << "Move assignment\n";
    this->_data.clear();
    this->_data = std::move(ctor._data);
    return *this;
  }

  ~Ctor_v3() { std::cout << "Destructor\n"; }

  void update_data(int a) { _data.push_back(a); }

  void print_data() {
    if (_data.empty()) {
      std::cout << "Empty data\n";
    }
    for (const auto &i : _data) {
      std::cout << i << std::endl;
    }
  }

private:
  std::vector<int> _data;
};

#endif /* DEFAULT_CTOR_HPP_ */