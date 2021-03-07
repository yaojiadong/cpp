/*
 * Rectangle.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_PROTOTYPE_RECTANGLE_H_
#define DESIGN_PATTERN_PROTOTYPE_RECTANGLE_H_


#include "IShape.h"
#include <iostream>


class Rectangle : public IShape{
public:
	Rectangle(int l = 0, int w = 0)
	:length{l}, width{w}
	{}

	Rectangle* clone() override {std::cout << "Clone a rectangle\n"; return new Rectangle(*this);}

	int get_length() const {return length;}
	int get_width() const {return width;}

private:
	int length, width;

};


#endif /* DESIGN_PATTERN_PROTOTYPE_RECTANGLE_H_ */
