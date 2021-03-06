/*
 * Paper_Rock_Scissors.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: jiado
 */


#include <thread>
#include <iostream>
#include <condition_variable>
#include <string>
#include <mutex>
#include <stdexcept>

#include "Test_paper_rock_scissors_v1.h"

constexpr int RUN=5000;

class Paper_rock_scissors{

public:
	enum Choice{PAPER, ROCK,SCISSORS};

private:
	Choice cc = PAPER;
	Choice pc = PAPER;
	std::string inputMap[3] {"paper", "rock", "scissors"};
	bool userReady = false;
	std::condition_variable cond;
	std::mutex mLock;


public:
	void playerChoice(){

		std::cout<<"********************Start to Play************************"<<std::endl;
		std::cout<<"Press 1 for Paper, 2 for Rock, 3 for Scissors:"<<std::endl;

		int run_num = RUN;
		while(run_num--){

			std::unique_lock<std::mutex> lckStart(mLock);
			cond.wait(lckStart,[this]{return (!userReady);});
			lckStart.unlock();

			int choice;
			std::cin>> choice;

			while(choice<1 || choice>3){
//				throw std::runtime_error("Selection out of range");
				std::cout<<"Sorry, I don't understand.\nPlease press 1 for Paper, 2 for Rock, 3 for Scissors: \n\n"<<std::endl;
				std::cin>> choice;
			}

			if(choice==1){
				pc = PAPER;
			}else if(choice==2){
				pc = ROCK;
			}else if(choice==3){
				pc = SCISSORS;
			}

			std::lock_guard<std::mutex> lg(mLock);
			userReady = true;
			cond.notify_one();
		}

	}

	void computerChoice(){

		int run_num =  RUN;
		while(run_num--){

			cc = static_cast<Choice>(rand() % 3);

			std::unique_lock<std::mutex> lck{mLock};
			cond.wait(lck,[this]{return userReady;});
			try{
				arbitration();
			}catch(std::runtime_error& e){
				std::cout <<e.what()<<std::endl<< std::flush;
			}
			userReady = false;
			cond.notify_one();
		}
	}

	void arbitration(){

		std::cout<<"You chose "<< inputMap[pc]<< ". Computer chose "<<inputMap[cc]<<". ";

		if (pc == cc) {
			std::cout<<"Draw."<<std::endl;
		} else if (pc == Choice::ROCK && cc == Choice::PAPER) {
			std::cout<<"Computer wins."<<std::endl;
		} else if (pc == Choice::ROCK && cc == Choice::SCISSORS) {
			std::cout<<"You win."<<std::endl;
		} else if (pc == Choice::PAPER && cc == Choice::ROCK){
			std::cout<<"You win."<<std::endl;
		} else if (pc == Choice::PAPER && cc == Choice::SCISSORS){
			std::cout<<"Computer wins."<<std::endl;
		} else if (pc == Choice::SCISSORS && cc == Choice::ROCK){
			std::cout<<"Computer wins."<<std::endl;
		} else if (pc == Choice::SCISSORS && cc == Choice::PAPER) {
			std::cout<<"You win."<<std::endl;
		}else{
			throw std::runtime_error("Not possible to arbitrate.");
		}

		std::cout<<"\n\n";
	}

};


int test_paper_rock_scissors_v1(){

	Paper_rock_scissors prc;

	std::thread player{[&]{prc.playerChoice();}};
	std::thread computer{[&]{prc.computerChoice();}};

	player.join();
	computer.join();

	return 0;

}
