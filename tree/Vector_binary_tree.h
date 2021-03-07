/*
 * VBinaryTree.hpp
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

#ifndef TREE_VBINARYTREE_HPP_
#define TREE_VBINARYTREE_HPP_


#include <list>
#include "Vector.h"

template<class E>
class Vector_binary_tree{
protected:
	struct Node{
		E elem;
		int index;

		Node(E e=E{}, int _index=-1):elem{e},index{_index}{}

		bool operator==(Node & node){
			return this->index == node.index;
		}

		bool operator!=(Node & node){
			return this->index != node.index;
		}
	};


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

		//TODO: how to identify the external node in an array based tree? BUT No access to vec
		bool isExternal() const {
			return 0;
//			Node e{}; //default value is used to identify if the place is occupied or empty. If both children is empty, the node is external
//			return ((2*index+1>=vec.getCapacity()) || (vec[index*2+1]==e && vec[index*2+2]==e));
		}

		friend class Vector_binary_tree;
	};

	using PositionList = std::list<Position>;

public:
	Vector_binary_tree():vec{}{}

	int size() const{return vec.size();}

	int capacity() const{return vec.getCapacity();}

	bool empty() const{return vec.size()==0;}

	Position root() const{return Position(0);}

	PositionList positions() const{ PositionList pl; preorder(0, pl); return pl;}

	void addRoot(const E & elem){
		vec.insert(0, Node(elem,0));
	}

	Vector<E> getVector(){return vec;}

	void expandExternal(const Position& p){
		int i = p.index;
		vec.insert(i*2+1, Node{});
		vec.insert(i*2+2, Node{});
	}

	void expandLeft(){

	}
	void expandRight(){

	}

	void expandExternal(const Position& p, const E& left_elem, const E& right_elem){
		int i = p.index;
		vec.insert(i*2+1, Node{left_elem,i*2+1});
		vec.insert(i*2+2, Node{right_elem,i*2+2});
	}

	//TODO
//	Position removeAboveExternal(const Position& p){}

	void printVector(){
		for(int i=0; i<vec.getCapacity(); ++i){
			std::cout<<vec.at(i).elem<<" ";
		}
		std::cout<<'\n';
	}

	void printTree(){
		for(auto p: positions() ){
			try{
				std::cout<<"At position "<<(*p)<< ", the value is"<<vec.at(*p).elem<<std::endl;
			}catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
		}
	}
protected:

	/* Only traverse the node that is not a default node in the array.
	 * Default node has index=-1
	 * */
	void preorder(int index, PositionList& pl) const{
		pl.push_back(Position(index));
		Node e{};
		if((index*2+1<vec.getCapacity()) && ((vec[index*2+1])!=e)) preorder(index*2+1,pl);
		if(index*2+2<vec.getCapacity() && vec[index*2+2]!=e) preorder(index*2+2,pl);
	}

private:
	Vector<Node> vec;
};


#endif /* TREE_VBINARYTREE_HPP_ */
