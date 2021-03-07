/*
 * Factory1.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY1_H_
#define DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY1_H_

#include "IFactory.h"
#include "Product_a1.h"
#include "Product_b1.h"

class Factory1 : public IFactory{
public:
	virtual std::unique_ptr<IProduct_a> create_product_a() const override{return std::make_unique<Product_a1>();}
	virtual std::unique_ptr<IProduct_b> create_product_b() const override{return std::make_unique<Product_b1>();}
};



#endif /* DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY1_H_ */
