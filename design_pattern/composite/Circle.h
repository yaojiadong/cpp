/*
 * Circle.h
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_COMPOSITE_CIRCLE_H_
#define DESIGN_PATTERN_COMPOSITE_CIRCLE_H_


#include "Dot.h"

class Circle : public Dot{
public:
	Circle(int x=0, int y=0, int r=0):Dot{x,y},radius{r}{}
//	virtual void move(int xx, int yy) override {}
	virtual void draw() const override {std::cout << "Draw circle\n";}
private:
	int radius;
};


#endif /* DESIGN_PATTERN_COMPOSITE_CIRCLE_H_ */
