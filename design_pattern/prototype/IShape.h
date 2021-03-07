/*
 * Shape.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_PROTOTYPE_SHAPE_H_
#define DESIGN_PATTERN_PROTOTYPE_SHAPE_H_

#include <memory>

class IShape{
public:

	virtual ~IShape(){}
//	virtual std::shared_ptr<IShape> clone() = 0;
	virtual IShape* clone() = 0;

};


#endif /* DESIGN_PATTERN_PROTOTYPE_SHAPE_H_ */
