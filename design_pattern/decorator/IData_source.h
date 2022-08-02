/*
 * Data_source.h
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_DECORATOR_DATA_SOURCE_H_
#define DESIGN_PATTERN_DECORATOR_DATA_SOURCE_H_

#include <string>

class IData_source{
public:
	virtual ~IData_source(){}
	virtual void write_data(std::string &data) = 0;
	virtual void read_data() const = 0;
};


#endif /* DESIGN_PATTERN_DECORATOR_DATA_SOURCE_H_ */
