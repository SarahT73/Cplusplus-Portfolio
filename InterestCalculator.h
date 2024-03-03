#pragma once

#ifndef InterestCalculator_h
#define InterestCalculator_h

#include <iostream>
#include <iomanip>

using namespace std;

// InterestCalculator.h
class InterestCalculator {

public:
	void displayMenu();
	void interestTableNoDeposit(double& t_currBal, int t_annualInt, int t_numYears);
	void interestTableWithDeposit(double& t_initialInvestment, double t_monthlyDep, int t_annualInt, int t_numYears);
	void getUserInput();
};


#endif // InterestCalculator.h
