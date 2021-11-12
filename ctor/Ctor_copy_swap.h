#pragma once
#include <iostream>
#include <memory>

class Ctor_copy_swap {
public:
  Ctor_copy_swap(unsigned int sz = 0) : size{sz} {
    std::cout << "Constructor\n";
  }

  Ctor_copy_swap(const Ctor_copy_swap &other) : size{other.size} {
    std::cout << "Copy constructor\n";
  }

  // Ctor_copy_swap &operator=(const Ctor_copy_swap &other) {
  //  if (this != &other) {
  //    size = other.size;
  //  }
  //  return *this;
  //}

  Ctor_copy_swap(Ctor_copy_swap &&other) noexcept
      : size{std::move(other.size)} {
    std::cout << "Move constructor\n";
    other.size = 0;
  }

  // Ctor_copy_swap &operator=(Ctor_copy_swap &&other) noexcept {
  //  if (this != &other) {
  //    size = std::move(other.size);
  //    other.size = 0;
  //  }
  //  return *this;
  //}

  ~Ctor_copy_swap() {}

  /* Copy and swap idom
   * destructor of other is called to release the resources formerly managed by
   * *this. This form automatically provides strong exception guarantee, but
   * prohibits resource reuse.
   */
  Ctor_copy_swap &operator=(Ctor_copy_swap other) { // pass a copy!!!
    std::cout << "Copy and swap\n";
    std::swap(size, other.size);
    // std::swap(data, other.data); // if data is heap-allocated array
    return *this;
  }

  void print_data() { std::cout << size << std::endl; }

private:
  unsigned int size;
};