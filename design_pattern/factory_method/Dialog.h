/*
 * Dialog.h
 *
 *  Created on: Mar 6, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_FACTORY_METHOD_DIALOG_H_
#define DESIGN_PATTERN_FACTORY_METHOD_DIALOG_H_


#include "IButton.h"

class Dialog{
public:
	Dialog(){}
	virtual ~Dialog(){}

	// this method can be used in subclass that creates different types of buttons.
	std::string render(){
		IButton* button = this->create_button();
		std::string s = "Dialog creates " + button->render();

		delete button;
		return s;
	}

	virtual IButton* create_button() = 0;

private:

};


#endif /* DESIGN_PATTERN_FACTORY_METHOD_DIALOG_H_ */
