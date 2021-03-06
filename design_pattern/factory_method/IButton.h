/*
 * IButton.h
 *
 *  Created on: Mar 6, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_FACTORY_METHOD_IBUTTON_H_
#define DESIGN_PATTERN_FACTORY_METHOD_IBUTTON_H_

/*
 * https://refactoring.guru/design-patterns/factory-method
 */

#include <string>

class IButton{
public:
	virtual std::string render() = 0;
	virtual void onClick() = 0;
	virtual ~IButton(){}
};


#endif /* DESIGN_PATTERN_FACTORY_METHOD_IBUTTON_H_ */
