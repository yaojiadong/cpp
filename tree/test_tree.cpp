/*
 * test_tree.cpp
 *
 *  Created on: Mar 2, 2021
 *      Author: jiado
 */


#include <iostream>
#include "test_tree.hpp"

using namespace std;

void test_tree(){
	VBinaryTree<int> vbt;
//	VBT<int> vbt;
	vbt.addRoot(5);
	VBinaryTree<int>::Position p0{0};
	vbt.expandExternal(p0, 1, 10);
//	vbt.expandExternal(vbt.root(), 1, 10);
	VBinaryTree<int>::Position p{2};
	vbt.expandExternal(p,3,6);

	VBinaryTree<int>::Position p5{5};
	vbt.expandExternal(p5,23,26);

//	cout<<p0.isExternal();
	cout<<"size is "<<vbt.size()<<endl;
	cout<<"capacity is "<<vbt.capacity()<<endl;

//	Vector<int> vec = vbt.getVector();
//	cout<<"capacity is "<<vec.getCapacity()<<endl;
//	for(int i=0; i<vec.size(); ++i){
//		cout<<*(vec.at(i))<<" ";
//	}
//	cout<<'\n';

//	for(auto p: vbt.positions() ){
////		if(p.isExternal()){}
//		try{
//		cout<<"At position "<<(*p)<< ", the value is"<<vec.at(*p)<<endl;
//		}catch(std::runtime_error& e){
//			cout<<e.what()<<endl;
//		}
////		cout<<vec.at(*p)<<' ';
//	}
	vbt.printVector();
	vbt.printTree();

}
