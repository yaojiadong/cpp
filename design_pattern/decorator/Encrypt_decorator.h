/*
 * Encrypt_decorator.h
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_DECORATOR_ENCRYPT_DECORATOR_H_
#define DESIGN_PATTERN_DECORATOR_ENCRYPT_DECORATOR_H_

#include "Data_source_decorator.h"

class Encrypt_decorator : public Data_source_decorator
{
public:
	Encrypt_decorator(const std::shared_ptr<IData_source> &ds) : Data_source_decorator{ds} {}
	virtual void write_data(std::string &data) override
	{
		std::cout << "Data encrypted\n";
		Data_source_decorator::write_data(data);
	}
	virtual void read_data() const override
	{
		Data_source_decorator::read_data();
		std::cout << "Data read and decrypted\n";
	}
};

#endif /* DESIGN_PATTERN_DECORATOR_ENCRYPT_DECORATOR_H_ */
