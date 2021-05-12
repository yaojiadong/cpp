/*
 * Linked_binary_tree2.h
 *
 *  Created on: Apr 21, 2021
 *      Author: jiado
 */

#ifndef TREE_LINKED_BINARY_TREE_V2_HPP_
#define TREE_LINKED_BINARY_TREE_V2_HPP_


#include <stdexcept>
#include <list>
#include "Position.hpp"

/**
 * The 2nd version of Linked binary tree class does not contain the Position class and Node struct
 * This file includes the Position.hpp, where the Position and Node are defined in namespace tree2.
 */

namespace tree2{

//template<class E>
//struct Node{
//	E elem;
//	Node* par;
//	Node* left;
//	Node* right;
////	Node(const E & e = E{}):elem{e},par{nullptr},left{nullptr},right{nullptr}{}
//	Node():elem{E()},par{nullptr},left{nullptr},right{nullptr}{}
//};


//template<class E>
//class Linked_binary_tree;

//template<class E>
//class Position{
//private:
//	Node<E>* node;
//public:
//	Position(Node<E>* _node=nullptr):node{_node}{}
//
//	E& operator*(){return node->elem;}
//
//	Position parent() const{return Position(node->par);}
//
//	Position left() const{return Position(node->left);}
//
//	Position right() const{return Position(node->right);}
//
//	Position sibling() const{return node->par->left==node? Position(node->par->right):Position(node->par->left);}
//
//	bool isRoot() const {return node->par == nullptr;}
//
//	bool isExternal() const {return node->left==nullptr && node->right==nullptr;}
//
//	friend class Linked_binary_tree<E>;
//};



template<class E>
class Linked_binary_tree{

protected:
public:
	using PositionList = std::list<Position<E>>;

public:

	Linked_binary_tree():_root{nullptr},n{0}{}

	int size() const{return n;}

	bool empty() const{return n==0;}

	Position<E> root() const{return Position<E>{_root};}

	PositionList positions() const{ PositionList pl; preorder(_root, pl); return pl;}

	void addRoot(){_root = new Node<E>(); n=1;}

	void expandExternal(const Position<E>& p){
		Node<E>* node = p.node;
		node->left = new Node<E>;
		node->left->par = node;
		node->right = new Node<E>;
		node->right->par = node;
		n += 2;
	}

//	void expandExternal(const Position<E>& p, const E & left_elem, const E & right_elem){
//		Node<E>* node = p.node;
//		node->left = new Node<E>{left_elem};
//		node->left->par = node;
//		node->right = new Node<E>{right_elem};
//		node->right->par = node;
//		n += 2;
//	}

	Position<E> removeAboveExternal(const Position<E>& p){

		if(p.isRoot()){
			throw std::runtime_error("remove root");
		}
		if(!p.isExternal()){
			throw std::runtime_error("remove internal node");
		}

		Node<E>* node = p.node;
		Node<E>* par = node->par;
		Node<E>* sib = p.sibling().node;
		if(node->par == _root){
			_root = sib;
			sib->par = nullptr;
		}else{
			Node<E>* gpar = par->par;

			sib->par = gpar;
			if(gpar->left == par){
				gpar->left = sib;
			}else{
				gpar->right = sib;
			}
		}

		delete par;
		delete node;
		n -= 2;
		return Position<E>(sib);
	}


protected:
	void preorder(Node<E>* node, PositionList& pl) const{
		pl.push_back(Position<E>(node));
		if(node->left != nullptr) preorder(node->left,pl);
		if(node->right != nullptr) preorder(node->right, pl);
	}

private:
	Node<E>* _root;
	int n;
};

} // end of namespace tree2

#endif /* TREE_LINKED_BINARY_TREE_V2_HPP_ */
