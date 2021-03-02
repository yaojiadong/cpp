#ifndef CLIENT_HPP_
#define CLIENT_HPP_


#include <iostream>

#include "Publisher.hpp"
#include "Subscriber.hpp"


class Client{

public:
	void config(){
		Publisher pub;

		Subscriber* sub = new Subscriber{};
		Subscriber* sub2 = new Subscriber{};
		pub.subscribe(sub);
		pub.subscribe(sub2);

		/*Using smart pointer*/
	//	SubscriberA sa;
	//	SubscriberA sb;
	//	pub.subscribe(std::make_shared<SubscriberA>(sa));
	//	pub.subscribe(std::make_shared<SubscriberA>(sb));

		pub.onClick();

		std::cout<<"msg got in subscriber1: "<<sub->message()<<std::endl;
		std::cout<<"msg got in subscriber2: "<<sub2->message()<<std::endl;

		delete sub;
		delete sub2;
	}

};

#endif /* CLIENT_HPP_ */
