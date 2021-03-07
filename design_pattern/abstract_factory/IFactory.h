/*
 * IFactory.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_IFACTORY_H_
#define DESIGN_PATTERN_ABSTRACT_FACTORY_IFACTORY_H_

#include "IProduct_a.h"
#include "IProduct_b.h"
#include <memory>

class IFactory{
public:
	virtual ~IFactory(){}
	virtual std::unique_ptr<IProduct_a> create_product_a() const = 0;
	virtual std::unique_ptr<IProduct_b>  create_product_b() const = 0;
};


#endif /* DESIGN_PATTERN_ABSTRACT_FACTORY_IFACTORY_H_ */
