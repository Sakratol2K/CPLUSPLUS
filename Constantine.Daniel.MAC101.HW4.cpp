//Programmer: Daniel Constantine
//Contact: daniel.constantine@live.lagcc.cuny.edu
//Date: November 6, 2016
//Description: This program was my fourth assignment from my MAC101 class. 
//This program asks the user to input an integer where then the program would 
//find the prime factorization of that number using iteration method and not recursion

#include <iostream>
#include <cmath>
using namespace std;

//this function finds the prime factorization of 
//a number being inputted from the user.

void get_all_divisors(int );
int get_lowest_divisors(int);

int main(){
	int number;
	
	//prompt the user to input the desirable number
	cout << "Enter a number and press ENTER: ";
	cin >> number;
	
	//execute the function using the number from the user
	get_all_divisors(number);
	cout << endl;
	
	system("PAUSE");
	return 0;
}


//this function prints all of the divisors
void get_all_divisors(int number){
	
	//initialize variable firstDivisor by calling
	//get_lowest_divisors with the original number
	int firstDivisor = get_lowest_divisors(number); 
	
	//this loop is for getting the rest of the divisors
	//until the divisor is the number itself
	for(firstDivisor; firstDivisor < number; ){
		cout << firstDivisor << ", ";
		number = number / firstDivisor; //assign the new value to the variable number
		
		//assign a new value to the firstDivisor variable
		//by calling the get_lowest_divisors function using new number value
		firstDivisor = get_lowest_divisors(number); 
	}
	
	cout << firstDivisor;
}

int get_lowest_divisors(int number){
	double sqrt_of_n = sqrt(number);
	
	//check if the number is able to be divided evenly
	for(int i = 2; i <= sqrt_of_n; i++){
		if(number % i == 0)
			return i; //return i to the function
	}
	
	//if the number can't be divided then
	//return the number as it is the last divisor
	return number; 
}
