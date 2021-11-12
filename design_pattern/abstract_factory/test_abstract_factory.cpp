/*
 * test_abstract_factory.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#include "Client.h"
#include "Factory1.h"
#include "Factory2.h"

void test_abstract_factory() {
  std::shared_ptr<Factory1> f1 = std::make_shared<Factory1>();
  std::shared_ptr<Factory2> f2 = std::make_shared<Factory2>();
  Client client1{f1};
  Client client2{f2};

  client1.use_product_a();
  client1.use_product_b();

  client2.use_product_a();
  client2.use_product_b();
}
