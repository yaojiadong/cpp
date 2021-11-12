/*
 * Product_b2.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_PRODUCT_B2_H_
#define DESIGN_PATTERN_ABSTRACT_FACTORY_PRODUCT_B2_H_

#include "IProduct_b.h"

class Product_b2 : public IProduct_b {
public:
  std::string use_product_b() const override {
    return "I am using product b2.\n";
  }
};

#endif /* DESIGN_PATTERN_ABSTRACT_FACTORY_PRODUCT_B2_H_ */
