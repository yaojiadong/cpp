#ifndef ROUNDHOLE_HPP_
#define ROUNDHOLE_HPP_

#include "Round_peg.h"

class Round_hole {
public:
  Round_hole(int radius = 0) : radius_{radius} {}

  int radius() const { return radius_; }

  bool fit(const Round_peg &rp) { return rp.radius() == this->radius_; }

private:
  int radius_;
};

#endif /* ROUNDHOLE_HPP_ */
