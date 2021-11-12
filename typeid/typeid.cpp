/*
 * typeid.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: jiadong
 */




#include"typeid.h"
#include<typeindex>

//using namespace std;


void f(Component s){
	cout<< typeid(s).name()<<endl;
}

void g(string s){
	cout<< typeid(s).name()<<endl;
}




void test_typeid(){
Component com;
string s ="abc";
Ran ran, ran2;
f(com);
g(s);

cout<< typeid(ran).name()<<endl;
cout<< typeid(ran2).name()<<endl
		;
bool a = typeid(com).before(typeid(ran));
bool b = typeid(ran2).before(typeid(ran));

size_t sz = typeid(ran).hash_code();
size_t sz2 = typeid(ran2).hash_code();

cout<< a << "\n"<<b<<endl;
cout<<sz<<endl;
cout<<sz2<<endl;



const type_info& typeinfo = typeid(ran);
const type_info& typeinfo2 = typeid(ran2);
type_index typeIndex = type_index{typeinfo};
type_index typeIndex2 = type_index{typeinfo2};

if(typeIndex == typeIndex2)
	cout<<"equal"<<endl;
cout<< typeIndex.name()<<endl;
cout<< typeIndex2.name()<<endl;
}

struct Poly{
	virtual void f(){}

	virtual~Poly(){}
};

struct Non_poly{

};

struct D1:Poly{

};
struct D2:Non_poly{

};

void f(Non_poly& npr, Poly& pr){
	cout<<typeid(npr).name()<<endl;
	cout<<typeid(pr).name()<<endl;
}

void test_typeid_poly(){
	D1 d1;
	D2 d2;
	f(d2,d1);
	try{
		f(*static_cast<Non_poly*>(nullptr), *static_cast<Poly*>(nullptr));
	}catch (std::bad_typeid&){
		cout<<"bad typeid"<<endl;
	}
}

