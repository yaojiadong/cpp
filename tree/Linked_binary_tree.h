/*
 * BinaryTree.hpp
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_BINARYTREE_HPP_
#define DATA_STRUCTURE_BINARYTREE_HPP_


#include<exception>
#include<list>



template<class E>
class Linked_binary_tree{

protected:
	struct Node{
		E elem;
		Node* par;
		Node* left;
		Node* right;
		Node():elem{},par{nullptr},left{nullptr},right{nullptr}{}
	};

public:
	class Position{
	private:
		Node* node;
	public:
		Position(Node* _node=nullptr):node{_node}{}

		E& operator*(){return node->elem;}

		Position parent() const{return Position(node->par);}

		Position left() const{return Position(node->left);}

		Position right() const{return Position(node->right);}

		Position sibling() const{return node->par->left==node? Position(node->par->right):Position(node->par->left);}

		bool isRoot() const {return node->par == nullptr;}

		bool isExternal() const {return node->left==nullptr && node->right==nullptr;}

		friend class Linked_binary_tree;
	};

	using PositionList = std::list<Position>;

public:

	Linked_binary_tree():_root{nullptr},n{0}{}

	int size() const{return n;}

	bool empty() const{return n==0;}

	Position root() const{return Position{_root};}

	PositionList positions() const{ PositionList pl; preorder(_root, pl); return pl;}

	void addRoot(){_root = new Node; n=1;}

	void expandExternal(const Position& p){
		Node* node = p.node;
		node->left = new Node;
		node->left->par = node;
		node->right = new Node;
		node->right->par = node;
		n += 2;
	}

	void expandExternal(const Position& p, E left_elem, E right_elem){
		Node* node = p.node;
		node->left = new Node{left_elem};
		node->left->par = node;
		node->right = new Node{right_elem};
		node->right->par = node;
		n += 2;
	}

	Position removeAboveExternal(const Position& p){

		if(p.isRoot()){
			throw std::runtime_error("remove root");
		}
		if(!p.isExternal()){
			throw std::runtime_error("remove internal node");
		}

		Node* node = p.node;
		Node* par = node->par;
		Node* sib = p.sibling().node;
		if(node->par == _root){
			_root = sib;
			sib->par = nullptr;
		}else{
			Node* gpar = par->par;

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
		return Position(sib);
	}


protected:
	void preorder(Node* node, PositionList& pl) const{
		pl.push_back(Position(node));
		if(node->left != nullptr) preorder(node->left,pl);
		if(node->right != nullptr) preorder(node->right, pl);
	}

private:
	Node* _root;
	int n;
};



#endif /* DATA_STRUCTURE_BINARYTREE_HPP_ */
