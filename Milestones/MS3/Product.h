// Author: Lean Junio
// File" Product.h
// Description: Product class header
#include "ErrorState.h"

namespace AMA
{
	// Concrete class that encapsulates the general information for an AMA product
	// Uses the ErrorState object

	const int MAX_SKU = 7;
	const int MAX_UNIT_DESCRIPTOR = 10;
	const int MAX_NAME_DESCRIPTOR = 75;
	const double TAX_RATE = 0.13;

	class Product
	{
	private:
		char m_ProductType;
		char m_ProductSKU[MAX_SKU];
		char m_ProductUnit[MAX_UNIT_DESCRIPTOR];
		char* m_UnitAddress;
		int m_ProductQuantity;
		int m_ProductNeeded;
		double m_PriceBeforeTax;
		bool m_Taxable;
		ErrorState er;
	protected:
		// Receives the address that holds the name of the product
		// 1. Stores the name in a dynamically allocated memory
		// 2. Replaces any name previously stored
		// 3. if nullptr, remove the name of the product (if any exists) from the memory
		void name(const char* address);

		// Returns the address of the string that holds the name of the product
		// 1. if the product has no name, return nullptr
		const char* name() const;

		// Returns the price of a single item of the product plus any tax that applies to the product
		double cost() const;

		// Receives the address of a string holding an error message
		// Stores that message in the ErrorState object
		void message(const char* address);

		// Return true if the ErrorState object is clear, else, false
		bool isClear() const;
	
	public:

		// Receives an optional character that identifies the product type
		// The default value is 'N'
		// 1. Store the character in an instance variable
		// 2. Set object to empty state
		Product(char type = 'N');

		
		Product();
	};
}