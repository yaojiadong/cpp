#include "test_adapter.h"
#include "Round_hole.h"
#include "Square_peg.h"
#include "Square_peg_adapter.h"
#include <iostream>

void test_adapter() {

  Round_hole round_hole{3};
  Square_peg square_peg{5};
  Square_peg_adapter square_peg_adapter{square_peg};

  std::cout << round_hole.fit(square_peg_adapter) << std::endl;
  ;
}
