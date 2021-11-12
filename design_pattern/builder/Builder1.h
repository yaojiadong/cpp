/*
 * Builder1.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_BUILDER_BUILDER1_H_
#define DESIGN_PATTERN_BUILDER_BUILDER1_H_

#include "IBuilder.h"
#include "Product1.h"
#include <memory>

class Builder1 : public IBuilder {
public:
  Builder1() { this->reset(); }

  void product_part_a() const override { p->parts.push_back("part a"); }
  void product_part_b() const override { p->parts.push_back("part b"); }
  void product_part_c() const override { p->parts.push_back("part c"); }

  void reset() { p = std::make_shared<Product1>(); }
  std::shared_ptr<Product1> product1() const { return p; }

private:
  std::shared_ptr<Product1> p;
};

#endif /* DESIGN_PATTERN_BUILDER_BUILDER1_H_ */
