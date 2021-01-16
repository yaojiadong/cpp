#include<iostream>
#include"Tic-Tac-Toe.h"

using namespace std;



int test(){
    Canvas canvas;
    Player p1{"X"}, p2{"O"};
    
//    int row, column;
//    cout << "Please specify the row and column for your next step:" << endl;
//    cin >> row >> column;
    bool b;
    do{
        b = p1.add(canvas);
        if(p1.isWon()){
            cout<< "End game, player1 won." <<endl;
            break;
        }
        if(canvas.isFull() ){
            cout<< "End game, Draw!." <<endl;
            break;
        }
            
            
        b &= p2.add(canvas);
        if(p2.isWon()){
            cout<< "End game, player2 won." <<endl;
            break;
        }
        if(canvas.isFull()){
            cout<< "End game, Draw!." <<endl;
            break;
        }
    }while(b);
    
    return 0;
    
}
