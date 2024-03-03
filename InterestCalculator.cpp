#include <iostream>
#include <iomanip>
using namespace std;

#include "InterestCalculator.h"

void InterestCalculator::displayMenu() {
	cout << "   Welcome to Airgead Banking" << endl;
	cout << endl;
	cout << "********************************" << endl;
	cout << "***********Data Input***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit Amount: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years of Investment: " << endl;
	cout << "********************************" << endl;
	system("pause");
	cout << endl;
}

void InterestCalculator::interestTableNoDeposit(double& t_currBal, int t_annualInt, int t_numYears) {
	cout << " Balance and Interest WITHOUT Additional Monthly Deposits" << endl;
	cout << "**********************************************************" << endl;
	cout << "  YEAR\t     YEAR END BALANCE\t YEAR END EARNED INTEREST" << endl;
	cout << "**********************************************************" << endl;
	double monthlyInt;
	for (int i = 1; i <= t_numYears; ++i) { // table for no additional deposits
		double yearEndEarned = 0.0;
		for (int j = 1; j <= 12; ++j) {
			monthlyInt = t_currBal * ((t_annualInt / 100.0) / 12.0);
			t_currBal = t_currBal + monthlyInt;
			yearEndEarned = yearEndEarned + monthlyInt;
		}
		cout << "    " << i << "\t\t $" << fixed << setprecision(2) << t_currBal << "\t\t\t $" << yearEndEarned << endl;
	}
}

void InterestCalculator::interestTableWithDeposit(double& t_initialInvestment, double t_monthlyDep, int t_annualInt, int t_numYears) {
	cout << "   Balance and Interest WITH Additional Monthly Deposits" << endl;
	cout << "**********************************************************" << endl;
	cout << "  YEAR\t     YEAR END BALANCE\t YEAR END EARNED INTEREST" << endl;
	cout << "**********************************************************" << endl;
	double monthlyInt;
	double currBalance = t_initialInvestment;
	for (int i = 1; i <= t_numYears; ++i) { // table for no additional deposits
		double yearEndEarned = 0.0;
		for (int j = 1; j <= 12; ++j) {
			monthlyInt = currBalance * ((t_annualInt / 100.0) / 12.0);
			currBalance = currBalance + t_monthlyDep + monthlyInt;
			yearEndEarned = yearEndEarned + monthlyInt;

			//cout << j << "\t\t$" << fixed << setprecision(2) << currBalance << "\t\t$" << yearEndEarned << endl;
		}
		cout << "    " << i << "\t\t $" << fixed << setprecision(2) << currBalance << "\t\t $" << yearEndEarned << endl;
	}
}

void InterestCalculator::getUserInput() {
	double initialInvestment;
	double monthlyDeposit;
	int annualInterest;
	int numInvestmentYears;

	int userChoice = 2;

	while (userChoice != 1) {
		cout << "Enter whole number values." << endl;
		cout << endl;
		cout << "Initial Investment: $";
		cin >> initialInvestment;
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << "Annual Interest: %";
		cin >> annualInterest;
		cout << "Number of Years of Investment: ";
		cin >> numInvestmentYears;

		cout << endl;
		interestTableNoDeposit(initialInvestment, annualInterest, numInvestmentYears);
		cout << endl;
		interestTableWithDeposit(initialInvestment, monthlyDeposit, annualInterest, numInvestmentYears);

		cout << endl;
		cout << "Type '1' to QUIT or '2' to CONTINUE" << endl;
		cin >> userChoice;
	}

	cout << "Exiting Program." << endl;
}