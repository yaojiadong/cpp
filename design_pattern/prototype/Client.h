/*
 * Client.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_PROTOTYPE_CLIENT_H_
#define DESIGN_PATTERN_PROTOTYPE_CLIENT_H_

//namespace prototype{

#include "IShape.h"
#include <unordered_map>


enum class Type{circle, rectangle};

class Client{

public:
	Client(){}
	void add_prototype(Type t, IShape* p){prototypes[t] = p;}

	IShape* clone_type(Type t) {return prototypes[t]->clone();}

	std::unordered_map<Type,IShape*> get_prototypes() const {return prototypes;}

private:
	std::unordered_map<Type,IShape*> prototypes;

};

//}

#endif /* DESIGN_PATTERN_PROTOTYPE_CLIENT_H_ */
