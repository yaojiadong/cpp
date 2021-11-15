#include "test_euler_tour.h"
#include "../../binary_tree/Linked_binary_tree.h"
#include "../../binary_tree/test_binary_tree.h"
#include "../../util.h"
#include "Element.h"
#include "Euler_tour.h"

void test_euler_tour_print_expression_linked_binary_tree() {
  message("\nTest template function pattern:");
  message("Test euler tour printing expression using linked binary tree:");

  Linked_binary_tree<std::string> lbt;
  build_tree(lbt);
  Print_exression<Linked_binary_tree<std::string>, std::string, std::string> pe;
  pe.execute(lbt);
  message("\n");
}

void test_euler_tour_print_expression_vecotr_binary_tree() {
  message("\nTest template function pattern:");
  message("Test euler tour printing expression using vector binary tree:");

  Vector_binary_tree<std::string> vbt;
  build_tree(vbt);
  Print_exression<Vector_binary_tree<std::string>, std::string, std::string> pe;
  pe.execute(vbt);
  message("\n");
}

void test_euler_tour_eval_expression_linked_binary_tree() {
  message("\nTest template function pattern:");
  message("Test euler tour evaluating expression using linked binary tree:");
  message("The user-defined Element with int as return type helped the "
          "evaluation:");

  Linked_binary_tree<Element<int>> lbt;
  build_tree<Linked_binary_tree<Element<int>>, Element<int>>(lbt);
  Evaluate_expression<Linked_binary_tree<Element<int>>, int, Element<int>> ep;
  ep.execute(lbt);
}

void test_euler_tour_eval_expression_vector_binary_tree() {
  message("\nTest template function pattern:");
  message("Test euler tour evaluating expression using vector binary tree:");
  message("The user-defined Element with int as return type helped the "
          "evaluation:");

  Vector_binary_tree<Element<int>> vbt;
  build_tree<Vector_binary_tree<Element<int>>, Element<int>>(vbt);
  Evaluate_expression<Vector_binary_tree<Element<int>>, int, Element<int>> ep;
  ep.execute(vbt);
}

void test_template_function() {

  test_euler_tour_print_expression_linked_binary_tree();

  test_euler_tour_print_expression_vecotr_binary_tree();

  test_euler_tour_eval_expression_linked_binary_tree();

  test_euler_tour_eval_expression_vector_binary_tree();
}