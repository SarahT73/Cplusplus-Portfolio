#include <iostream>
#include <iomanip>
using namespace std;


#include "InterestCalculator.h"

int main() {

	InterestCalculator investmentData;

	investmentData.displayMenu();
	investmentData.getUserInput();

	return 0;
}