/*
 * File_data_source.h
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_DECORATOR_FILE_DATA_SOURCE_H_
#define DESIGN_PATTERN_DECORATOR_FILE_DATA_SOURCE_H_



#include "IData_source.h"
#include <iostream>

class File_data_source : public IData_source{
public:
	File_data_source(const std::string &s):filename{s}{}
	virtual void write_data(std::string &data) override {std::cout << "Write data: " << data << " to "<< filename <<"\n";}
	virtual void read_data() const override {std::cout << "Read data from file: " << filename << "\n"; return "";}

private:
	std::string filename;
};

#endif /* DESIGN_PATTERN_DECORATOR_FILE_DATA_SOURCE_H_ */
