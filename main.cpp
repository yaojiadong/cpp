/*
 * main.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */

#include<vector>
#include<utility>
#include<memory>
#include<iostream>
#include<map>
#include<unordered_map>
#include<variant>
#include<iomanip>
#include<functional>


//#include "typeid/typeid.hpp"
//#include "template/templates.hpp"
#include "template/template_alias.hpp"
//#include "ctor/default_ctor.hpp"
//#include "template/template_alias.hpp"
//#include "tic-tac-toe/Tic-Tac-Toe.h"
#include"lambda/lambda.h"
#include"rvalue/rvalue.h"
#include "parameter_pack_auto/par_pack_auto.h"
#include"structure_binding/structure_binding.h"
#include"node_handle/node_handle.h"

using namespace std;

#if __cplusplus
#endif



int main(){

//	test_typeid();
//	test_typeid_poly();

//	test_templates();
//	test_template_alias();

//	test_rvalue();
//	test_lambda();
//	test_par_pack_auto();

//  test_structure_binding();

	test_node_handle();


	return 0;
}

