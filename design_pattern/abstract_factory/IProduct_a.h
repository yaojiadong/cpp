/*
 * IProduct_a.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_IPRODUCT_A_H_
#define DESIGN_PATTERN_ABSTRACT_FACTORY_IPRODUCT_A_H_

#include <iostream>

class IProduct_a {
public:
  virtual ~IProduct_a() {}
  virtual std::string use_product_a() const = 0;
};

#endif /* DESIGN_PATTERN_ABSTRACT_FACTORY_IPRODUCT_A_H_ */
