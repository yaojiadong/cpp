/*
 * test_binary_tree.cpp
 *
 *  Created on: Mar 2, 2021
 *      Author: jiado
 */

#include "../util.h"
#include "Entry.h"
#include "test_binary_tree.h"

void test_linked_binary_tree_int() {

  /*************************** test linked binary tree with int as element
   * ***************************/
  message("\ntest linked binary tree with int as element...");
  Linked_binary_tree<int> lbt;
  // using Pos = Linked_binary_tree<int>::Position;

  // lbt.add_root();
  //*(lbt.root()) = 2; // set element for root
  // lbt.expand_external(lbt.root());

  // Pos p = lbt.root().left();
  // lbt.expand_external(p);
  //*(p) = 5; // set element

  // p = lbt.root().right();
  // lbt.expand_external(p);
  //*(p) = 6;

  // alternative
  lbt.add_root(2);
  lbt.expand_external(lbt.root(), 5, 6);
  lbt.expand_external(lbt.root().left());
  lbt.expand_external(lbt.root().right());
  lbt.set_node(lbt.root().left().left(), 3);

  message("The size of tree is ", lbt.size());

  Linked_binary_tree<int>::PositionList pl = lbt.positions();
  for (auto p : pl) {
    std::cout << *p << std::endl;
  }
}

void test_linked_binary_tree_string() {
  /*************************** test vector binary tree with string as element
   * ***************************/
  message("Test linked binary tree with string as element...");
  Linked_binary_tree<std::string> lbt;
  build_tree(lbt);
  message("The size of tree is ", lbt.size());

  Linked_binary_tree<std::string>::PositionList pl = lbt.positions();
  for (auto p : pl) {
    std::cout << *p << std::endl;
  }

  message("Printing the expression:");
  lbt.print_expression(lbt.root());

  // optional: draw tree
  using less = Linked_binary_tree<std::string>::less;
  using Pos = Linked_binary_tree<std::string>::Position;
  std::multimap<std::pair<int, int>, Pos, less> m;
  message("\nComposing data as coordinates mapped to node value:");
  lbt.compose_data_inorder_for_drawing(lbt.root(), m);
  message("The size of map is ", m.size());

  message("\nPrint multimap impilicitly sorted by y coordinate:");
  for (const auto &e : m) {
    std::cout << "Coordinate: (" << e.first.first << ", " << e.first.second
              << "), Node value: " << *(e.second) << std::endl;
  }

  message("\nDrawing a tree using x,y coordinates:");
  lbt.draw(m); // a navie tree drawing.
}

void test_linked_binary_tree_entry() {

  /*************************** test linked binary tree with Entry as element
   * ***************************/
  message("\ntest linked binary tree with Entry as element...");

  Linked_binary_tree<Entry<int, std::string>> lbt;
  using Pos = Linked_binary_tree<Entry<int, std::string>>::Position;

  lbt.add_root();
  lbt.expand_external(lbt.root());
  lbt.root()->set_key(2); // set element for root
  lbt.root()->set_value("two");

  Pos p = lbt.root().left();
  lbt.expand_external(p);
  p->set_key(5);
  p->set_value("five");

  p = lbt.root().right();
  lbt.expand_external(p);
  p->set_key(6); // set element for root
  p->set_value("six");

  message("The size of tree is ", lbt.size());

  Linked_binary_tree<Entry<int, std::string>>::PositionList pl =
      lbt.positions();
  for (auto p : pl) {
    std::cout << p->key() << " " << p->value() << std::endl;
  }
}

void test_vector_binary_tree_int() {

  /*************************** test vector binary tree with int as element
   * ***************************/
  message("\ntest vector binary tree with int as element...");

  Vector_binary_tree<int> vbt;
  // using Pos = Vector_binary_tree<int>::Position;

  // vbt.add_root();
  // vbt.expand_external(vbt.root());
  //*(vbt.root()) = 2; // set element for root

  // Pos p = vbt.root().left();
  // vbt.expand_external(p);
  //*p = 5; // set element

  // p = vbt.root().right();
  // vbt.expand_external(p);
  //*p = 6;

  // alternative
  vbt.add_root(2);
  vbt.expand_external(vbt.root(), 5, 6);
  vbt.expand_external(vbt.root().left());
  vbt.expand_external(vbt.root().right());
  // vbt.set_node(vbt.root().left().left(), 2);

  message("The size of tree is ", vbt.size());
  message("The capacity of tree is ", vbt.size());

  Vector_binary_tree<int>::PositionList pl = vbt.positions();
  for (auto p : pl) {
    //		std::cout << vbt.element(p) << "\tExternal: " <<
    // p.isExternal()
    //<< std::endl;
    std::cout << *p << "\tExternal: " << (p.is_external() ? "true" : "false")
              << std::endl;
  }
}

void test_vector_binary_tree_entry() {

  /*************************** test vector binary tree with Entry as element
   * ***************************/
  message("\ntest vector binary tree with Entry as element...");

  Vector_binary_tree<Entry<int, std::string>> vbt;
  // using Pos = Vector_binary_tree<Entry<int, std::string>>::Position;
  //
  // vbt.add_root();
  // vbt.expand_external(vbt.root());
  // vbt.root()->set_key(2); // set element for root
  // vbt.root()->set_value("two");
  //
  // Pos p = vbt.root().left();
  // vbt.expand_external(p);
  // p->set_key(5);
  // p->set_value("five");
  //
  // p = vbt.root().right();
  // vbt.expand_external(p);
  // p->set_key(6); // set element for root
  // p->set_value("six");

  /* alternative */
  // Entry<int, std::string> e2{2, "two"};
  // Entry<int, std::string> e5{5, "five"};
  // Entry<int, std::string> e6{6, "six"};
  // vbt.add_root(e2);
  // vbt.expand_external(vbt.root(), e5, e6);

  vbt.add_root(Entry{2, std::string{"two"}});
  vbt.expand_external(vbt.root(), Entry{5, std::string{"five"}},
                      Entry{6, std::string{"six"}});

  vbt.expand_external(vbt.root().left());
  vbt.expand_external(vbt.root().right());

  message("The size of tree is ", vbt.size());
  message("The capacity of tree is ", vbt.size());

  Vector_binary_tree<Entry<int, std::string>>::PositionList pl =
      vbt.positions();
  for (auto p : pl) {
    std::cout << p->key() << " " << p->value() << std::endl;
  }
}

void test_binary_tree() {
  test_linked_binary_tree_int();

  test_linked_binary_tree_string();

  test_linked_binary_tree_entry();

  test_vector_binary_tree_int();

  test_vector_binary_tree_entry();
}