/*
 * Product_a.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_PRODUCT_A_H_
#define DESIGN_PATTERN_ABSTRACT_FACTORY_PRODUCT_A_H_

#include "IProduct_a.h"


class Product_a1 : public IProduct_a{
public:
	std::string use_product_a() const override {return "I am using product a1.\n";}
};


#endif /* DESIGN_PATTERN_ABSTRACT_FACTORY_PRODUCT_A_H_ */
