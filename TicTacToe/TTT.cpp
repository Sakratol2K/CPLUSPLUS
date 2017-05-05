//This is the class function's definition
//from the TTT class.

#include "TTT.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

//default constructor
TTT::TTT(){
    //ctor
}

//asks user what type of game he/she wants to play
int TTT::askUser(){
    int x;
    cout << "Do you want to play: " << endl;
    cout << "(1) Human vs Human." << endl;
    cout << "(2) Human vs Computer."  << endl; //haven't figured this part for really smart AI
    cout << "(3) Computer vs Computer." << endl;
    cin >> x;
    return x;
}

//executes human vs human game
void TTT::HumanVSHuman(){
    count = 0;
    player = whoGoesFirst(); //asks user who wants to go first

    //keeps playing until we find the winner
    //or until the board is full
    while(!isWinner()){
        display();
        cout << "\nUser " << player << " turns: ";
        userChoice = getTurn(); //ask user for his move

        Go(userChoice, player);

        player = switchTurn(player); //change the player turns
        count++;

        if(isFull(count))
            break;
    }

    display();
    cout << "\nThe game ends" << endl;

    if(isWinner()){
        player = switchTurn(player);
        cout << "User " << player << " wins! CONGRATULATIONS";
    } else {
        cout << "It is a draw. Better luck next time! ";
    }
}

//executes machine vs machine game
void TTT::MachineVSMachine(){
    count = 0;
    cout << endl << "Enjoy the match! " << endl;
    player = 'X';
    int computerMove; //saves computer move
    while(!isWinner()){
        cout << "\nComputer " << player << " turns.";
        computerMove = randomPlay();
        Go(computerMove,player);
        player = switchTurn(player); //change the characters turns

        display();
        count++;
        if(isFull(count))
            break;
    }

    cout << "\nThe game ends" << endl;
    if(isWinner()){
        player = switchTurn(player);
        cout << "Computer " << player << " wins! CONGRATULATIONS";
    } else {
        cout << "It is a draw. Dang it, stupid computer! ";
    }
}

//executes human vs machine game
void TTT::HumanVSMachine(){
	cout << endl << "So, you're up to the challenge, huh? Thinking you can beat my amazing machine mind?";
            cout << "Well, let's see what you got!" << endl;
            cout << "Do you want to go first or second? [ENTER 1 or 2]: ";
            cin >> userChoice;

            if(userChoice == 1){
                HuVSMaHumanFirst();
            }
            else if(userChoice == 2){
                HuVSMaMachineFirst();
            }
}

//executes human vs machine first, human plays first
void TTT::HuVSMaHumanFirst(){
	player = 'X';
	count = 0;
    cout << endl << "You are player X" << endl;
    display();
    while(!isWinner()){
        cout << endl << "Please make your move" << endl;
        userChoice = getTurn();
        Go(userChoice, player);
        display();
        count++;

        if(isWinner()){
            break;
        }
        if(isFull(count)) //should check if the board is full
            break;

        player = switchTurn(player);
        cout << endl << "Now it's computer turn:" << endl;
        int temp = 0;
        while(true){
            temp = rand() % 9 + 1;
            if(isFree(temp))
                    break;
        }
        Go(temp,player);
        display();
        if(isWinner()){
            break;
        }

        player = switchTurn(player);
        count++;

        if(isFull(count)) //should check if the board is full
            break;
        }
    cout << "\nThe game ends" << endl;
    if(isWinner()){
        cout << "User " << player << " wins! CONGRATULATIONS";
    } else {
        cout << "It is a draw. Better luck next time! ";
    }
}

//executes human vs machine first, machine plays first
void TTT::HuVSMaMachineFirst(){
    player = 'X';
    count = 0;
    cout << endl << "Computer is player X" << endl;
    display();

    while(!isWinner()){
        cout << endl << "Computer's' turn:" << endl;
        int temp = 0;
        while(true){
            temp = rand() % 9 + 1;
            if(isFree(temp))
                break;
        }
        cout << "Computer choose " << temp << endl;
        Go(temp,player);
        display();
        count++;
        if(isWinner()){
            break;
        }
        if(isFull(count)) //should check if the board is full
            break;

        player = switchTurn(player);

        cout << endl << "Please make your move" << endl;
        userChoice = getTurn();
        Go(userChoice, player);
        display();

        if(isWinner()){
            break;
        }

        player = switchTurn(player);
        count++;

        if(isFull(count)) //should check if the board is full
            break;
    }

    cout << "\nThe game ends" << endl;

    if(isWinner()){
        cout << "User " << player << " wins! CONGRATULATIONS";
    } else {
        cout << "It is a draw. Better luck next time! ";
    }
}

//starts the game
void TTT::startGame(){
    do {
        reset(); //reset the board
        showRules(); //display the rules to the user
        userChoice = askUser(); //asks user what type of game he/she wants to play

		//human vs human
        if(userChoice == 1){
            HumanVSHuman();
        }

       	//human vs computer code
	    else if(userChoice == 2){
           	HumanVSMachine();
            }

        //computer vs computer
		else if(userChoice == 3){
            MachineVSMachine();
        }

        //in case user input another number
        else {
            cout << endl << "!You input the wrong number!";
        }

        stopGame = exitGame();
        cout << endl << "\t\t\t------------------------------------------" << endl;
    } while(stopGame != 'E');
}

//produce random number for computer turn
int TTT::randomPlay(){
    int temp;
    while(true){
        temp = rand() % 9 + 1;
        if(isFree(temp))
            break;
    }
    return temp;
}

//return true if the specific board is empty
bool TTT::isFree(int x){
    if(boardGame[x-1] != 'X' && boardGame[x-1] != 'O'){
        return true;
	}
    return false;
}

//asks user for their choice
int TTT::getTurn(){
    int number;
    cout << "Which number you want to put : ";
    cin >> number;
    return number;
}

//displays the board
void TTT::display(){
    cout << endl;
    cout << "       " << boardGame[0] << "  |  " << boardGame[1] << "  |  " << boardGame[2] << endl;
    cout << "     -----+-----+-----"  << endl;
    cout << "       " << boardGame[3] << "  |  " << boardGame[4] << "  |  " << boardGame[5] << endl;
    cout << "     -----+-----+-----"  << endl;
    cout << "       " << boardGame[6] << "  |  " << boardGame[7] << "  |  " << boardGame[8] << endl;
    cout << "     -----+-----+-----"  << endl;
    return;
}

//displays the rules
void TTT::showRules(){
    cout << "\t\t\t";
    cout << "Welcome to Constantine's Tic-Tac-Toe game." << endl;
    cout << "Rules: " << endl;
    cout << "(1) The object of Tic Tac Toe is to get three in a row." << endl;
    cout << "(2) You play on a three by three game board." << endl;
    cout << "(3) The first player is known as X and the second is O." << endl;
    cout << "(4) Players alternate placing X and O on the game board." << endl;
    cout << "(6) Whoever gets three in a row first wins the game." << endl;
    cout << "(5) If all nine squares are filled and no one has three in a row, it is a draw.";
    cout << endl << endl;
    return;
}

//eventually checks every movement both players made and returns true if the board is full
bool TTT::isFull(int count){
    if(count == 9)
        return true;
    return false;
}

//asks the user who wants to go first
char TTT::whoGoesFirst(){
	char goFirst;
    cout << "Who wants to go first? (X / O): ";
    cin >> goFirst;
    goFirst = toupper(goFirst);
    return goFirst;
}

//checks if there is a winner, if there is, returns true
bool TTT::isWinner(){
	//these codes check for a winner based on the first column
	if((boardGame[0] == boardGame[1]) && ((boardGame[0]) == (boardGame[2])))
		return true;
	else if( (boardGame[0] == boardGame[4]) && (boardGame[0]) == (boardGame[8]) )
		return true;
	else if( (boardGame[0]) == (boardGame[3]) && (boardGame[0]) == (boardGame[6]) )
		return true;
	//this code check for a winner based on the second column
	else if( (boardGame[1]) == (boardGame[4]) && (boardGame[1]) == (boardGame[7]))
		return true;
	//these code check for a winner based on the third column
	else if( (boardGame[2]) == (boardGame[5]) && (boardGame[2]) == (boardGame[8]) )
		return true;
	else if( (boardGame[2]) == (boardGame[4]) && (boardGame[2]) == (boardGame[6]) )
		return true;
	//this code check for a winner based on the second row
	else if( (boardGame[3]) == (boardGame[4]) && (boardGame[3]) == (boardGame[5]) )
		return true;
	//this code check for a winner based on the third row
	else if( (boardGame[6]) == (boardGame[7]) && (boardGame[6]) == (boardGame[8]) )
		return true;
	else
		return false;
}

//automatically switches player's turns
char TTT::switchTurn(char player){
	if(player == 'X')
		return 'O';
	else
		return 'X';
}

//takes user choice and changes the board based on player's symbol
void TTT::Go(int userChoice, char player){
    boardGame[userChoice-1] = player;
    return;
}

//clears the board
void TTT::reset(){
    boardGame[0] = '1';
    boardGame[1] = '2';
    boardGame[2] = '3';
    boardGame[3] = '4';
    boardGame[4] = '5';
    boardGame[5] = '6';
    boardGame[6] = '7';
    boardGame[7] = '8';
    boardGame[8] = '9';
    return;
}

//asks user if he/she wants to end the game
char TTT::exitGame(){
    char x;
    cout << endl << endl;
    cout << "Do you want to play again? Press E to exit the program: ";
    cin >> x;
    x = toupper(x);
    return x;
}
