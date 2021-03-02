
#ifndef SUBSCRIBERA
#define SUBSCRIBERA

#include "Publisher.h"
#include "Subscriber.h"


class SubscriberA : public Subscriber {

public:
	//ctor
	/* When using smart pointer, keyword this cannot be converted to a smart pointer
	 * The solution is to leave the constructor default and subscribe in client
	 * */
	SubscriberA(Publisher& p): pub{p}{
		pub.subscribe(this);
	}


	~SubscriberA(){}

	void removeSubscription() {
//		pub.unsubscribe(this);
	}

	void update(std::string msg) override {
		this->msg = msg;
		std::cout<< msg << std::endl;
	}

private:
	Publisher& pub;
	std::string msg;
};

#endif
