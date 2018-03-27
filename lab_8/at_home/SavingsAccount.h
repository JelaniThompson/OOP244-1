
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include <iostream>
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double m_Interest;
	public:
		// TODO: constructor initializes balance and interest rate
		// 
		// Receives the initial balance and the interest rate to be applied to the balance
		// If the interest rate received is +ve, the function stores the rate
		// If the interest rate received is -ve, the function stores 0.0 as the rate to be applied
		SavingsAccount(double initBalance, double interestRate);

		// TODO: perform month end transactions
		// 
		// Calculates the interest earned on the current balance and credits the account with that interest
		void monthEnd();

		// TODO: display inserts the account information into an ostream		
		// 
		// Receives a reference to an ostream object and displays
		void display(std::ostream& os) const;	
	};
}
#endif
