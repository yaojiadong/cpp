/*
 * Dialog.h
 *
 *  Created on: Mar 6, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_FACTORY_METHOD_DIALOG_H_
#define DESIGN_PATTERN_FACTORY_METHOD_DIALOG_H_


#include "IButton.h"
#include <memory>

class Dialog{
public:
	Dialog(){}
	virtual ~Dialog(){}

	// this method can be used in subclass that creates different types of buttons.
	std::string render(){
		std::unique_ptr<IButton> button = this->create_button();
		std::string s = "Dialog creates " + button->render();

		return s;
	}

	virtual std::unique_ptr<IButton> create_button() = 0;

private:

};


#endif /* DESIGN_PATTERN_FACTORY_METHOD_DIALOG_H_ */
