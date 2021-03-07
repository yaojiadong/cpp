/*
 * Circle.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_PROTOTYPE_CIRCLE_H_
#define DESIGN_PATTERN_PROTOTYPE_CIRCLE_H_


#include "IShape.h"
#include <iostream>


class Circle : public IShape{
public:
	Circle(int r = 0):radius{r}{}

	Circle* clone() override {std::cout << "Clone a circle\n"; return new Circle(*this);}

	int get_radius() const {return radius;}

private:
	int radius;

};


#endif /* DESIGN_PATTERN_PROTOTYPE_CIRCLE_H_ */
