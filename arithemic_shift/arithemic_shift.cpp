// Example program
#include <iostream>

/*
 * In practice, however, almost all compiler/machine combinations use arithmetic
 * right shifts for signed data, and many programmers assume this to be the
 * case. For unsigned data, on the other hand, right shifts must be logical.
 *
 * Java has a precise definition of how right shifts should be
 * performed. The expression x >> k shifts x arithmetically by k positions,
 * while x >>> k shifts it logically.
 *
 */

int arithemic_shift() {
  {
    signed int a = -107;
    signed int b = a / 16;
    signed int c = a >> 4;
    std::cout << b << ", " << c << std::endl;
  }
  {
    unsigned int a = 107;
    unsigned int b = a / 16;
    unsigned int c = a >> 4;
    std::cout << b << ", " << c;
  }
}
