#ifndef ISUBSCRIBER
#define ISUBSCRIBER

/*
 * Subscriber acts as observer. Publisher acts as subject.
 * */
#include <string>

class ISubscriber {

public:

	virtual void update(std::string) = 0;

	virtual ~ISubscriber() {}

private:

};


#endif
