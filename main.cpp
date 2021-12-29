/*
 * main.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */

#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

#include "concurrent/Test_concurrent_queue.h"
#include "ctor/ctor.h"
#include "lambda/lambda.h"
#include "node_handle/node_handle.h"
#include "operator_overloading/My_integer.h"
#include "parameter_pack_auto/par_pack_auto.h"
#include "pow/pow.h"
#include "rvalue/rvalue.h"
#include "structure_binding/structure_binding.h"
#include "template/template_alias.h"
#include "template/templates.h"
#include "tic-tac-toe/Tic-Tac-Toe.h"
#include "typeid/typeid.h"
#include "union/test_tagged_union.h"
#include "variant/variant.h"

#include "container/Array_stack.h"
#include "container/Deque.h"
#include "container/Doubly_linked_list.h"
#include "container/Iterator_doubly_linked_list.h"
#include "container/List_stack.h"
#include "container/Stack.h"

#include "design_pattern/abstract_factory/test_abstract_factory.h"
#include "design_pattern/adapter/test_adapter.h"
#include "design_pattern/bridge/test_bridge.h"
#include "design_pattern/builder/test_builder.h"
#include "design_pattern/composite/test_composite.h"
#include "design_pattern/decorator/test_decorator.h"
#include "design_pattern/factory_method/test_factory_method.h"
#include "design_pattern/observer/test_observer.h"
#include "design_pattern/prototype/test_prototype.h"
#include "design_pattern/singleton/test_singleton.h"
#include "design_pattern/template_function/test_euler_tour.h"

#include "binary_search_tree/test_AVL_tree.h"
#include "binary_search_tree/test_binary_search_tree.h"
#include "binary_tree/test_binary_tree.h"

#include "smart_pointer/Shared_ptr.h"

#include "ctor/test_ctor_copy_swap.h"
using namespace std;

//#if __cplusplus
//#endif

int main() {

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
  //	test_operator_overloading();

  test_binary_tree();

  //	test_search_tree();
  //	test_AVL_tree();

  // test_adapter();
  // test_bridge();
  //	test_observer();
  //	test_singleton();
  //	test_abstract_factory();
  //	test_builder();
  //	test_prototype();
  // test_composite();
  //	test_decorator();
  // test_template_function();

  // test_euler_tour_print_expression_linked_binary_tree();
  // test_euler_tour_print_expression_vecotr_binary_tree();
  // test_euler_tour_eval_expression_linked_binary_tree();
  // test_euler_tour_eval_expression_vector_binary_tree();

  //	test_variant();
  //	test_factory_method();

  //	test_concurrent_queue();
  //	test_tagged_union();

  // test_shared_ptr();
  // test_ctor_copy_swap();

  return 0;
}
