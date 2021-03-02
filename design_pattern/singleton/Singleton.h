#pragma once


#include <string>
class Singleton {

public:

	//delete copy ctor
	Singleton(Singleton&) = delete;

	//delete assignment ctor
	void operator= (const Singleton&) = delete;


	static Singleton& getInstance() {
		static Singleton singleton;
		return singleton;
	}

	void setString(const std::string s) {
		str = s;
	}

	std::string getString() {
		return str;
	}

private:
	//private ctor
	Singleton(const std::string s = "Hello\n") : str{s} {}

private:
//	static Singleton singleton;
	std::string str;

};
