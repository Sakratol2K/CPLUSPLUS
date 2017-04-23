//Programmer: Daniel Constantine
//Contact: daniel.constantine@live.lagcc.cuny.edu
//Date: January 22, 2017
//Description: This program is from Programming Projects in Savitch's Absolute C++ book: Chapter 1 number 3.
//This program takes an employee’s previous annual salary as input and outputs the amount of retroactive pay due the employee,
//the new annual salary, and the new monthly salary.

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

	const double rates = 0.076;
	double previousSalary;
	double monthlySalary;
	double annualSalary;
	double retroactiveSalary;
	double increasedSalary;

	cout << "Input your previous salary: ";
	cin >> previousSalary;

	//calculate the retroactive salary by multiplying your previous salary with the rates
	retroactiveSalary = previousSalary * rates;
	cout << "Your retroactive salary is: " << retroactiveSalary << endl;

    //calculate the annual salary by adding your previous salary with your retroactive salary
	annualSalary = previousSalary + retroactiveSalary;
	cout << "Your annual salary is: " << annualSalary << endl;

	//calculate the increasing in your salary each month by multiplying your previous salary with the rates (0.076) and divided it by 6.
	increasedSalary = previousSalary * rates / 6;
	cout << "Your increased salary each month: " << increasedSalary << endl;

    //calculate your monthly salary by adding your previous salary with your increasing salary each month
	monthlySalary = previousSalary + increasedSalary;
	cout << "Your salary per month: " << monthlySalary;

	return 0;
}
