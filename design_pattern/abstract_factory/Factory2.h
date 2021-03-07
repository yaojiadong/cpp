/*
 * Factory2.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY2_H_
#define DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY2_H_

#include "IFactory.h"
#include "Product_a2.h"
#include "Product_b2.h"

class Factory2 : public IFactory{
public:
	virtual std::unique_ptr<IProduct_a> create_product_a() const override{return std::make_unique<Product_a2>();}
	virtual std::unique_ptr<IProduct_b> create_product_b() const override{return std::make_unique<Product_b2>();}
};



#endif /* DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY2_H_ */
