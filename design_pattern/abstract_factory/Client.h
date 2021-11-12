/*
 * Client.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_ABSTRACT_FACTORY_CLIENT_H_
#define DESIGN_PATTERN_ABSTRACT_FACTORY_CLIENT_H_

//#include "Factory1.h"
//#include "Factory2.h"
#include "IFactory.h"
#include "IProduct_a.h"
#include "IProduct_b.h"
#include <iostream>

/*
 * Which product_a is created depends on which factory is used.
 * If factory1 is used, product a1 and b1 are created.
 * If factory2 is used, product a2 and b2 are created.
 * */
class Client {
public:
  Client(std::shared_ptr<IFactory> f) : factory{f} {}

  std::unique_ptr<IProduct_a> create_product_a() {
    return factory->create_product_a();
  }
  std::unique_ptr<IProduct_b> create_product_b() {
    return factory->create_product_b();
  }

  void use_product_a() {
    std::cout << create_product_a()->use_product_a() << std::endl;
  }
  void use_product_b() {
    std::cout << create_product_b()->use_product_b() << std::endl;
  }

private:
  std::shared_ptr<IFactory> factory;
};

#endif /* DESIGN_PATTERN_ABSTRACT_FACTORY_CLIENT_H_ */
