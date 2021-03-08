/*
 * test_decorator.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */




#include "test_decorator.h"
#include "Encrypt_decorator.h"
#include "Compression_decorator.h"
#include "File_data_source.h"

void test_decorator(){
	std::string data = "Here is my data to be written....";

	// Operations on data source itself
	std::shared_ptr<File_data_source> fds = std::make_shared<File_data_source>("My_file_name.c");
	fds->write_data(data);
	fds->read_data();

	// pass data source to decorator
	Encrypt_decorator ed{fds};
	Compression_decorator cd{fds};

	// Operations on the data source with decoration, ie, encryption
	ed.write_data(data);
	ed.read_data();
	// Operations on the data source with decoration, ie, compression
	cd.write_data(data);
	cd.read_data();


}
