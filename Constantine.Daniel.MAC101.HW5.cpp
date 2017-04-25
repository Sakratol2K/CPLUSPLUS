//Programmer: Daniel Constantine
//Contact: daniel.constantine@live.lagcc.cuny.edu
//Date: November 13, 2016
//Description: This program was my fifth assignment from my MAC101 class. 
//This program lets the user draw objects with two shapes (ball and cube)
//each with four different colors (red, blue, orange, green) endlessly.

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int rand_0toN1(int n);
void draw_an_object(); 
int select_next_available(int n);
bool card_drawn[8];
int items_remaining = 8; 
char *shape[2] = {"ball", "cube"}; //initalize the shape of the objects
char *color[4] = {"red","blue","orange","green"}; //initalize the colors of the objects

int main() {
	
    int n, i;
    srand(time(NULL));   //set seed for randomizing.
    
    while (1) {
        cout << "Enter no. of objects to draw (0 to exit): "; //prompt user to pick how many objects they want
        cin >> n;
		 
        if (n == 0)
            break;
        for (i = 1; i <= n; i++)
            draw_an_object();
    }
    return 0;
}

// Draw-an-object function
// Perform an object draw by getting a random 0-1 and a random 0-3.
// Use these to index the strings arrays, shape and colors.

void draw_an_object() {
    int r;      // Random index (0 thru 1) into 
                //  shape array 
    int s;      // Random index (0 thru 3) into 
                //  color array 
    int n, card; 	
    	
    // Just in case no items left,
	// putting all the items back in again
   	if(items_remaining == 0){ 
    	cout << endl << "We run out of items." << endl;
		cout << "Replacing all items in the bag." << endl;
		for(int i = 0; i<= 8; i++)
			card_drawn[i] = 0;
		items_remaining = 8;
		cout << "Continuing picking up items: " << endl;
	}  	
	
    n = rand_0toN1(items_remaining--);
    card = select_next_available(n);
    r = card % 2;            // r = random 0 to 1
    s = card / 2;            // s = random 0 to 3
    cout << shape[r] << " of " << color[s] << endl;
}

// Select-next-available-card function.
// Find the Nth element of card_drawn, skipping over
//  those elements already set to true.

int select_next_available(int n) {
    int i = 0;
    // At beginning of deck, skip objects already drawn.
    while (card_drawn[i])
        i++;
    while (n-- > 0) {     // Do the following n times:
        i++;                  // Advance to next objects
        while (card_drawn[i]) // Skip past objects
        	i++;
    }

    card_drawn[i] = true;
    return i;
}

int rand_0toN1(int n) {
    return rand() % n;
}

