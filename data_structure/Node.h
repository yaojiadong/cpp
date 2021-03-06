/*
 * Node.hpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_NODE_H_
#define DATA_STRUCTURE_NODE_H_



template<typename E>
class Doubly_linked_list;

template<typename E>
struct Node{
	E elem;
	Node* pre;
	Node* next;
	friend class Doubly_linked_list<E>;
};


#endif /* DATA_STRUCTURE_NODE_H_ */
