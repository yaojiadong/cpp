/*
 * HTML_button.h
 *
 *  Created on: Mar 6, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_FACTORY_METHOD_HTML_BUTTON_H_
#define DESIGN_PATTERN_FACTORY_METHOD_HTML_BUTTON_H_


#include "IButton.h"

class HTML_button : public IButton{
public:
	std::string render() override {return "HTML button rendering.\n";}
	void onClick() override {}
};


#endif /* DESIGN_PATTERN_FACTORY_METHOD_HTML_BUTTON_H_ */
