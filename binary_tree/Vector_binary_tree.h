/*
 * Vector_binary_tree.h
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

/* For the vector implementation of binary tree,
 * 1. Not recommend: store Node into the vector. When insert, create a local
 * instance of Node, and store a copy of it. In this case, we dont have to
 * bother memory management at the cost of many copys of the object.
 * 2. Recommend: We could also directly store element into the vector without
 * the Node wrapper, since Node basically only contains the element, nothing
 * more.
 */
#ifndef VECTOR_BINARY_TREE_H_
#define VECTOR_BINARY_TREE_H_

#include "Vector.h"
#include <list>

template <class E> class Vector_binary_tree {

protected:
  struct Node {
    E elem;
    Node(const E &e = E{}) : elem{e} {}
  };

public:
  class Position {
  private:
    const Vector_binary_tree *vbt;
    int index;

  public:
    Position(const Vector_binary_tree *_vbt, int i = 0) : vbt{_vbt}, index{i} {}

    E &operator*() const { return vbt->vec.at(index)->elem; }

    E *operator->() const { return &(vbt->vec.at(index)->elem); }

    Position parent() const { return Position(vbt, (index - 1) / 2); }

    Position left() const { return Position(vbt, index * 2 + 1); }

    Position right() const { return Position(vbt, index * 2 + 2); }

    Position sibling() const {
      return index % 2 == 0 ? Position(vbt, index - 1)
                            : Position(vbt, index + 1);
    }

    bool is_root() const { return index == 0; }

    bool is_external() const {
      return (index * 2 + 1) >= vbt->vec.capacity() ||
             (vbt->vec.at(index * 2 + 1) == nullptr &&
              vbt->vec.at(index * 2 + 2) == nullptr);
    }

    bool is_internal() const { return !is_external(); }

    friend class Vector_binary_tree;
  };

  using PositionList = std::list<Position>;

public:
  Vector_binary_tree() : vec{} {}

  /* Delete all allocated nodes, including the ones that points to null, ie,
   * nullptr. Check how the reserve() is implemented in Vector.h*/
  ~Vector_binary_tree() {
    for (int i = 0; i < vec.capacity(); ++i) {
      delete vec[i];
    }
  }

  int size() const { return vec.size(); }

  int capacity() const { return vec.capacity(); }

  bool empty() const { return vec.size() == 0; }

  Position root() const { return Position(this, 0); }

  PositionList positions() const {
    PositionList pl;
    preorder(0, pl);
    return pl;
  }

  void add_root(const E &e = E{}) {
    Node *n = new Node(e);
    vec.insert(0, n);
  }

  void expand_external(const Position &p, const E &left_elem = E{},
                       const E &right_elem = E{}) {
    if (p.is_internal()) {
      throw std::runtime_error("expand internal node");
    }
    int i = p.index;
    vec.insert(i * 2 + 1, new Node{left_elem});
    vec.insert(i * 2 + 2, new Node{right_elem});
  }

protected:
  void preorder(int index, PositionList &pl) const {
    pl.push_back(Position{this, index});
    if (index * 2 + 1 < vec.capacity() && vec.at(index * 2 + 1) != nullptr) {
      preorder(index * 2 + 1, pl);
    }
    if (index * 2 + 2 < vec.capacity() && vec.at(index * 2 + 2) != nullptr) {
      preorder(index * 2 + 2, pl);
    }
    /* Alternative */
    // if (Position(this, index * 2 + 1).is_external()) {
    //  pl.push_back(Position{this, index * 2 + 1});
    //} else {
    //  preorder(index * 2 + 1, pl);
    //}
    // if (Position(this, index * 2 + 2).is_external()) {
    //  pl.push_back(Position{this, index * 2 + 2});
    //} else {
    //  preorder(index * 2 + 2, pl);
    //}
  }

private:
  Vector<Node *> vec;
};

#endif /* VECTOR_BINARY_TREE_H_ */
