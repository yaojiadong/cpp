/*
 * BinaryTree.hpp
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

/**
 * This class is well-tested and mainly used by other modules.
 * */

#ifndef LINKED_BINARY_TREE_HPP_
#define LINKED_BINARY_TREE_HPP_


#include<stdexcept>
#include<list>


template<class E>
class Linked_binary_tree{

protected:
	struct Node{
		E elem;
		Node* par;
		Node* left;
		Node* right;
//		Node(const E & e = E{}):elem{e},par{nullptr},left{nullptr},right{nullptr}{}
		Node():elem{E()},par{nullptr},left{nullptr},right{nullptr}{}
		bool operator==(const Node & node){
			return this->elem == node.elem && this->left == node.left && this->right == node.right && this->par == node.par;

		}

		bool operator!=(const Node & node){
			return this->elem != node.elem || this->left != node.left || this->right != node.right || this->par != node.par;
		}
	};

public:
	class Position{
	private:
		Node* node;
	public:
		Position(Node* _node=nullptr):node{_node}{}

		E& operator*() const {return node->elem;}

		E* operator->() const {return &(node->elem);}

		bool operator==(const Position& p) const {return p.node == node;}

		bool operator!=(const Position& p) const {return p.node != node;}

		// what if the parent() is called on root? -> set nullptr as parent of root. see addRoot()
		Position parent() const{return Position(node->par);}

		Position left() const{return Position(node->left);}

		Position right() const{return Position(node->right);}

		Position sibling() const{return node->par->left==node? Position(node->par->right):Position(node->par->left);}

		bool isRoot() const {return node->par == nullptr;}

		bool isExternal() const {return node->left==nullptr && node->right==nullptr;}

		bool isInternal() const {return !isExternal();}

		friend class Linked_binary_tree;
	};

	using PositionList = std::list<Position>;

public:

	Linked_binary_tree():_root{nullptr},n{0}{}

	int size() const{return n;}

	bool empty() const{return n==0;}

	Position root() const{return Position{_root};}

	PositionList positions() const{ PositionList pl; preorder(_root, pl); return pl;}
	// set nullptr as parent of root,  _root->par = nullptr is done by ctor of Node()
	void addRoot(){_root = new Node(); n=1;}

	void expandExternal(const Position& p){
		Node* node = p.node;
		node->left = new Node;
		node->left->par = node;
		node->right = new Node;
		node->right->par = node;
		n += 2;
	}

//	void expandExternal(const Position& p, E left_elem, E right_elem){
//		Node* node = p.node;
//		node->left = new Node{left_elem};
//		node->left->par = node;
//		node->right = new Node{right_elem};
//		node->right->par = node;
//		n += 2;
//	}

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

	Position restructure(const Position& x){ //throw BoundaryViolation
		Position y = x.parent();
		Position z = y.parent();
		Position a, b, c, T0, T1, T2, T3;

		if(z.left() == y){
			c = z;
			if(y.left() == x){
				a = x;
				b = y;
				T1 = a.right();
			}
			if(y.right() == x){
				a = y;
				b = x;
				T1 = b.left();
			}
			T0 = a.left();
			T2 = b.right();
			T3 = c.right();
		}
		if(z.right() == y){
			a = z;
			if(y.left() == x){
				b = x;
				c = y;
				T2 = b.right();
			}
			if(y.right() == x){
				b = y;
				c = x;
				T2 = c.left();
			}

			T0 = a.left();
			T1 = b.left();
			T3 = c.right();
		}

		if(z.parent().left() == z){
			z.parent().node->left = b.node;
			b.node->par = z.parent().node;
		}
		if(z.parent().right() == z){
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
	void preorder(Node* node, PositionList& pl) const{
		pl.push_back(Position(node));
		if(node->left != nullptr) preorder(node->left,pl);
		if(node->right != nullptr) preorder(node->right, pl);
	}

private:
	Node* _root;
	int n;
};



#endif /* LINKED_BINARY_TREE_HPP_ */
