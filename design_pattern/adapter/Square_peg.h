#ifndef SQUAREPEG_HPP_
#define SQUAREPEG_HPP_

class Square_peg{
public:
	Square_peg(int width=0):width_{width}{}

	int width() const {return width_;}

private:
	int width_;
};



#endif /* SQUAREPEG_HPP_ */
