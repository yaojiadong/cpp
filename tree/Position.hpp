/*
 * Position.hpp
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

#ifndef TREE_POSITION_HPP_
#define TREE_POSITION_HPP_

/**
 * Place the definition in the tree2 namespace to avoid multiple
 * definition of Node and Position in Linked_binary_tree.hpp
 * */

namespace tree2{

template<class E>
struct Node{
	E elem;
	Node* par;
	Node* left;
	Node* right;
	Node():elem{E()},par{nullptr},left{nullptr},right{nullptr}{}
};


/**Place the class declaration, which is necessary for the Position class
 * to define the friend class
 * */
template<class E>
class Linked_binary_tree;

template<class E>
class Position{
private:
	Node<E>* node;
public:
	Position(Node<E>* _node=nullptr):node{_node}{}

	E& operator*(){return node->elem;}

	Position parent() const{return Position(node->par);}

	Position left() const{return Position(node->left);}

	Position right() const{return Position(node->right);}

	Position sibling() const{return node->par->left==node? Position(node->par->right):Position(node->par->left);}

	bool isRoot() const {return node->par == nullptr;}

	bool isExternal() const {return node->left==nullptr && node->right==nullptr;}

	friend class Linked_binary_tree<E>;
};

} /* namespaecc tree2*/

#endif /* TREE_POSITION_HPP_ */
