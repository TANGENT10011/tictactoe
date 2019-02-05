/*
 * class.cpp
 *
 *  Created on: Jan 26, 2019
 *      Author: Crimson
 */


// C++ program to demonstrate function
// declaration outside class
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
class Game
{
    public:
    string name;
    int id;
    string boardstate = "---------";

    // printname is not defined inside class defination
    void printname();

    // printid is defined inside class defination
    void printid()
    {
        cout << "Geek id is: " << id;
    }

    int IsValidInput(char num){
    	if (num>='1' && num <='9'){
    		return 1;
    	}
    	else{
    		return 0;
    	}

    }

    void placeX(char num){
    	int x = num;
    	boardstate[x-49] = 'X';
    //	cout << "\nboardstate is : " << boardstate;
    }
    void placeO(int x){
    	boardstate[x-49] = 'O';
    	//cout << "\nboardstate is : " << boardstate;
    }
    void drawboard(){
    	cout << "\n";
    	for (int i = 0 ; i < 8; i=i+3 ){

    		cout << boardstate[i]<<  boardstate[i+1] << boardstate[i+2];
    		cout << "\n";
    	}

    }

    void askforx(){
        	cout << "\n";
        	cout << "enter a number to place an X"<<"\n "<<   std::flush;
        }

    void askforo(){
        	cout << "\n";
        	cout << "enter a number to place an O"<<"\n"<<   std::flush;
        }

    int gamewon(){
    	char row1[] = {boardstate[0],boardstate[1],boardstate[2],0 };
    	char row2[] = {boardstate[3],boardstate[4],boardstate[5],0 };
    	char row3[] = {boardstate[6],boardstate[7],boardstate[8] ,0};

    	char col1[] = {boardstate[0],boardstate[3],boardstate[6],0 };
    	char col2[] = {boardstate[1],boardstate[4],boardstate[7],0 };
    	char col3[] = {boardstate[2],boardstate[5],boardstate[8],0 };

    	char diag1[] = {boardstate[0],boardstate[4],boardstate[8],0 };
    	char diag2[] = {boardstate[6],boardstate[4],boardstate[2],0 };
    	char testX[] = {'X','X','X',0};
    	char testO[] = {'O','O','O',0};



    	int xwins = strcmp(row1,testX)*strcmp(row2,testX)*strcmp(row3,testX)*strcmp(col1,testX)*strcmp(col2,testX)*strcmp(col3,testX)*strcmp(diag1,testX)*strcmp(diag2,testX);
    	int owins = strcmp(row1,testO)*strcmp(row2,testO)*strcmp(row3,testO)*strcmp(col1,testO)*strcmp(col2,testO)*strcmp(col3,testO)*strcmp(diag1,testO)*strcmp(diag2,testO);


    	if( xwins==0 || owins==0 ){
    		return 1;
    	}
    	else{
    		return 0;
    	}
    }

};

// Definition of printname using scope resolution operator ::
void Game::printname()
{
    cout << "Game name is: " << name;
}
int main() {

	char buffer[64];
	Game obj1;
    obj1.name = "xyz";
    obj1.id=15;


    obj1.printname();

    cout << "\nX goes first\n";

    cout << "\nenter a number between 1 and 9\n"<<   std::flush;

    while(1){


    	obj1.askforx();

    	fgets(buffer,5,stdin);

    	if (obj1.IsValidInput(buffer[0])){
    		obj1.placeX(buffer[0]);
    	}

    	obj1.drawboard();

    	if(obj1.gamewon()){

    		cout << "\ngame over\n";
    		return 1;
    	}

    	obj1.askforo();

    	fgets(buffer,5,stdin);

    	if (obj1.IsValidInput(buffer[0])){
    		obj1.placeO(buffer[0]);
    	}
    	obj1.drawboard();
    	if(obj1.gamewon()){

    		cout << "\ngame over\n";
    	    	return 1;
    	    }



    }

    return 0;


}




