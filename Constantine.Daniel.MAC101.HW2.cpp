//Programmer: Daniel Constantine
//Contact: daniel.constantine@live.lagcc.cuny.edu
//Date: October 11, 2016
//Description: This program was my second assignment from my MAC101 class. 
//This program prints hexagon shape using asterisks '*' and blank space ' '

#include <iostream>
using namespace std;

int main(){
	int row, space, asterisk;
	for(row = 1; row <= 4; row++){
		for(space = row; space <= 3; space++) //output space
			cout << " ";
		for(asterisk = 1; asterisk <= 2*row+5; asterisk++) //output asterisk
			cout << "*";
	cout << "\n";
	}
	for(row = 3; row >= 1; row--){
		for(space = 3; space >= row; space--) //output space
			cout << " ";
		for(asterisk = 1; asterisk <= 2*row+5; asterisk++) //output asterisk
			cout << "*";
	cout << "\n";
	}
	system("PAUSE");
	return 0;
}
