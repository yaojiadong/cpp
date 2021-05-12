/*
 * VBinaryTree.hpp
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

#ifndef TREE_VBINARYTREE_HPP_
#define TREE_VBINARYTREE_HPP_


#include <list>
#include <iostream>
#include "Vector.h"


template<class E>
class Vector_binary_tree{

protected:
	struct Node{
		E elem;
		bool _is_external;

		Node(bool is_external = true ):elem{E()},_is_external{is_external}{}

		bool operator==(const Node & node){
			return this->elem == node.elem;
		}

		bool operator!=(const Node & node){
			return this->elem != node.elem;
		}
	};

public:
	class Position{
//	private:
//		Node* _node;
//
//	public:
//		Position(const Node* node):_node{node}{}
//
//		E& operator*(){return _node->elem;}
//
//		Position parent() const{return Position((_node->_index-1)/2);}
//
//		Position left() const{return Position(_node->_index*2+1);}
//
//		Position right() const{return Position(_node->_index*2+2);}
//
//		Position sibling() const{return _node->_index%2==0? Position(_node->_index-1):Position(_node->_index+1);}
//
//		bool isRoot() const {return _node->_index == 0;}
//
//		bool isExternal() const {
//			return _node->_index == -1;
//		}

	private:
		int index;

	public:
		Position(int i=0):index{i}{}

		int operator*() const {return index;}

		Position parent() const{return Position((index-1)/2);}

		Position left() const{return Position(index*2+1);}

		Position right() const{return Position(index*2+2);}

		Position sibling() const{return index%2==0? Position(index-1):Position(index+1);}

		bool isRoot() const {return index == 0;}

		//TODO: how to identify the external node in an array based tree? BUT No access to vec
		bool isExternal() const {
			return 0;
//			return vec.at(index)->_is_external;
		}

		friend class Vector_binary_tree;
	};

	using PositionList = std::list<Position>;



public:
	Vector_binary_tree():vec{}{}

	int size() const{return vec.size();}

	int capacity() const{return vec.getCapacity();}

	bool empty() const{return vec.size()==0;}

	Position root() const {return Position(0);}

	PositionList positions() const{ PositionList pl; preorder(0, pl); return pl;}

	void addRoot(){
		Node* n = new Node(0);
		vec.insert(0, n);
	}

	void expandExternal(const Position& p){
		int i = p.index;
		vec.insert(i*2+1, new Node{}); //default node is external
		vec.insert(i*2+2, new Node{});
		vec.at(i)->_is_external = false;
	}

	// in linked tree, dereferencing Position gives element.
	// in vector based, passing a Position to the vector to get the Node ptr, which gives element.
	E& element(const Position& p) const {
		return vec.at(*p)->elem;
	}

	// Position itself cannot determine if the node is external. The access to the node, thus to the vec is necessary.
	bool is_external(const Position& p){
		return vec.at(*p)->_is_external;
	}

	//TODO
//	Position removeAboveExternal(const Position& p){}

//	void printVector(){
//		for(int i=0; i<vec.getCapacity(); ++i){
//			std::cout<<vec.at(i).elem<<" ";
//		}
//		std::cout<<'\n';
//	}
//
//	void printTree(){
//		for(auto p: positions() ){
//			try{
//				std::cout<<"At position "<<(*p)<< ", the value is "<<vec.at(*p).elem<<std::endl;
//			}catch(std::runtime_error& e){
//				std::cout<<e.what()<<std::endl;
//			}
//		}
//	}
protected:

	/* Only traverse the node that is not a default node in the array.
	 * Default node has index=-1
	 * */
	void preorder(int index, PositionList& pl) const{
		pl.push_back(Position(index));

		if((index*2+1 < vec.getCapacity()) ){
			if (vec.at(index*2+1)->_is_external == false){
				preorder(index*2+1,pl);
			}else{ // push the Position of the external node
				pl.push_back(Position(index*2+1));
			}
		}

		if((index*2+2 < vec.getCapacity()) ){
			if (vec.at(index*2+2)->_is_external == false){
				preorder(index*2+2,pl);
			}else{ // push the Position of the external node
				pl.push_back(Position(index*2+2));
			}
		}
	}

private:
	Vector<Node*> vec;

};


#endif /* TREE_VBINARYTREE_HPP_ */
