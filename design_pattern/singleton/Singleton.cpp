// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "Singleton.h"

constexpr int LOOPS = 10;

int test_singleton()
{

	//std::cout << Singleton::getinstance().getstring();
	//Singleton::getinstance().setstring("hello world!\n");
	//std::cout << Singleton::getinstance().getstring();

	std::thread t2([]() {
		int loop = LOOPS;
		while (loop--) {
			Singleton::getInstance().setString("Hello World from t2!\n");
			std::cout << Singleton::getInstance().getString();
		}}
		);
	

	std::thread t1([]() {
		int loop = LOOPS;
		while (loop--) {
			Singleton::getInstance().setString("Hello World from t1!\n");
			std::cout << Singleton::getInstance().getString();
		}}
	);

	t1.join();
	t2.join();

	return 0;
}
