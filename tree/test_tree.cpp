/*
 * test_tree.cpp
 *
 *  Created on: Mar 2, 2021
 *      Author: jiado
 */


#include <iostream>
#include "test_tree.h"

using namespace std;

void test_tree(){

	/*************************** test vector binary tree***************************/
	Vector_binary_tree<int> vbt;
	vbt.addRoot(5);
	Vector_binary_tree<int>::Position p0{0};
	vbt.expandExternal(p0, 1, 10);
	Vector_binary_tree<int>::Position p2{2};
	vbt.expandExternal(p2,3,6);
	Vector_binary_tree<int>::Position p5{5};
	vbt.expandExternal(p5,23,26);

//	cout<<p0.isExternal();
	cout<<"size is "<<vbt.size()<<endl;
	cout<<"capacity is "<<vbt.capacity()<<endl;

	vbt.printVector();
	vbt.printTree();


	/*************************** test linked binary tree ***************************/
	Linked_binary_tree<int> lbt;
	lbt.addRoot(5);
	lbt.expandExternal(lbt.root(), 1, 10);
	lbt.expandExternal(lbt.root().left(),3,6);
	lbt.expandExternal(lbt.root().right(),23,26);

	cout<<"size is "<<lbt.size()<<endl;

	Linked_binary_tree<int>::PositionList pl = lbt.positions();
	for(auto p : pl){
		std::cout << *p << std::endl;
	}


	/*************************** test linked binary tree2 ***************************/
	tree2::Linked_binary_tree<int> lbt2;
	lbt2.addRoot(5);
	lbt2.expandExternal(lbt2.root(), 1, 10);
	lbt2.expandExternal(lbt2.root().left(),3,6);
	lbt2.expandExternal(lbt2.root().right(),23,26);

	cout<<"size is "<<lbt2.size()<<endl;

	tree2::Linked_binary_tree<int>::PositionList pl2 = lbt2.positions();
	for(auto p : pl2){
		std::cout << *p << std::endl;
	}





//	lbt.printVector();
//	lbt.printTree();



}
