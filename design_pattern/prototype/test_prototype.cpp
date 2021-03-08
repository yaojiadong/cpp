/*
 * test_prototype.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

/*
 * Polymorphic clones, covariance
 * https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/
 * https://stackoverflow.com/questions/196733/how-can-i-use-covariant-return-types-with-smart-pointers
 * https://stackoverflow.com/questions/6924754/return-type-covariance-with-smart-pointers
 *
 * C++ allows overriding a virtual method with one that has a different return type, provided this return
 * type is a pointer (resp. reference) to a class convertible to the one pointed to (resp. referenced by)
 * the return type of the base class. This is called covariance.
 *
 * Aim: after clone, the new object should be able to access the members of the subclass.
 * With row pointer, covariance works.
 * With smart pointer, covariance does not work. The return type of Base and Derived methods must be the same.
 * The newly-cloned object does not have access to subclass members.
 * Because clone returns smart_ptr<Base>, which is not possible to convert to smart_ptr<Subclass>.
 *
 * Solution:
 * 1. keep using row pointer
 * 2. Use row pointer in Base, and smart pointers elsewhere. Define an extra -impl member function to facilitate
 * the use of covariance on raw pointers, and then wrap them. See solution2.cpp
 * 3. Use covariance on raw pointers, and then wrap them. See soluction3.cpp
 *
 * */

#include "test_prototype.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Client.h"


void test_prototype(){

	Circle circle{5};
	Circle* circle_clone = circle.clone();
	std::cout << "Circle radius is " << circle_clone->get_radius() << std::endl;
	delete circle_clone;

	Rectangle rectangle{1,10};
	Rectangle* rectangle_clone = rectangle.clone();
	std::cout << "Rectangle length is " << rectangle_clone->get_length() <<", width is " << rectangle_clone->get_width() << std::endl;
	delete rectangle_clone;

	Client client;
	client.add_prototype(Type::circle, &circle);
	client.add_prototype(Type::rectangle, &rectangle);
	std::unordered_map<Type,IShape*> prototypes = client.get_prototypes();
	for(auto & [type, shape] : prototypes){
		if(type == Type::circle){
			Circle* s = (Circle*)shape->clone();
			std::cout << "Circle radius is " << s->get_radius() << std::endl;
			delete s;
		}
	}

}

