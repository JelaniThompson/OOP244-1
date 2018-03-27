#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double interest = 0.05;

	// TODO: Allocator function
	//
	// Receives the type of account to be created and the initial balance in the account
	// Returns the address to the calling function
	// If the initial character of the string is 'S', the function creates a savings account in dynamic memory
	// If the string does not identify a type that is available, the function returns nullptr
	iAccount* CreateAccount(const char* type, double initBalance) {
		iAccount *p = nullptr;
		if (type[0] == 'S') p = new SavingsAccount(initBalance, interest);
		return p;
	}
}
