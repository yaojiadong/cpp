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

class Base {
public:
  Base(int a_value = 0) : a{a_value} { std::cout << "Constructor\n"; }

  Base(const Base &base) : a{base.a} { std::cout << "Copy constructor\n"; }

  Base &operator=(Base &base) {
    std::cout << "Copy assignment";
    this->a = base.a;
    return *this;
  }

  Base(Base &&base) : a{std::move(base.a)} {
    std::cout << "Move constructor\n";
  }

  Base &operator=(Base &&base) {
    std::cout << "Move assignment\n";
    this->a = std::move(base.a);
  }

  ~Base() { std::cout << "Destructor\n"; }

private:
  int a;
};

#endif /* DEFAULT_CTOR_HPP_ */
