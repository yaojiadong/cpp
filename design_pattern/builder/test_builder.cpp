/*
 * test_builder.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#include "test_builder.h"
#include "Builder1.h"
#include "Builder2.h"
#include "Client.h"
#include "Director.h"
#include "Product1.h"
#include "Product2.h"

void test_builder() {
  // use builder1 to build product1
  std::shared_ptr<Builder1> builder1 = std::make_shared<Builder1>();
  Director director{builder1}; // tell director to use builder1
  Client client{director};     // the director is responsible for this client.

  client.ask_for_simple_product();
  std::shared_ptr<Product1> product1 =
      builder1->product1(); // get product from builder
  product1->ListParts();

  client.ask_for_full_product();
  product1 = builder1->product1();
  product1->ListParts();

  // use builder2 to build product2
  std::shared_ptr<Builder2> builder2 = std::make_shared<Builder2>();
  director.set_builder(builder2); // tell director to use builder2

  client.ask_for_simple_product();
  std::shared_ptr<Product2> product2 =
      builder2->product2(); // get product from builder
  product2->ListParts();

  client.ask_for_full_product();
  product2 = builder2->product2(); // get product from builder
  product2->ListParts();
}
