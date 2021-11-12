#include "test_ctor_copy_swap.h"

void test_ctor_copy_swap() {
  Ctor_copy_swap a, b; // constructor
  a.print_data();

  Ctor_copy_swap c = a; // copy constructor
  c.print_data();

  b.print_data();
  b = c; // copy assignment -> copy and swap, also calls copy constructor for
         // arg passing
  b.print_data();

  Ctor_copy_swap d = std::move(a); // move constructor
  // a.print_data();                  // a is undefined after move

  Ctor_copy_swap e; // Constructor
  e.print_data();
  e = std::move(d); // move assignment -> copy and swap, also calls copy
                    // constructor for arg passing
  e.print_data();
}