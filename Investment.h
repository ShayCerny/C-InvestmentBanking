#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>;

using namespace std;

class Investment {
	// Encapsulation of class variables
private:
	double m_initialAmount;
	double m_monthlyContribution;
	double m_interestRate; // as a percentage 5 for 5%
	int m_years;

public:
	//Constructior
	Investment(double t_initial, double t_monthly, double t_rate, int t_yrs);

	//Default Constructor
	Investment();

	//Setters for modifiying values after creation
	void setInitialAmount(double t_amount);
	void setMonthlyContribution(double t_amount);
	void setInterestRate(double t_rate);
	void setYears(int t_yrs);

	// Getters for retrieving the private data
	double getInitialAmount() const;
	double getMonthlyContribution() const;
	double getInterestRate() const;
	int getYears() const;


	//Function to generate the investment report
	string getInvestmentReport(bool t_withMonthly)const;
};

#endif // INVESTMENT_H