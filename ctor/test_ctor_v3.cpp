#include "test_ctor_v3.h"
#include "Ctor_v3.h"

void test_ctor_v3() {
  Ctor_v3 a, b; // constructor
  a.update_data(10);
  a.update_data(20);
  a.print_data();

  Ctor_v3 c = a; // copy constructor
  c.print_data();

  b.print_data();
  b = c; // copy assignment
  b.print_data();

  Ctor_v3 d = std::move(a); // move constructor
  // a.print_data();     // a is undefined after move

  Ctor_v3 e; // Constructor
  e.print_data();
  e = std::move(d); // move assignment
  e.print_data();
}