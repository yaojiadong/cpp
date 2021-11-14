/*
 * test_tree.cpp
 *
 *  Created on: Mar 2, 2021
 *      Author: jiado
 */

#include "test_tree.h"
#include "Entry.h"
#include <iostream>
#include <string>

using namespace std;

static void message(const std::string &msg) { std::cout << msg << std::endl; }

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

  cout << "size is " << lbt.size() << endl;

  Linked_binary_tree<int>::PositionList pl = lbt.positions();
  for (auto p : pl) {
    std::cout << *p << std::endl;
  }
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

  cout << "size is " << lbt.size() << endl;

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

  cout << "size is " << vbt.size() << endl;
  cout << "capacity is " << vbt.capacity() << endl;

  Vector_binary_tree<int>::PositionList pl = vbt.positions();
  for (auto p : pl) {
    //		std::cout << vbt.element(p) << "\tExternal: " << p.isExternal()
    //<< std::endl;
    std::cout << *p << "\tExternal: " << p.is_external() << std::endl;
  }
}

void test_vector_binary_tree_entry() {

  /*************************** test vector binary tree with Entry as element
   * ***************************/
  message("\ntest vector binary tree with Entry as element...");

  Vector_binary_tree<Entry<int, std::string>> vbt;
  // using Pos = Vector_binary_tree<Entry<int, std::string>>::Position;

  // vbt.add_root();
  // vbt.expand_external(vbt.root());
  // vbt.root()->set_key(2); // set element for root
  // vbt.root()->set_value("two");

  // Pos p = vbt.root().left();
  // vbt.expand_external(p);
  // p->set_key(5);
  // p->set_value("five");

  // p = vbt.root().right();
  // vbt.expand_external(p);
  // p->set_key(6); // set element for root
  // p->set_value("six");

  // alternative
  Entry<int, std::string> e2{2, "two"};
  Entry<int, std::string> e5{5, "five"};
  Entry<int, std::string> e6{6, "six"};
  vbt.add_root(e2);
  vbt.expand_external(vbt.root(), e5, e6);
  vbt.expand_external(vbt.root().left());
  vbt.expand_external(vbt.root().right());

  cout << "size is " << vbt.size() << endl;
  cout << "capacity is " << vbt.capacity() << endl;

  Vector_binary_tree<Entry<int, std::string>>::PositionList pl =
      vbt.positions();
  for (auto p : pl) {
    std::cout << p->key() << " " << p->value() << std::endl;
  }
}
