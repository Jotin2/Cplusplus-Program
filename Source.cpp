/*
Joshua Asari
CS 210
Project One - Clock
7/18/21
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
using namespace std;

/*
Creates a clock that can display both 12 and 24 hr times

void clock_12hr() - calculates the current time in 12 hour time and outputs it
void clock_24hr() - calculates the current time in 24 hour time and outputs it
void addhR() - adds an hour to both 12 and 24 hr times
void addMin() - adds a minute to both 12 and 24 hr times
void addSec() - adds a second to both 12 and 24 hr times
void displayClock() - outputs both the 12 and 24 hr times
*/
class clockDisplay
{
private:
	int hour;
	int minute;
	int second;

	void clock_12hr();
	void clock_24hr();

public:
	clockDisplay();

	void addHr();
	void addMin();
	void addSec();

	void displayClock();
};
clockDisplay::clockDisplay()
{
	time_t now = time(0); //gets current Time
	tm *ltm = localtime(&now); //converts current Time to struct tm type

	this->hour = ltm->tm_hour;
	this->minute = ltm->tm_min;
	this->second = ltm->tm_sec;
}

void clockDisplay::clock_24hr()
{
	cout.fill('0');
	cout << setw(2) << this->hour << ':' << setw(2) << this->minute << ':' << setw(2) << this->second;
}

void clockDisplay::clock_12hr()
{
	string am_pm;
	int newHr = this->hour;

	if (newHr == 0)
		newHr = 12;

	//  Calculates if time is in AM or PM
	if (newHr > 12)
	{
		am_pm = "PM";
		newHr = newHr - 12;
	}
	else
		am_pm = "AM";

	cout.fill('0');
	cout << setw(2) << newHr << ':' << setw(2) << this->minute << ':' << setw(2) << this->second
		<< " " << am_pm;

}

void clockDisplay::addHr()
{
	this->hour = this->hour + 1;

	if (this->hour > 23)
		this->hour = 0;
}

void clockDisplay::addMin()
{
	this->minute = this->minute + 1;

	if (this->minute > 59)
	{
		this->addHr();
		this->minute = 0;
	}
}

void clockDisplay::addSec()
{
	this->second = this->second + 1;

	if (this->second > 59)
	{
		this->addMin();
		this->second = 0;
	}
}

void clockDisplay::displayClock()
{
	cout << "**************************     **************************\n";
	cout << "*     12-Hour Clock      *     *     24-Hour Clock      *\n";
	cout << "*     "; 
	this->clock_12hr();
	cout << "        *     *     ";
	this->clock_24hr();
	cout << "           *\n";
	cout << "**************************     **************************\n";
}


/*
menu() displays to the user valid inputs, and what each input does
*/
void menu()
{
	cout << "**************************\n";
	cout << "* 1-Add One Hour         *\n";
	cout << "* 2-Add One Minute       *\n";
	cout << "* 3-Add One Second       *\n";
	cout << "* 4-Exit Program         *\n";
	cout << "**************************\n";
}


void runTime(clockDisplay c)
{
	string userInp = "";

	while (userInp != "4")
	{
		system("CLS");  // Clears the screen

		c.displayClock();
		menu();

		cin >> userInp;

		if (userInp == "1")
			c.addHr();
		else if (userInp == "2")
			c.addMin();
		else if (userInp == "3")
			c.addSec();
		else if (userInp == "4")
			break;
	
	}
}

int main()
{
	clockDisplay newClock;
	runTime(newClock);
	return 0;
}