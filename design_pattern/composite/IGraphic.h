/*
 * IGraphic.h
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_COMPOSITE_IGRAPHIC_H_
#define DESIGN_PATTERN_COMPOSITE_IGRAPHIC_H_


class IGraphic{
public:
	virtual ~IGraphic(){}
	virtual void move(int x, int y) = 0;
	virtual void draw() const = 0;
	virtual bool is_compound() const = 0;
};


#endif /* DESIGN_PATTERN_COMPOSITE_IGRAPHIC_H_ */
