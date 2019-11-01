/*
menuconversion.cpp
Erin Tan
CSCI 140 T,Th
Project #2 question 1
Visual Studio 2019
10/24/19
*/

#include <iostream>
#include <string>
using namespace std;

void menu();
double mitokm(double);
double fttom(double);
double degftodegc(double);

int main()
{
	enum Choice {option, miles, feet, degf };

	double x;
	int i = -1;
	int selection;
	bool quit;

	do {
		menu();
		cin >> i;
		quit = false;
		switch (i) {
		case miles:
			cout << "Enter a number to convert miles to kilometers: ";
			cin >> x;
			cout << "Kilometers:" << mitokm(x) << endl;
			break;
		case feet:
			cout << "Enter a number to convert feet to meters: ";
			cin >> x;
			cout << "Meters:" << fttom(x) << endl;
			break;
		case degf:
			cout << "Enter a number to convert Fahrenheit to Celcius: ";
			cin >> x;
			cout << "Celcius:" << degftodegc(x) << endl;
			break;
		case option:
			cout << "Quit? Enter 0 again to quit, 1 to continue:";
			cin >> selection;
			if (selection == 1) {
				break;
			}
			else {
				quit = true;
			}

		}
	} while (!quit);
	system("PAUSE");
	return 0;
}

void menu() {
	cout << "0. Option menu" << endl;
	cout << "1. Miles" << endl;
	cout << "2. Feet" << endl;
	cout << "3. Degrees Fahrenheit" << endl;
	cout << "Enter an option number: ";
}

double mitokm(double x) {
	return x * 1.609;
}

double fttom(double x) {
	return x * 0.3048;
}

double degftodegc(double x) {
	return (x - 32) * 0.5556;
}
