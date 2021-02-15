/*
 * Node.hpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_NODE_HPP_
#define DATA_STRUCTURE_NODE_HPP_



template<typename E>
class DLinkedList;

template<typename E>
struct Node{
	E elem;
	Node* pre;
	Node* next;
	friend class DLinkedList<E>;
};


#endif /* DATA_STRUCTURE_NODE_HPP_ */
