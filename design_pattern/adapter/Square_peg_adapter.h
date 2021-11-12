#ifndef SQUAREPEGADAPTER_HPP_
#define SQUAREPEGADAPTER_HPP_

/*
 * Is the square peg fit to the round hole?
 * Since the round hole only accepts round peg,
 * the square peg adapter facilitates the check if a square peg fits the round
 * hole.
 * */

#include <cmath>

#include "Round_peg.h"
#include "Square_peg.h"

class Square_peg_adapter : public Round_peg {

public:
  Square_peg_adapter(Square_peg sp) : square_peg_{sp} {}

  int radius() const override {
    return static_cast<int>(square_peg_.width() * std::sqrt(2) * 2);
  }

private:
  Square_peg square_peg_;
};

#endif /* SQUAREPEGADAPTER_HPP_ */
