//Programmer: Daniel Constantine
//Contact: daniel.constantine@live.lagcc.cuny.edu
//Date: October 30, 2016
//Description: This program was my third assignment from my MAC101 class. 
//This program asks the user to input a character and an integer where the program would create
//a diamond shape based on that character and the size is depend on the integer the user just inputted

#include <iostream>
using namespace std;

// This function produces diamond based on the integer and character inputted by the user.
// It has default value 5 for the side and * for the character
void diamond(int sideOfDiamond = 5, char characterPrint = '*' );

int main(){
	
	char confirm;
	int sideOfDiamond;
	char characterPrint;
	
	// Prompt the user to use default values or not
	cout << "Do you want to use the default values? (Y/N?): ";
	cin >> confirm;
	
	// If the user inputs 'Y' or 'y' then the function is being executed with default value
	if( confirm == 'Y' || confirm == 'y' ){
		diamond();
	}	
	
	// If the user inputs 'N' or 'n' then proceed to the next prompt
	else if( confirm == 'N' || confirm == 'n' ){
			
			// Prompt the user to input an integer for how many side the user wants for the diamond
			cout << "Enter an integer for the side of the diamond: ";
			cin >> sideOfDiamond;
			
			// Prompt the user to input a character they want to use for the diamond
			cout << "Enter a char value for the character printed: ";
			cin >> characterPrint;	
		
		// Executes the function with side and character specifically get from the user
		diamond(sideOfDiamond, characterPrint);
	}
	
	system("PAUSE");
	return 0;
}


void diamond(int sideOfDiamond, char characterPrint){
	int row, space, character;
	
	// This loop produces the top of the diamond
	for(row = 1; row <= sideOfDiamond; row++){
		for(int space=row; space <= sideOfDiamond; space++) //This loop prints the space
			cout << " "; 
		for(int character=1; character <= 2*row-1; character++){ //This loop prints the character
			cout << characterPrint;
		}
		cout << endl;		
	}
	
	// This loop produces the bottom of the diamond
	for(row = sideOfDiamond-1; row >= 0; row--){
		for(int space=row; space <= sideOfDiamond; space++) //This loop prinst the space
			cout << " ";
		for(int character=1; character <= 2*row-1; character++){ //This loop prints the character
			cout << characterPrint; 
		}
		cout << endl;		
	}
	
	return;
}
