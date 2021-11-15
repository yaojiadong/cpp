#pragma once

#include <iostream>

void message(const std::string &msg);

template <typename V> void message(const std::string &msg, const V &value) {
  std::cout << msg << value << std::endl;
}

/* This is used to build a tree with has a user defined element.
 * The user-defined element provides the functionality to evaluate arithmetic
 * expression. It is intended to be used for Euler_tour.h where the template
 * function pattern is implemented.
 */
template <typename T, typename E> void build_tree(T &tree) {
  using Pos = typename T::Position;

  tree.add_root(E{"-"});
  tree.expand_external(tree.root(), E{"/"}, E{"+"});
  Pos depth_1_left = tree.root().left();
  Pos depth_1_right = tree.root().right();
  tree.expand_external(depth_1_left, E{"*"}, E{"+"});
  tree.expand_external(depth_1_right, E{"*"}, E{"6"});

  Pos depth_1_left_depth_2_left = depth_1_left.left();
  Pos depth_1_left_depth_2_right = depth_1_left.right();
  Pos depth_1_right_depth_2_left = depth_1_right.left();
  tree.expand_external(depth_1_left_depth_2_left, E{"+"}, E{"3"});
  tree.expand_external(depth_1_left_depth_2_right, E{"-"}, E{"2"});
  tree.expand_external(depth_1_right_depth_2_left, E{"3"}, E{"-"});

  Pos depth_1_left_depth_2_left_depth_3_left = depth_1_left_depth_2_left.left();
  Pos depth_1_left_depth_2_right_depth_3_left =
      depth_1_left_depth_2_right.left();
  Pos depth_1_right_depth_2_left_depth_3_right =
      depth_1_right_depth_2_left.right();
  tree.expand_external(depth_1_left_depth_2_left_depth_3_left, E{"3"}, E{"1"});
  tree.expand_external(depth_1_left_depth_2_right_depth_3_left, E{"9"}, E{"5"});
  tree.expand_external(depth_1_right_depth_2_left_depth_3_right, E{"7"},
                       E{"4"});
}

/* Specialization with the second type as std::string. It is used for normal
 * tree building, but not for evaluating arithmetic expression.*/
template <typename T> void build_tree(T &tree) {
  build_tree<T, std::string>(tree);
}