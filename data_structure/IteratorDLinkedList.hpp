/*
 * IteratorDLinkedList.hpp
 *
 *  Created on: Feb 17, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_ITERATORDLINKEDLIST_HPP_
#define DATA_STRUCTURE_ITERATORDLINKEDLIST_HPP_


/*
 * Extension of the DLinkedList, in which iterator is used to encapsulate the node.
 * */



template<typename E>
class IteratorDLinkedList{

private:

	class Node{ //if use struct, friend class is not needed
	private:
		E elem;
		Node* pre;
		Node* next;
		friend class IteratorDLinkedList;
	};

public:

	class Iterator{
	public:
//		Iterator(Node* n):node{n}{}

		E& operator*(){
			return node->elem;
		}

		bool operator==(const Iterator& it) const{
			return node == it.node;
		}

		bool operator!=(const Iterator& it) const{
			return node != it.node;
		}
		/* prefix ++, e.g. ++it */
		Iterator& operator++(){
			node = node->next;
			return *this;
		}

		/* postfix ++, e.g. it++, return a copy */
		Iterator operator++(int){
			Iterator tmp = *this;
			++(*this);
//			node = node->next;  //equivalent to the above statement
			return tmp;
		}
		/* prefix --, e.g. --it */
		Iterator& operator--(){
			node = node->pre;
			return *this;
		}
		/* postfix --, e.g. it--, return a copy */
		Iterator operator--(int){
			Iterator tmp = *this;
			--(*this);
//			node = node->pre; //equivalent to the above statement
			return tmp;
		}

		/*
		 * Allow IteratorDLinkedList to access to the private members of Iterator
		 * */
		friend class IteratorDLinkedList;

	private:
		Node* node;
		/*
		 * Private ctor, need friend class. The Iterator can only be created
		 * in the IteratorDLinkedList object.
		 * */
		Iterator(Node* n):node{n}{}
	};

public:
	IteratorDLinkedList(){
		sz = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->pre = header;
	}

	~IteratorDLinkedList(){
		while(!empty()){
			pop_front();
		}
		delete header;
		delete trailer;
	}

	/* return a copy */
	Iterator begin() const {return Iterator(header->next);}
	Iterator end() const {return Iterator(trailer);}

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
	void addBefore(Node* v, const E& elem){
		Node* n = new Node;
		n->elem = elem;
		n->pre = v->pre;
		n->next = v;
		v->pre->next = n;
		v->pre = n;
		++sz;

	}

	void remove(Node* v){
		if(!empty()){
			Node* vpre = v->pre;
			Node* vnext = v->next;
			vpre->next = vnext;
			vnext->pre = vpre;
			delete v;
			--sz;
		}
	}

private:
	int sz;
	Node* header;
	Node* trailer;
};


#endif /* DATA_STRUCTURE_ITERATORDLINKEDLIST_HPP_ */
