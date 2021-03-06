
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount {
		double m_Balance;
	protected:
		double balance() const;
	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		// 
		// Receives either a double holding the initial account balance or nothing
		Account(double initBalance);

		// TODO: credit adds +ve amount to the balance 
		// 
		// if +ve valued param, add param to m_Balance and return true
		// If -ve valued, return false
		bool credit(double amountToAdd);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double amountToSubtract);
	};

	// TODO: add prototype for Allocator function
	iAccount* CreateAccount(const char* type, double initBalance);
}
#endif
