/*
 * Position.h
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

/* This header is not intended to be included. The various tree implementation
 * has its own Position definition. The tree needs access to the private
 * attribute (Node) of Position, so Tree has to be defined as friend inside
 * Position.
 */

#ifndef POSITION_H_
#define POSITION_H_

template <class E> class Position {
public:
  struct Node {
    E elem;
    Node *par;
    Node *left;
    Node *right;
    Node() : elem{E()}, par{nullptr}, left{nullptr}, right{nullptr} {}
  };

private:
  Node *node;

public:
  Position(E *_node = nullptr) : node{_node} {}

  E &operator*() { return node->elem; }

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
};

#endif /* POSITION_H_ */
