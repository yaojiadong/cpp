#ifndef PUBLISHER
#define PUBLISHER

#include <memory>
#include <list>
#include "Subscriber.h"

class Publisher {
public:

	//default ctor and detor

	void subscribe(Subscriber* sub) {
		vec.push_back(sub);
	}

	void unsubscribe(Subscriber* sub) {
		vec.remove(sub);
	}

	/*Using smart pointer*/
//	void subscribe(std::shared_ptr<Subscriber> sub) {
//		vec.push_back(sub);
//	}
//
//	void unsubscribe(std::shared_ptr<Subscriber> sub) {
//		vec.remove(sub);
//	}

	void notifySubscribers() {
//		for (auto s : vec) {
		for(auto it=vec.begin(); it!=vec.end(); ++it){
			(*it)->update(msg);
		}
	}

	void onClick() {
		this->msg = "Clicked";
		notifySubscribers();
	}

private:
	std::list<Subscriber*> vec;
//	std::list<std::shared_ptr<Subscriber>> vec;
	std::string msg;
};


#endif
