
#ifndef SUBSCRIBER
#define SUBSCRIBER

#include "ISubscriber.h"
#include "Publisher.hpp"

class Subscriber : public ISubscriber {

public:

	//subscriber is subscribed as it is instantiated.
//	Subscriber(Publisher& p): pub{p}{
//		pub.subscribe(this);
//	}


//	void removeSubscription() {
//		pub.unsubscribe(this);
//	}

	void update(std::string msg) override {
		this->msg = msg;
	}

	std::string message(){
		return msg;
	}
private:
//	Publisher& pub;
	std::string msg;
};

#endif
