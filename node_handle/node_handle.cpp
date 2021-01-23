/*
 * node_handle.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: jiado
 */



/*
 * Reference:
 * https://en.cppreference.com/w/cpp/container/map/extract
 * https://en.cppreference.com/w/cpp/container/node_handle
 *
 */

#include"node_handle.h"
#include<map>
#include<string>
#include<iostream>

using namespace std;

void test_node_handle(){

	std::map<int, string> m {{1, "one"}, {2, "two"}, {3, "three"}};
	auto e = m.extract(2);  //return a node handle that is unspecified.
	e.key() = 4;
	m.insert(std::move(e));  // Node handle is move-only.
//	m.insert(e);  //ERROR
	for(auto a :m){
		cout<<a.first << a.second << endl;
	}
}
