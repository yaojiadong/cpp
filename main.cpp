/*
 * main.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */

#include<array>
#include<vector>
#include<utility>
#include<memory>
#include<iostream>
#include<map>
#include<unordered_map>
#include<variant>
#include<iomanip>
#include<functional>


#include "template/templates.h"
#include "template/template_alias.h"
#include "ctor/default_ctor.h"
#include "tic-tac-toe/Tic-Tac-Toe.h"
#include "lambda/lambda.h"
#include "rvalue/rvalue.h"
#include "parameter_pack_auto/par_pack_auto.h"
#include "structure_binding/structure_binding.h"
#include "node_handle/node_handle.h"
#include "pow/pow.h"

#include "data_structure/Doubly_linked_list.h"
#include "data_structure/Array_stack.h"
#include "data_structure/List_stack.h"
#include "data_structure/Deque.h"
#include "data_structure/Iterator_doubly_linked_list.h"
#include "data_structure/Stack.h"
#include "tree/test_tree.h"
#include "design_pattern/adapter/test_adapter.h"
#include "design_pattern/bridge/test_bridge.h"
#include "design_pattern/observer/test_observer.h"
#include "design_pattern/singleton/test_singleton.h"
#include "design_pattern/factory_method/test_factory_method.h"
#include "design_pattern/abstract_factory/test_abstract_factory.h"
#include "design_pattern/builder/test_builder.h"
#include "design_pattern/prototype/test_prototype.h"
#include "design_pattern/composite/test_composite.h"

#include "concurrent/Test_concurrent_queue.h"

#include "typeid/typeid.h"

#include "variant/variant.h"
#include "union/test_tagged_union.h"
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
//	test_structure_binding();
//	test_node_handle();
//	test_pow();

//	test_tree();

//	test_adapter();
//	test_bridge();
//	test_observer();
//	test_singleton();

//	test_variant();
//	test_factory_method();

//	test_concurrent_queue();
//	test_tagged_union();

//	test_abstract_factory();
//	test_builder();
//	test_prototype();
	test_composite();

	return 0;
}

