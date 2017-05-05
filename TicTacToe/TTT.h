//This is the class declaration for the program I use

#ifndef TTT_H
#define TTT_H

class TTT {
    public:
        TTT(); //default constructor
        void startGame(); //starts the game
        void reset(); //clears the board
        void showRules(); //displays the rules
        void display(); //display the board
        void Go(int x, char y); //takes an integer and changes the board based on player's symbol
        void HumanVSHuman(); //human vs human game
        void MachineVSMachine(); //machine vs machine game
        void HumanVSMachine(); //human vs machine game
        void HuVSMaHumanFirst(); //human vs machine game, human plays first
        void HuVSMaMachineFirst(); //human vs machine game, machine plays first
        char whoGoesFirst(); //asks the user who wants to go first
        char switchTurn(char ); //automatically switches player's turns
        char exitGame(); //asks user to exit the program
        int getTurn(); //asks user where do they want to put the next X / O
        int randomPlay(); //return random number for computer movement
        int askUser(); //asks user what kind of game he/she wants
        bool isWinner(); //returns true if there is a winner
        bool isFull(int x); //returns true if the board is full and false if there is a space
        bool isFree(int x); //returns true if the board is free

    protected:

    private:
        char boardGame[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //this is the board game
        char player; //keep detail on character being used X or O
        char stopGame; //variable to contain character if user wants to exit
        int userChoice = 0; //to keep track of what the user's input
        int count = 0; //to keep track of how many board left

};

#endif // TTT_H
