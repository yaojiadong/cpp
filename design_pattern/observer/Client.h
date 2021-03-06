#ifndef CLIENT_HPP_
#define CLIENT_HPP_


#include <iostream>

#include "Publisher.hpp"
#include "Subscriber.hpp"


class Client{

public:
	void config(){
		Publisher pub;

//		Subscriber* sub = new Subscriber{};
//		Subscriber* sub2 = new Subscriber{};
//		pub.subscribe(sub);
//		pub.subscribe(sub2);

		/*Using smart pointer*/
//		Subscriber sub;
//		Subscriber sub2;
//		pub.subscribe(std::make_shared<Subscriber>(sub));
//		pub.subscribe(std::make_shared<Subscriber>(sub2));

		/*
		 * Error: requesting an implicit conversion from Subscriber* to std::shared_ptr:
		 * Since the std::shared_ptr constructor is explicit, the conversion isn't possible.
		 * Pass the Subscriber* explicitly to the std::shared_ptr constructor
		 * */
		//std::shared_ptr<Subscriber> sub = new Subscriber;

		std::shared_ptr<Subscriber> sub{new Subscriber};
		std::shared_ptr<Subscriber> sub2{new Subscriber};
		pub.subscribe(sub);
		pub.subscribe(sub2);

		pub.onClick();

		std::cout<<"msg got in subscriber1: "<<sub->message()<<std::endl;
		std::cout<<"msg got in subscriber2: "<<sub2->message()<<std::endl;

		//delete needed when handling row pointers.
//		delete sub;
//		delete sub2;
	}

};

#endif /* CLIENT_HPP_ */
