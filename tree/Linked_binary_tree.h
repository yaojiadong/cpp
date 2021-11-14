/*
 * Linked_binary_tree.h
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

/**
 * This class is well-tested and mainly used by other modules.
 * */

#ifndef LINKED_BINARY_TREE_H_
#define LINKED_BINARY_TREE_H_

#include <iostream>
#include <list>
#include <stdexcept>

template <class E> class Linked_binary_tree {

protected:
  struct Node {
    E elem;
    Node *par;
    Node *left;
    Node *right;

    Node(const E &e = E())
        : elem{e}, par{nullptr}, left{nullptr}, right{nullptr} {}

    bool operator==(const Node &node) {
      return this->elem == node.elem && this->left == node.left &&
             this->right == node.right && this->par == node.par;
    }

    bool operator!=(const Node &node) {
      return this->elem != node.elem || this->left != node.left ||
             this->right != node.right || this->par != node.par;
    }
  };

public:
  class Position {
  private:
    Node *node;

  public:
    Position(Node *_node = nullptr) : node{_node} {}

    E &operator*() const { return node->elem; }

    E *operator->() const { return &(node->elem); }

    bool operator==(const Position &p) const { return p.node == node; }

    bool operator!=(const Position &p) const { return p.node != node; }

    Position parent() const { return Position(node->par); }

    Position left() const { return Position(node->left); }

    Position right() const { return Position(node->right); }

    Position sibling() const {
      return node->par->left == node ? Position(node->par->right)
                                     : Position(node->par->left);
    }

    bool is_root() const { return node->par == nullptr; }

    bool is_external() const {
      return node->left == nullptr && node->right == nullptr;
    }

    bool is_internal() const { return !is_external(); }

    friend class Linked_binary_tree;
  };

  using PositionList = std::list<Position>;

public:
  Linked_binary_tree() : _root{nullptr}, n{0} {}

  ~Linked_binary_tree() {
    // PositionList pl = positions();
    // for (auto p : pl) {
    //  delete p.node;
    //}

    // alternative
    postorder_destructor(_root);
  }

  int size() const { return n; }

  bool empty() const { return n == 0; }

  Position root() const { return Position{_root}; }

  PositionList positions() const {
    PositionList pl;
    // preorder(_root, pl);
    // inorder(_root, pl);
    postorder(_root, pl);
    return pl;
  }

  void add_root(const E &e = E{}) {
    _root = new Node(e);
    n = 1;
  }

  // void expand_external(const Position &p) {
  //  Node *node = p.node;
  //  node->left = new Node;
  //  node->left->par = node;
  //  node->right = new Node;
  //  node->right->par = node;
  //  n += 2;
  //}

  void expand_external(const Position &p, const E &left_elem = E{},
                       const E &right_elem = E{}) {
    if (p.is_internal()) {
      throw std::runtime_error("expand internal node");
    }
    Node *node = p.node;
    node->left = new Node{left_elem};
    node->left->par = node;
    node->right = new Node{right_elem};
    node->right->par = node;
    n += 2;
  }

  void set_node(const Position &p, const E &e) const { *p = e; }

  Position remove_above_external(const Position &p) {
    if (p.is_root()) {
      throw std::runtime_error("remove root");
    }
    if (p.is_internal()) {
      throw std::runtime_error("remove internal node");
    }

    Node *node = p.node;
    Node *par = node->par;
    Node *sib = p.sibling().node;
    if (node->par == _root) {
      _root = sib;
      sib->par = nullptr;
    } else {
      Node *gpar = par->par;
      sib->par = gpar;
      if (gpar->left == par) {
        gpar->left = sib;
      } else {
        gpar->right = sib;
      }
    }

    delete par;
    delete node;
    n -= 2;
    return Position(sib);
  }

  Position restructure(const Position &x) { // throw BoundaryViolation
    Position y = x.parent();
    Position z = y.parent();
    Position a, b, c, T0, T1, T2, T3;

    if (z.left() == y) {
      c = z;
      if (y.left() == x) {
        a = x;
        b = y;
        T1 = a.right();
      }
      if (y.right() == x) {
        a = y;
        b = x;
        T1 = b.left();
      }
      T0 = a.left();
      T2 = b.right();
      T3 = c.right();
    }
    if (z.right() == y) {
      a = z;
      if (y.left() == x) {
        b = x;
        c = y;
        T2 = b.right();
      }
      if (y.right() == x) {
        b = y;
        c = x;
        T2 = c.left();
      }

      T0 = a.left();
      T1 = b.left();
      T3 = c.right();
    }

    if (z.parent().left() == z) {
      z.parent().node->left = b.node;
      b.node->par = z.parent().node;
    }
    if (z.parent().right() == z) {
      z.parent().node->right = b.node;
      b.node->par = z.parent().node;
    }

    b.node->left = a.node;
    b.node->right = c.node;
    a.node->par = b.node;
    c.node->par = b.node;

    a.node->left = T0.node;
    a.node->right = T1.node;
    T0.node->par = a.node;
    T1.node->par = a.node;

    c.node->left = T2.node;
    c.node->right = T3.node;
    T2.node->par = c.node;
    T3.node->par = c.node;

    return b;
  }

protected:
  void preorder(Node *node, PositionList &pl) const {
    pl.push_back(Position(node));
    if (node->left != nullptr)
      preorder(node->left, pl);
    if (node->right != nullptr)
      preorder(node->right, pl);
  }

  void postorder(Node *node, PositionList &pl) const {
    if (node->left != nullptr)
      postorder(node->left, pl);
    if (node->right != nullptr)
      postorder(node->right, pl);
    pl.push_back(Position(node));
  }

  void inorder(Node *node, PositionList &pl) const {
    if (node->left != nullptr)
      inorder(node->left, pl);
    pl.push_back(Position(node));
    if (node->right != nullptr)
      inorder(node->right, pl);
  }

  void postorder_destructor(Node *node) const {
    if (node->left != nullptr)
      postorder_destructor(node->left);
    if (node->right != nullptr)
      postorder_destructor(node->right);
    delete node;
  }

private:
  Node *_root;
  int n;
};

#endif /* LINKED_BINARY_TREE_H_ */
