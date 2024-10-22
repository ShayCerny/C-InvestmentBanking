#include <iostream>
#include <iomanip>
#include "Investment.h"
#include "utility.h"

using namespace std;

int main() {
	// start a do while loop so the user can retry the investment calculator with different values
	do {
		// get the users input and create an instance of Investment
		auto userInvestment = getInitialData();

		// generate a print report without monthly contributions
		cout << userInvestment->getInvestmentReport(false) << endl << endl;

		// generate a print report with monthly contributions
		cout << userInvestment->getInvestmentReport(true);

		//Wait for user input
		cout << "Press any key to continue . . .";
		cin.ignore();
		cin.get();

		//ask the user if they want to try again
		char choice;
		choice = getValidCharInput("Would you like to try again with different values? (Y/N)");

		//continue or break based on user input
		if (choice != 'y') {
			break;
		}

	} while (true);

	return 0;
}