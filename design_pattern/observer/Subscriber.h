#ifndef SUBSCRIBER
#define SUBSCRIBER

#include <string>

class Subscriber {

public:

	virtual void update(std::string) = 0;

	virtual ~Subscriber() {}

private:

};


#endif
