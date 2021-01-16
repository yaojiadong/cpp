/*
 * Tic-Tac-Toe.h
 *
 *  Created on: Jan 16, 2021
 *      Author: jiado
 */

#ifndef TIC_TAC_TOE_TIC_TAC_TOE_H_
#define TIC_TAC_TOE_TIC_TAC_TOE_H_

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int test();


class Canvas{

    public:
        Canvas(){

            print();
        }

        bool draw(int& row, int& column, const string& symbol){

            if(occupied_canvas.size() == 9)
                return false;

            //check if occupied, enter new position
            while(isOccupied(row, column)){
                cout << "Position occupied. Please choose another position." << endl;
                cin >> row >> column;
            }

            // not occupied, draw it and store the pair
            // int myRow = convertRow(row);
            int myColumn = convertColumn(column);


            if(row == 1){
                s1.replace(s1.begin()+myColumn,s1.begin()+myColumn+1, symbol);
            }else if(row == 2){
                s3.replace(s3.begin()+myColumn,s3.begin()+myColumn+1, symbol);
            }else{ // myRow ==3
                s5.replace(s5.begin()+myColumn,s5.begin()+myColumn+1, symbol);
            }

            print();

            return true;

        }

        // int convertRow(int row){
        //     return pow(row,2)-pow(row-1,2);
        // }

        //change the user input column to actual row of the canvas
        int convertColumn(int column){
            return 4*column-3;
        }

        bool isOccupied(int row, int column){

            int p =row*10+column;;

            auto it = occupied_canvas.find(p);
            if(it != occupied_canvas.end()){ //  found pair, occupied
                return true;
            }else{
                occupied_canvas.insert(p);
                return false;
            }

        }

        void print(){
            cout << '\n' << endl;
            cout << s1 << endl;
            cout << s2 << endl;
            cout << s3 << endl;
            cout << s4 << endl;
            cout << s5 << endl;
        }


        set<int> getOccupiedCanvas(){
            return occupied_canvas;
        }

        bool isFull(){
        	if(occupied_canvas.size() == 9)
        		return true;
        	else
        		return false;
        }

    private:
        set<int> occupied_canvas;
        string s1 = "   |   |   ";
        string s2 = "---+---+---";
        string s3 = "   |   |   ";
        string s4 = "---+---+---";
        string s5 = "   |   |   ";

};

class Player{

    public:

        //constructor
        Player(string str): mark{str}{}
//		Player(string str){
//			mark = str;
//		}

        bool add(Canvas& canvas){
            int row, column;
            cout << "Please specify the row and column for your next step:" << endl;
            cin >> row >> column;

            while(row<0 || row>3 || column<0 || column>3){
                cout << "Invalid. Please choose a position between 1 and 3." << endl;
                cin >> row >> column;
            }
            if( canvas.draw(row, column, mark) ){
                wonPattern[row][column] = 1;
                return true;
            }else
                return false;

        }

        bool isWon(){
        	// check horizontal and vertical

            for(int i=1; i<4; ++i){
            	//set flag
            	int flag_h =1, flag_v=1;

                for(int j=1; j<4; ++j){
                    flag_h &= wonPattern[i][j];
                    flag_v &= wonPattern[j][i];

                    if(flag_h ==0 && flag_v ==0){
                        break;
                    }
                }

                if (flag_h ==1 || flag_v ==1)
                    return true;
            }
            //check diagonal
            if((wonPattern[1][1] & wonPattern[2][2] & wonPattern[3][3]) ||
               (wonPattern[1][3] & wonPattern[2][2] & wonPattern[3][1])){
                return true;
            }
            return false;
        }

    private:
        string mark;
        int wonPattern[4][4] = {0};
};





#endif /* TIC_TAC_TOE_TIC_TAC_TOE_H_ */
