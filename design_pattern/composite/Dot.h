/*
 * Dot.h
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_COMPOSITE_DOT_H_
#define DESIGN_PATTERN_COMPOSITE_DOT_H_

#include "IGraphic.h"
#include <iostream>

class Dot : public IGraphic{
public:
	Dot(int xx=0, int yy=0):x{xx},y{yy}{}
	virtual void move(int xx, int yy) override {x += xx; y += yy;}
	virtual void draw() const override {std::cout << "Draw dot\n";}

private:
	int x, y;
};


#endif /* DESIGN_PATTERN_COMPOSITE_DOT_H_ */
