/*
 * Data_source_decorator.h
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_DECORATOR_DATA_SOURCE_DECORATOR_H_
#define DESIGN_PATTERN_DECORATOR_DATA_SOURCE_DECORATOR_H_


#include "IData_source.h"
#include <memory>
#include <iostream>

class Data_source_decorator : public IData_source{
public:
	Data_source_decorator(const std::shared_ptr<IData_source> &ds):data_source{ds}{}
	virtual void write_data(std::string &data) override {data_source->write_data(data);}
	virtual void read_data() const override { return data_source->read_data();}

private:
	std::shared_ptr<IData_source> data_source;
};


#endif /* DESIGN_PATTERN_DECORATOR_DATA_SOURCE_DECORATOR_H_ */
