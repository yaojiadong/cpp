/*
 * DLinkedList.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jiado
 */

#include "DLinkedList.hpp"
#include<iostream>

template<typename E>
DLinkedList<E>::DLinkedList(){

	header = new Node<E>;
	trailer = new Node<E>;
	header->next = trailer;
	trailer->pre = header;
}

template<typename E>
DLinkedList<E>::~DLinkedList(){
	while(!empty()){
		pop_front();
	}
	delete header;
	delete trailer;
}

template<typename E>
void DLinkedList<E>::push_front(E& elem){
	addBefore(header->next, elem);
}

template<typename E>
void DLinkedList<E>::pop_front(){
	remove(header->next);
}

template<typename E>
void DLinkedList<E>::push_back(E& elem){
	addBefore(trailer, elem);
}

template<typename E>
void DLinkedList<E>::pop_back(){
	remove(trailer->pre);
}

/*
 * Unlike member list::begin, which returns an iterator to this same element, this function returns a direct reference.
 * Calling this function on an empty container causes undefined behavior.
 */
template<typename E>
const E& DLinkedList<E>::front() const{
//	if(!empty()){
		return header->next->elem;
//	}
}

/*
 * Unlike member list::end, which returns an iterator just past this element, this function returns a direct reference.
 * Calling this function on an empty container causes undefined behavior.
 */
template<typename E>
const E& DLinkedList<E>::back() const{
//	if(!empty()){
		return trailer->pre->elem;
//	}
}

template<typename E>
bool DLinkedList<E>::empty() const{
	return (header->next == trailer);
}

template<typename E>
void DLinkedList<E>::addBefore(Node<E>* v, const E& elem){
	Node<E>* n = new Node<E>;
	n->elem = elem;
	n->pre = v->pre;
	n->next = v;
	v->pre->next = n;
	v->pre = n;
}

template<typename E>
void DLinkedList<E>::remove(Node<E>* v){
	Node<E>* vpre = v->pre;
	Node<E>* vnext = v->next;
	vpre->next = vnext;
	vnext->pre = vpre;
	delete v;
}
