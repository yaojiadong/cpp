/*
 * Director.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_BUILDER_DIRECTOR_H_
#define DESIGN_PATTERN_BUILDER_DIRECTOR_H_

#include "IBuilder.h"
#include <memory>

class Director {

public:
  Director(std::shared_ptr<IBuilder> b) : builder{b} {}
  void build_simple_product() { builder->product_part_a(); }
  void build_full_product() {
    builder->product_part_a();
    builder->product_part_b();
    builder->product_part_c();
  }

  void set_builder(std::shared_ptr<IBuilder> b) { builder = b; }

private:
  std::shared_ptr<IBuilder> builder;
};

#endif /* DESIGN_PATTERN_BUILDER_DIRECTOR_H_ */
