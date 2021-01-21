/*
 * structure_binding.cpp
 *
 *  Created on: Jan 21, 2021
 *      Author: jiadong
 */

#include<iostream>
#include<unordered_map>
#include<map>
#include"structure_binding.h"

using namespace std;

void test_structure_binding(){
	std::unordered_map<std::string, int> mapping {
	  {"a", 1},
	  {"c", 3},
	  {"b", 2}

	};

	// Destructure by reference.
	for (const auto& [key, value] : mapping) {
	  // Do something with key and value
		cout<<key << value<< endl;
		if(key == "a")
			mapping[key] = value+5;
		cout<<key << value<< endl;
	}

}
