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

	// Operations on the data source with decoration, ie, encryption
	std::cout << "\nEncrypt data..." <<std::endl;
	Encrypt_decorator ed{fds};
	ed.write_data(data);
	ed.read_data();
	
	// Operations on the data source with decoration, ie, compression
	std::cout << "\nCompress data..." <<std::endl;
	Compression_decorator cd{fds};
	cd.write_data(data);
	cd.read_data();
	
	// Operations on the data source with decoration, ie, compression and encrypt
	std::cout << "\nCompress and encrypt data..." <<std::endl;
 	std::shared_ptr<IData_source> comp_enc_deco = std::make_shared<Compression_decorator>(std::make_shared<Encrypt_decorator>(ed));
// 	std::shared_ptr<IData_source> comp_enc_deco = std::make_shared<Compression_decorator>(std::make_shared<Encrypt_decorator>(fds));
	comp_enc_deco->write_data(data);
	comp_enc_deco->read_data();
}
