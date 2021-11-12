#ifndef ROUNDPEG_HPP_
#define ROUNDPEG_HPP_

class Round_peg {
public:
  Round_peg(int radius = 0) : radius_{radius} {}

  virtual int radius() const { return radius_; }

  virtual ~Round_peg() {}

private:
  int radius_;
};

#endif /* ROUNDPEG_HPP_ */
