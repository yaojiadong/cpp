/*
 * Product1.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_BUILDER_PRODUCT1_H_
#define DESIGN_PATTERN_BUILDER_PRODUCT1_H_

#include <iostream>
#include <vector>

class Product1{
public:
	std::vector<std::string> parts;

	void ListParts()const{
		std::cout << "Product1 has parts: ";
		for (size_t i=0;i<parts.size();i++){
			if(parts[i]== parts.back()){
				std::cout << parts[i];
			}else{
				std::cout << parts[i] << ", ";
			}
		}
		std::cout << "\n\n";
	}
};


#endif /* DESIGN_PATTERN_BUILDER_PRODUCT1_H_ */
