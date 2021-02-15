/*
 * DLinkedList.hpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_DLINKEDLIST_HPP_
#define DATA_STRUCTURE_DLINKEDLIST_HPP_

//#include "Node.hpp"

/* The declaration is a must for declaration of the Node class, where the friend class is declared. */
template<typename E>
class DLinkedList;

template<typename E>
class Node{
private:
	E elem;
	Node* pre;
	Node* next;
	friend class DLinkedList<E>;
};

template<typename E>
class DLinkedList{

private:

	/* if take the node as an attribute of the linked list, the Node is not a template anymore.*/
//	class Node{
//	private:
//		E elem;
//		Node* pre;
//		Node* next;
//		friend class DLinkedList;
//	};

public:
	DLinkedList();
	~DLinkedList();

	void push_front(E&);
	void pop_front();
	void push_back(E&);
	void pop_back();
	const E& front() const;
	const E& back() const;
	bool empty() const;


protected:  //local utilities, helper function for internal use
	void addBefore(Node<E>* v, const E& e); //insert node before v
	void remove(Node<E>* v); // remove node before v

private:
	Node<E>* header;
	Node<E>* trailer;
};




#endif /* DATA_STRUCTURE_DLINKEDLIST_HPP_ */
