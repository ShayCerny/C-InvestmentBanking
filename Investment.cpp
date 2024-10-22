#include "Investment.h"
#include <iomanip> 
#include <sstream> // string buffer for creating formatted string before outputing to console

using namespace std;

//Constructor
Investment::Investment(double t_initial, double t_monthly, double t_rate, int t_yrs) :
	m_initialAmount(t_initial), m_monthlyContribution(t_monthly), m_interestRate(t_rate), m_years(t_yrs) {}

//Default Constructor (all values default to 0)
Investment::Investment() :
	m_initialAmount(0), m_monthlyContribution(0), m_interestRate(0), m_years(0) {}

//Setters
void Investment::setInitialAmount(double t_amount) {
	m_initialAmount = t_amount;
}

void Investment::setMonthlyContribution(double t_amount) {
	m_monthlyContribution = t_amount;
}

void Investment::setInterestRate(double t_rate) {
	m_interestRate = t_rate;
}

void Investment::setYears(int t_yrs) {
	m_years = t_yrs;
}

// Getters
double Investment::getInitialAmount() const {
	return m_initialAmount;
}

double Investment::getMonthlyContribution() const {
	return m_monthlyContribution;
}

double Investment::getInterestRate() const {
	return m_interestRate;
}

int Investment::getYears() const {
	return m_years;
}

//Function to generate the investment report
string Investment::getInvestmentReport(bool t_withMonthly)const {
	// collecting important variables
	double currentBalance = m_initialAmount;
	double monthlyInterest = (m_interestRate / 100.0) / 12.0;
	double monthlyContribution = m_monthlyContribution;
	double totalInterestEarned = 0;

	ostringstream report; // formatted string which will be returned

	//Header
	if (t_withMonthly) // if this report will contain the monthly deposits change the header
	{
		report << setw(66) << "Balance and Interest With Additional Monthly Deposits" << endl;
	}
	else {
		report << setw(66) << "Balance and Interest Without Additional Monthly Deposits" << endl;
	}
	report << setfill('=') << setw(76) << "=" << endl;
	report << setfill(' ') << setw(5) << "Year" << setw(30) << "Year End Balance" << setw(40) << "Year End Earned Interest" << endl;
	report << setfill('-') << setw(76) << "-" << endl;

	// Loop through each year
	for (int year = 1; year <= m_years; ++year) {
		double yearEndInterest = 0.0; // Interest earned during the year

		// Loop through each month
		for (int month = 1; month <= 12; ++month) {
			// Add monthly contribution if applicable
			if (t_withMonthly) {
				currentBalance += monthlyContribution; // Add monthly contribution to current balance
			}
			// Calculate monthly interest and update balance
			double interestForThisMonth = currentBalance * monthlyInterest;
			currentBalance += interestForThisMonth; // Add interest to current balance
			yearEndInterest += interestForThisMonth; // Track total interest for the year

		}
		// Update the total interest earned
		totalInterestEarned += yearEndInterest;

		// Create Temp stream for string formatting
		// this extra formatting is to ensure the dollar amounts are in the same position each time regardless of how long the number is
		// it was done due to the setw() only applying to the "$" which offset the dollar amounts each time they gained an place
		ostringstream tempStream;
		
		//format current balance
		tempStream << fixed << setprecision(2);
		tempStream << "$" << currentBalance;
		string balanceStr = tempStream.str();

		tempStream.str(""); // clear stream buffer

		//format year end interest
		tempStream << fixed << setprecision(2);
		tempStream << "$" << yearEndInterest;
		string interestStr = tempStream.str();

		// Format the report line for the current year
		report << setfill(' ');
		report << setw(5) << year
			<< setw(30) << balanceStr
			<< setw(40) << interestStr <<endl;

	}
	return report.str(); // return formatted string
}