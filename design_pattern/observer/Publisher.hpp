#ifndef PUBLISHER
#define PUBLISHER

/*
 * Subscriber acts as observer. Publisher acts as subject.
 * */

#include <memory>
#include <list>

#include "ISubscriber.hpp"

class Publisher {
public:

	//default ctor and detor

	void subscribe(ISubscriber* sub) {
		vec.push_back(sub);
	}

	void unsubscribe(ISubscriber* sub) {
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
		this->msg = "New message -- Click action";
		notifySubscribers();
	}

private:
	std::list<ISubscriber*> vec;
//	std::list<std::shared_ptr<Subscriber>> vec;
	std::string msg;
};


#endif
