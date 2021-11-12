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

class Ctor {
public:
  Ctor(int a_value = 0) : size{a_value} { std::cout << "Constructor\n"; }

  Ctor(const Ctor &other) : size{other.size} {
    std::cout << "Copy constructor\n";
  }

  Ctor &operator=(const Ctor &other) {
    std::cout << "Copy assignment";
    if (this != &other) {
      this->size = other.size;
    }
    return *this;
  }

  Ctor(Ctor &&other) noexcept : size{std::move(other.size)} {
    std::cout << "Move constructor\n";
    other.size = 0;
  }

  Ctor &operator=(Ctor &&other) noexcept {
    std::cout << "Move assignment\n";
    if (this != &other) {
      this->size = std::move(other.size);
      other.size = 0;
    }
    return *this;
  }

  ~Ctor() { std::cout << "Destructor\n"; }

private:
  int size;
};

#endif /* DEFAULT_CTOR_HPP_ */
