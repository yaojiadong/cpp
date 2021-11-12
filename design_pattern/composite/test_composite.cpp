/*
 * test_composite.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#include "test_composite.h"
#include "Circle.h"
#include "Compound_graphic.h"
#include "Dot.h"

void test_composite() {
  std::shared_ptr<Compound_graphic> cg_large =
      std::make_shared<Compound_graphic>();
  std::shared_ptr<Compound_graphic> cg_small =
      std::make_shared<Compound_graphic>();
  std::shared_ptr<Dot> dot = std::make_shared<Dot>();
  std::shared_ptr<Circle> circle = std::make_shared<Circle>();

  cg_small->add(dot);
  cg_small->add(circle);
  cg_large->add(cg_small);
  cg_large->add(circle);

  cg_large->draw();

  cg_small->remove(circle);
  cg_large->draw();
}
