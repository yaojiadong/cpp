/*
 * main.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */

#include<array>
#include<vector>
#include<utility>
#include<memory>
#include<iostream>
#include<map>
#include<unordered_map>
#include<variant>
#include<iomanip>
#include<functional>


//#include "typeid/typeid.hpp"
//#include "template/templates.hpp"
//#include "template/template_alias.hpp"
//#include "ctor/default_ctor.hpp"
//#include "template/template_alias.hpp"
//#include "tic-tac-toe/Tic-Tac-Toe.h"
//#include "lambda/lambda.h"
//#include "rvalue/rvalue.h"
//#include "parameter_pack_auto/par_pack_auto.h"
//#include "structure_binding/structure_binding.h"
//#include "node_handle/node_handle.h"
//#include "pow/pow.h"
#include "data_structure/DLinkedList.hpp"
#include "data_structure/ArrayStack.hpp"
#include "data_structure/ListStack.hpp"
#include "data_structure/Deque.hpp"
#include "data_structure/IteratorDLinkedList.hpp"
#include "data_structure/Stack.hpp"
#include "tree/LinkedBinaryTree.hpp"
#include "tree/VBinaryTree.hpp"
#include "tree/VBT.hpp"
#include "tree/Vector.hpp"
using namespace std;

#if __cplusplus
#endif



int main(){

	//	test_typeid();
	//	test_typeid_poly();
	//	test_templates();
	//	test_template_alias();
	//	test_rvalue();
	//	test_lambda();
	//	test_par_pack_auto();
	//  test_structure_binding();
	//	test_node_handle();
	//	test_pow();

//	int elem = 5;
//	Stack<int, DLinkedList<int>> stack;
//	stack.push_back(elem);
//	cout<<stack.front();

//	Deque<int> deque;
//	deque.push_back(elem);
//	deque.push_back(elem+1);
//	auto it = deque.begin();
//	auto itt = deque.end();
//
//	cout<<*it<<" "<< *--itt;


//	try{
//		stack.pop_back();
//		stack.pop_front();
//	}catch(runtime_error& e){
//		cout<<e.what();
//	}

//	cout<<lst.back();


//	LinkedBinaryTree<int> bt;
//	bt.addRoot();
//	bt.expandExternal(bt.root());
//	cout<<bt.size();
//	for(auto p: bt.positions()){
//		cout<<*p<<' ';
//	}

//	Vector<int> vec;
//	vec.insert(0, 5);
//
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
//	vector<int> vec;
//	int* a = new int;
//	vec[0] = a;

//	std::array<double,10> arr{};
//	for(auto a: arr){
//		cout<<a<<" ";
//	}


	return 0;
}

