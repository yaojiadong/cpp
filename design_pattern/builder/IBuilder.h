/*
 * IBuilder.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_BUILDER_IBUILDER_H_
#define DESIGN_PATTERN_BUILDER_IBUILDER_H_


class IBuilder{
public:
	virtual ~IBuilder(){}

	virtual void product_part_a() const = 0;
	virtual void product_part_b() const = 0;
	virtual void product_part_c() const = 0;
};


#endif /* DESIGN_PATTERN_BUILDER_IBUILDER_H_ */
