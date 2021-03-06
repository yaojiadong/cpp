/*
 * Test_factory_method.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: jiado
 */


#include "Web_dialog.h"
#include "Windows_dialog.h"
#include "Dialog.h"
#include <iostream>

void client_code(Dialog & dialog){
	std::cout << "Client creates a button though I am not aware of dialog class.\n"
			<< dialog.render() << std::endl;

}


void test_factory_method(){
	Windows_dialog windows_dialog;
	Web_dialog web_dialog;

	client_code(windows_dialog);
	client_code(web_dialog);
}
