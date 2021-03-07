/*
 * IProduct_b.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_IPRODUCT_B_H_
#define DESIGN_PATTERN_ABSTRACT_FACTORY_IPRODUCT_B_H_


#include <iostream>

class IProduct_b{
public:
	virtual ~IProduct_b(){}
	virtual std::string use_product_b() const = 0;
};



#endif /* DESIGN_PATTERN_ABSTRACT_FACTORY_IPRODUCT_B_H_ */
