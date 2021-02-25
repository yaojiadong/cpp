/*
 * VBinaryTree.hpp
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

#ifndef TREE_VBINARYTREE_HPP_
#define TREE_VBINARYTREE_HPP_


#include <list>
#include "Vector.hpp"

template<class E>
class VBinaryTree{
//protected:
//	struct Node{
//		E elem;
//		int index;
//		Node(int _index):elem{},index{_index}{}
//	};


public:
	class Position{

	private:
		int index;
	public:
		Position(int i=0):index{i}{}

		int operator*(){return index;}

		Position parent() const{return Position((index-1)/2);}

		Position left() const{return Position(index*2+1);}

		Position right() const{return Position(index*2+2);}

		Position sibling() const{return index%2==0? Position(index-1):Position(index+1);}

		bool isRoot() const {return index == 0;}

		//TODO: how to identify the external node in an array based tree?
		bool isExternal() const {

			E e{}; //default value is used to identify if the place is occupied or empty. If both children is empty, the node is external

			return ((2*index+1>=vec.getCapacity()) || (vec[index*2+1]==e && vec[index*2+2]==e));
		}

		friend class VBinaryTree;
	};

	using PositionList = std::list<Position>;

public:
	VBinaryTree():vec{}{}

	int size() const{return vec.size();}

	bool empty() const{return vec.size()==0;}

	Position root() const{return Position(0);}

	PositionList positions() const{ PositionList pl; preorder(0, pl); return pl;}

	void addRoot(const E & elem){//vec[0] = new E;

		vec.insert(0, elem);
	}

	Vector<E> getVector(){return vec;}

	void expandExternal(const Position& p){
		int i = p.index;
		E elem{};
		vec.insert(i*2+1, elem);
		vec.insert(i*2+2, elem);
	}

	void expandExternal(const Position& p, const E& left_elem, const E& right_elem){
		int i = p.index;
		vec.insert(i*2+1, left_elem);
		vec.insert(i*2+2, right_elem);
	}

	//TODO
//	Position removeAboveExternal(const Position& p){}

protected:
	//TODO: only traverse the node that is not empty in the array.
	void preorder(int index, PositionList& pl) const{
		pl.push_back(Position(index));
		if(index*2+1<vec.getCapacity()) preorder(index*2+1,pl);
		if(index*2+2<vec.getCapacity()) preorder(index*2+2,pl);
	}

private:
//	std::vector<E*> vec;
	Vector<E> vec;
//	Vector<Node> vec;

};


#endif /* TREE_VBINARYTREE_HPP_ */
