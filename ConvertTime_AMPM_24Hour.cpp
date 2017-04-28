//Programmer: Daniel Constantine
//Contact: daniel.constantine@live.lagcc.cuny.edu
//Date: February 9, 2017
//Description: This program converts the time user enter from 24 hour clock to AM/PM or from AM/PM to 24 hour clock

#include <iostream>
using namespace std;

int askHour();
int askMinute();
string askAmPm();
int userChoice();
int exit();
void display(int, int);
void displayAmPm(int, int, string );
void conversion24Hour(int, int);
void conversionAMPM(int, int, string);


int main(){
	int hour, minute, exitValue, userNumber;
	string time;

    userNumber = userChoice();

    if(userNumber == 2){
        do{
            hour = askHour();
            minute = askMinute();
            display(hour, minute);
            conversion24Hour(hour, minute);
            exitValue = exit();

        } while(exitValue != 0);
    } else if (userNumber == 1) {
        do{
            hour = askHour();
            minute = askMinute();
            time = askAmPm();

            displayAmPm(hour, minute, time);
            conversionAMPM(hour, minute, time);
            exitValue = exit();

        } while(exitValue != 0);
    } else {
        cout << "Thank you for trying our program." << endl;
    }
return 0;
}

//asks the user about which mode they want to use
int userChoice(){
    int x;
    do{
        cout << "Enter which converter mode you want to use: " << endl;
        cout << "(1) AM/PM to 24 hour clock." << endl;
        cout << "(2) 24 hour clock to AM/PM." << endl;
        cout << "(0) to exit the program." << endl << endl;
        cin >> x;
        if(x > 2 || x < 0)
            cout << endl << "Sorry I do not understand. Please try input another number." << endl << endl;
    } while (x > 2 || x < 0);

    return x;
}

//convert the time from 24 hour clock to AM/PM
void conversion24Hour(int hour, int minute){
	if(hour > 24){
		cout << "Error";
		return;
	}
	if(hour > 12){
		hour -= 12;
		cout << "The conversion result in AM/PM clock: ";
		cout << hour << ":" << minute << " PM";
		return;
	}
	cout << "The conversion result in AM/PM clock: ";
	cout << hour << ":" << minute << " AM";
	return;
}

//convert the time from AM/PM to 24 hour
void conversionAMPM(int hour, int minute, string time){
    if(time == "PM" || time == "pm" || time == "Pm" || time == "pM"){
        hour += 12;
    }
    cout << "The conversion result in 24 hour clock: ";
	cout << hour << ":" << minute;
	return;
}

//ask the user to input the hour
int askHour(){
    int x;
    cout << endl << "Enter the hour: ";
    cin >> x;
    return x;
}

//ask the user to input the minute
int askMinute(){
    int x;
    cout << "Enter the minute: ";
    cin >> x;
    return x;
}

//ask the user to input AM/PM
string askAmPm(){
    string x;
    cout << "Enter AM / PM: ";
    cin >> x;
    return x;
}

//display the time to the user. 24 hour clock version
void display(int hour, int minute){
    cout << "The time you entered: " << hour << ":" << minute << endl;
}

//display the time to the user. AM/PM clock version
void displayAmPm(int hour, int minute, string AMPM){
    cout << "The time you entered: " << hour << ":" << minute << " " << AMPM << endl;
}

//returning exit value from the user. If the user enter 0, the program ends
int exit(){
    int x;
    cout << endl << endl << "Enter 0 exit: ";
    cin >> x;
    return x;
}
