/*
 * Paper_Rock_Scissors_v2.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: jiado
 */




#include <thread>
#include <iostream>
#include <string>
#include <future>

#include "Paper_Rock_Scissors_v2.h"

enum Choice{PAPER, ROCK,SCISSORS};

std::string inputMap[3] {"paper", "rock", "scissors"};

Choice playerChoice(){

//	std::cout<<"********************Start to Play************************"<<std::endl;
	std::cout<<"Press 1 for Paper, 2 for Rock, 3 for Scissors:"<<std::endl;

	int choice;//=1;
	std::cin>> choice;

	while(choice<1 || choice>3){
		//				throw std::runtime_error("Selection out of range");
		std::cout<<"Sorry, I don't understand.\nPlease press 1 for Paper, 2 for Rock, 3 for Scissors: \n\n"<<std::endl;
		std::cin>> choice;
	}

	Choice pc;
	if(choice==1){
		pc = PAPER;
	}else if(choice==2){
		pc = ROCK;
	}else if(choice==3){
		pc = SCISSORS;
	}
	return pc;
}

Choice computerChoice(){
	srand(unsigned(std::time(0)));
	return static_cast<Choice>(rand() % 3);

}

void arbitration(Choice pc, Choice cc){

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


int test_paper_rock_scissors2(){

	int num=5000;
	while(num--){
		auto handle = std::async(playerChoice);
		auto handle2= std::async(computerChoice);

		try{
			auto pc = handle.get();
			auto cc = handle2.get();
			arbitration(pc, cc);
		}
		catch(std::exception& e){
			std::cout<<"exception: "<<e.what() <<'\n';
		}

		/* Alternative: using packaged_task and run in thread*/
//		using PTT = Choice(void);
//
//		auto pcObj = [](){return playerChoice();};
//		auto ccObj = [](){return computerChoice();};
//
//		std::packaged_task<PTT> tpc{pcObj};
//		std::packaged_task<PTT> tcc{ccObj};
//		std::future<Choice> tpcr = tpc.get_future();
//		std::future<Choice> tccr = tcc.get_future();
//
//		std::thread taskpc{std::move(tpc)};
//		std::thread taskcc{std::move(tcc)};
//		taskpc.join();
//		taskcc.join();
//
//		Choice pc = tpcr.get();
//		Choice cc = tccr.get();


	}
	return 0;
}
