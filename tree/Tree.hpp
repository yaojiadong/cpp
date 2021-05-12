/*
 * Tree.hpp
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */


/**
 * This header is not included in any other files.
 * It is just for study purpose.
 */


/*
 * Algorithm preorder(T, p):
 * perform the “visit” action for node
 * for each child q of p do
 * recursively traverse the subtree rooted at q by calling preorder(T,q)
 *
 * Algorithm postorder(T, p):
 * for each child q of p do
 * recursively traverse the subtree rooted at q by calling postorder(T,q)
 * perform the “visit” action for node p
 *
 * */

#ifndef DATA_STRUCTURE_TREE_HPP_
#define DATA_STRUCTURE_TREE_HPP_

#include "Position.hpp"
#include <list>

template<class E>
class Tree{
public:
//	class Position<E>;
//	class PositionList<E>;

	using Position = typename tree2::Position<E>;
	using PositionList = std::list<Position>;

public:
	int size() const;
	bool empty() const;
	Position root() const;

	/* return positions of all nodes */
	PositionList positions() const;
//	PositionList positions() const {PositionList pl; preorder(_root, pl); return pl;}

	int depth(const Tree& T, const Position& p){
		if(p.isRoot()){
			return 0;
		}else{
			return 1+depth(T, p.parent());
		}
	}

	int height(const Tree& T){
		int h=0;
		PositionList nodes = positions();
		for(auto q: nodes){
			if(q.isEnternal()){
				h = max(h,depth(T, q));
			}
		}
		return h;
	}

	/**
	 * Recursive, more efficient
	 */
	int height2(const Tree& T, const Position& p){
		if(p.isExternal()){
			return 0;
		}else{
			int h=0;
			PositionList children = p.children();
			for(auto ch : children){
				h = max(h,height2(T, ch));
			}
			return 1+h;
		}
	}
};


#endif /* DATA_STRUCTURE_TREE_HPP_ */
