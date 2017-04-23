//Programmer: Daniel Constantine
//Contact: daniel.constantine@live.lagcc.cuny.edu
//Date: September 29, 2016
//Description: This program was an assignment from my MAC101 class. 
//This program takes a value from the user and then calculate it in function 4x^3 + x^2 + 3x - 5

#include <iostream>
using namespace std;
int main(){
	int x = 0, result = 0;
	cout << "Let f(x) = 4x^3 + x^2 + 3x - 5" << endl;

	cout << "Enter a value for x: ";
	cin >> x;

	result = 4*(x*x*x) + (x*x) + 3*x - 5; //calculate the result of the function based on number being inputted
	cout << "f(" << x << ") = " << result;

	return 0;
}
