/*
 * Builder2.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_BUILDER_BUILDER2_H_
#define DESIGN_PATTERN_BUILDER_BUILDER2_H_


#include "IBuilder.h"
#include "Product2.h"
#include <memory>

class Builder2 : public IBuilder{
public:
	Builder2(){this->reset();}

	void product_part_a() const override{p->parts.push_back("part a");}
	void product_part_b() const override{p->parts.push_back("part b");}
	void product_part_c() const override{p->parts.push_back("part c");}

	void reset(){p = std::make_shared<Product2>();}
	std::shared_ptr<Product2> product2() const {return p;}

private:
	std::shared_ptr<Product2> p;
};


#endif /* DESIGN_PATTERN_BUILDER_BUILDER2_H_ */
