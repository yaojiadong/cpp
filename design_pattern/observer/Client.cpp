
#include <iostream>
#include "Publisher.h"
#include "Subscriber.h"
#include "SubscriberA.h"

void client() {
	Publisher pub;

	SubscriberA sa{pub};  //subscriber is subscribed as it is instantiated.
	SubscriberA sb{pub};

	/*Using smart pointer*/
//	SubscriberA sa;
//	SubscriberA sb;
//	pub.subscribe(std::make_shared<SubscriberA>(sa));
//	pub.subscribe(std::make_shared<SubscriberA>(sb));

	pub.onClick();

}

int test_observer()
{
	client();

    return 0;
}
