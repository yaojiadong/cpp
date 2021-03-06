/*
 * Windows_dialog.h
 *
 *  Created on: Mar 6, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_FACTORY_METHOD_WINDOWS_DIALOG_H_
#define DESIGN_PATTERN_FACTORY_METHOD_WINDOWS_DIALOG_H_


#include "Dialog.h"
#include "Windows_button.h"

class Windows_dialog : public Dialog{
public:
	IButton* create_button() override {return new Windows_button;}
};


#endif /* DESIGN_PATTERN_FACTORY_METHOD_WINDOWS_DIALOG_H_ */
