/*
 * Position.hpp
 *
 *  Created on: Feb 22, 2021
 *      Author: jiado
 */

#ifndef TREE_POSITION_HPP_
#define TREE_POSITION_HPP_


#include<list>

template<class E>
class PositionList{
public:
private:
	std::list<E> lst;
};

template <class E>
class Position{
public:
	E& operator*(){}

	Position parent() const{}

	PositionList<E> children() const{}

//	bool isRoot() const {}
//
//	bool isExternal() const {}
};





#endif /* TREE_POSITION_HPP_ */
