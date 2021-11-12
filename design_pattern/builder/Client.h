/*
 * Client.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_BUILDER_CLIENT_H_
#define DESIGN_PATTERN_BUILDER_CLIENT_H_

#include "Director.h"

class Client {
public:
  Client(Director &d) : director{d} {}
  void ask_for_simple_product() { director.build_simple_product(); }
  void ask_for_full_product() { director.build_full_product(); }

  //	void ask_for_simple_product() {director.build_simple_product();}
  //	void ask_for_full_product1() {director.build_full_product();}

private:
  Director &director;
};

#endif /* DESIGN_PATTERN_BUILDER_CLIENT_H_ */
