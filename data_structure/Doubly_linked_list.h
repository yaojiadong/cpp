/*
 * DLinkedList.hpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jiado
 *
 *      Note: do not separate declaration and definition of a template!!!
 *      https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 *      https://stackoverflow.com/questions/115703/storing-c-template-function-definitions-in-a-cpp-file#:~:text=When%20used%20together%20with%20explicit,function%20code%20in%20cpp%20files.
 *
 */

#ifndef DATA_STRUCTURE_DOUBLY_LINKED_LIST_H_
#define DATA_STRUCTURE_DOUBLY_LINKED_LIST_H_

//#include "Node.hpp"

/* The declaration is a must for declaration of the Node class, where the friend class is declared. */
template<typename E>
class Doubly_linked_list;

template<typename E>
class Node{
private:
	E elem;
	Node* pre;
	Node* next;
	friend class Doubly_linked_list<E>;
};

template<typename E>
class Doubly_linked_list{

private:

	/* If take the node as an attribute of the linked list, the Node is not a template anymore.*/
//	class Node{
//	private:
//		E elem;
//		Node* pre;
//		Node* next;
//		friend class DLinkedList;
//	};

public:
	Doubly_linked_list(){
		sz = 0;
		header = new Node<E>;
		trailer = new Node<E>;
		header->next = trailer;
		trailer->pre = header;
	}

	~Doubly_linked_list(){
		while(!empty()){
			pop_front();
		}
		delete header;
		delete trailer;
	}

	void push_front(const E& elem){addBefore(header->next, elem);}
	void pop_front(){remove(header->next);}
	void push_back(const E& elem){addBefore(trailer, elem);}
	void pop_back() {remove(trailer->pre);}

	/*
	 * Unlike member list::begin, which returns an iterator to this same element, this function returns a direct reference.
	 * Calling this function on an empty container causes undefined behavior.
	 */
	const E& front() const {return header->next->elem;}

	/*
	 * Unlike member list::end, which returns an iterator just past this element, this function returns a direct reference.
	 * Calling this function on an empty container causes undefined behavior.
	 */
	const E& back() const {return trailer->pre->elem;}
	bool empty() const {return (header->next == trailer);}
	int size() const {return sz;}

protected:  //local utilities, helper function for internal use
	/*
	 * Insert node before v
	 * */
	void addBefore(Node<E>* v, const E& elem){
		Node<E>* n = new Node<E>;
		n->elem = elem;
		n->pre = v->pre;
		n->next = v;
		v->pre->next = n;
		v->pre = n;
		++sz;

	}

	void remove(Node<E>* v){
		if(!empty()){
			Node<E>* vpre = v->pre;
			Node<E>* vnext = v->next;
			vpre->next = vnext;
			vnext->pre = vpre;
			delete v;
			--sz;
		}
	}

private:
	int sz;
	Node<E>* header;
	Node<E>* trailer;
};



#endif /* DATA_STRUCTURE_DOUBLY_LINKED_LIST_H_ */
