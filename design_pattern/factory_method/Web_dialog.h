/*
 * Web_dialog.h
 *
 *  Created on: Mar 6, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_FACTORY_METHOD_WEB_DIALOG_H_
#define DESIGN_PATTERN_FACTORY_METHOD_WEB_DIALOG_H_

#include "Dialog.h"
#include "HTML_button.h"

class Web_dialog : public Dialog{
public:
	std::unique_ptr<IButton> create_button() override {return std::make_unique<HTML_button>();}
};

#endif /* DESIGN_PATTERN_FACTORY_METHOD_WEB_DIALOG_H_ */
