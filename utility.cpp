#include <iostream>
#include <iomanip>
#include "Investment.h"
#include "utility.h"

// Function to get a valid double input from the user
double getValidDoubleInput(const string& prompt) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;

		// Check for input failure
		if (cin.fail()) {
			cin.clear(); // Clear the error flag
			cin.ignore();
			cout << "Invalid input. Please enter a numeric value." << endl << endl;
		}
		else {
			return value; // Return valid input
		}
	}
}

// Function to get a valid integer input from the user
int getValidIntInput(const string& prompt) {
	int value;
	while (true) {
		cout << prompt;
		cin >> value;

		// Check for input failure
		if (cin.fail()) {
			cin.clear(); // Clear the error flag
			cin.ignore();
			cout << "Invalid input. Please enter a whole number." << endl << endl;
		}
		else {
			return value; // Return valid input
		}
	}
}

// Function to get a valid character input from the user
char getValidCharInput(const string& prompt) {
	char choice;
	while (true) {
		cout << prompt;
		cin >> choice;

		// Check if the input is not followed by any other characters
		if (cin.fail() || cin.peek() != '\n') {
			cin.clear(); // Clear the error flag
			cin.ignore();
			cout << "Invalid input. Please enter a single character." << endl << endl;
		}
		else {
			return choice; // Return valid input
		}
	}
}


// Get Initial Investment Data, Will return an instance of Investment class
unique_ptr<Investment> getInitialData() {
	// local variables
	double initialAmount, monthlyContribution, interestRate;
	int years;
	string WAIT_FOR_KEY;


	cout << setfill('*') << setw(32) << "*" << endl;
	cout << setw(10) << "*" << " Data Input " << setw(10) << "*" << endl;

	//Get the user input for each value

	initialAmount = getValidDoubleInput("Initial Investment Amount: ");
	monthlyContribution = getValidDoubleInput("Monthly Deposit: ");
	interestRate = getValidDoubleInput("Annual Interest: ");
	years = getValidIntInput("Number of years: ");

	//Wait for user input
	cout << "Press any key to continue . . .";
	cin.ignore();
	cin.get();

	cout << endl << endl; // a little margin for the reports coming after

	// create an Investment instance using a smart pointer and then return
	return make_unique<Investment>(initialAmount, monthlyContribution, interestRate, years);
}