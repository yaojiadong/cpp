/*
 * Tree.h
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

/**
 * This header is not intended to be included in any other files.
 * It only presents an interface of a general. Later we focus on binary tree.
 * It can be used as a base class, only has to.
 * 1. add virtual to the functions that are to be overridden
 * 2. add virtual destructor
 * 3. define Position and PositionList
 */

/*
 * Algorithm preorder(T, p):
 * perform the “visit” action for node
 * for each child q of p do
 * recursively traverse the subtree rooted at q by calling preorder(T,q)
 *
 * Algorithm postorder(T, p):
 * for each child q of p do
 * recursively traverse the subtree rooted at q by calling postorder(T,q)
 * perform the “visit” action for node p
 *
 * */

#ifndef TREE_H_
#define TREE_H_

#include <list>

template <class E> class Tree {
public:
  class Position<E>;
  class PositionList<E>;

  // using Position = Position<E>;
  // using PositionList = std::list<Position>;

public:
  int size() const;
  bool empty() const;
  Position root() const;
  PositionList positions() const;
  void preorder() const;
  void postOrder() const;

  int depth(const Tree &T, const Position &p) {
    if (p.is_root()) {
      return 0;
    } else {
      return 1 + depth(T, p.parent());
    }
  }

  int height(const Tree &T) {
    int h = 0;
    PositionList nodes = positions();
    for (auto q : nodes) {
      if (q.isEnternal()) {
        h = max(h, depth(T, q));
      }
    }
    return h;
  }

  /**
   * Recursive, more efficient
   */
  int height2(const Tree &T, const Position &p) {
    if (p.is_external()) {
      return 0;
    } else {
      int h = 0;
      PositionList children = p.children();
      for (auto ch : children) {
        h = max(h, height2(T, ch));
      }
      return 1 + h;
    }
  }
};

#endif /* TREE_H_ */
