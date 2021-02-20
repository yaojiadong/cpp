/*
 * exception.hpp
 *
 *  Created on: Feb 17, 2021
 *      Author: jiado
 */

#ifndef DATA_STRUCTURE_EXCEPTION_HPP_
#define DATA_STRUCTURE_EXCEPTION_HPP_

#include<string>
#include<stdexcept>

class StackFull:public std::runtime_error{
public:
	StackFull(const std::string& s):std::runtime_error(s){}
};

class StackEmpty:public std::runtime_error{
public:
	StackEmpty(const std::string& s):std::runtime_error(s){}
};

class DequeEmpty:public std::runtime_error{
public:
	DequeEmpty(const std::string& s):std::runtime_error(s){}
};

class QueueEmpty:public std::runtime_error{
public:
	QueueEmpty(const std::string& s):std::runtime_error(s){}
};

#endif /* DATA_STRUCTURE_EXCEPTION_HPP_ */
