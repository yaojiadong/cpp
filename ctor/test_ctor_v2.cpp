#include "test_ctor_v2.h"
#include "Ctor_v2.h"

void test_ctor_v2() {
  Ctor_v2 a, b; // constructor
  a.update_data(0, 10);
  a.update_data(1, 20);
  a.print_data();

  Ctor_v2 c = a; // copy constructor
  c.print_data();

  b.print_data();
  b = c; // copy assignment
  b.print_data();

  Ctor_v2 d = std::move(a); // move constructor
  // a.print_data();     // a is undefined after move

  Ctor_v2 e; // Constructor
  e.print_data();
  e = std::move(d); // move assignment
  e.print_data();
}