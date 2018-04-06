// File: Product.h
// Author: Lean Junio
// Description: Header file for Product module

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include "ErrorState.h"

namespace AMA
{
	const int MAX_CHAR_SKU = 7;					// Maximum number of characters in a sku (stock keeping unit)
	const int MAX_CHAR_UNIT = 10;				// Maximum number of characters in a sku (stock keeping unit)
	const int MAX_CHAR_NAME = 75;				// Maximum number of characters in the user’s name descriptor for a product length
	const double TAX_RATE = 0.13;				// The current tax rate

	const int max_sku_length = MAX_CHAR_SKU;
	const int max_name_length = MAX_CHAR_NAME;
	const int max_unit_length = MAX_CHAR_UNIT;

	class Product 
	{
	private:
		char mp_Pr_Type;						// A character that indicates the type of the product – for use in the file record
		char mp_Pr_Sku[MAX_CHAR_SKU + 1];		// A character array that holds the product’s sku (stock keeping unit) - null char
		char mp_Pr_Unit[MAX_CHAR_UNIT + 1];		// A character array that describes the product’s units
		char* mp_Address_Pr_Name;				// A pointer that holds the address of a string in dynamic memory containing the name of the product
		int mp_Quantity_Pr_OnHand;				// An integer that holds the quantity of the product currently on hand; that is, the number of units currently on hand
		int mp_Quantity_Pr_Needed;				// An integer that holds the quantity of the product needed; that is, the number of units needed
		double mp_Price_Pr_SingleBeforeTax;		// A double that holds the price of a single unit of the product before any taxes
		bool mp_Pr_Taxable;						// A bool that identifies the taxable status of the product; its value is true if the product is taxable
		ErrorState mp_Err;						// An ErrorState object that holds the error state of the Product object
	
	protected:
		void name(const char* nameAddress);		// This function receives the address of a C-style null-terminated string that holds the name of the product
		const char* name() const;				// This query returns the address of the C-style string that holds the name of the product
		const char* sku() const;				// This query returns the address of the C-style string that holds the sku of the product
		const char* unit() const;				// This query returns the address of the C-style string that holds the unit of the product
		bool taxed() const;						// This query returns the taxable status of the product
		double price() const;					// This query returns the price of a single item of the product
		double cost() const;					// This query returns the price of a single item of the product plus any tax that applies to the product
		void message(const char*);				// This function receives the address of a C-style null-terminated string holding an error message and stores that message in the ErrorState object
		bool isClear() const;					// This query returns true if the ErrorState object is clear; false otherwise
	public:	
		Product(char type = 'N');				// This constructor optionally receives a character that identifies the product type. Default is N

		// Saves the data into the object
		Product(const char* sku, const char* address, const char * unit, int onHand = 0, int needed = 0, double beforeTax = 0.0, bool taxable = true);

		Product(const Product& other);			// This constructor receives an unmodifiable reference to a Product object and copies the object referenced to the current object
		
		~Product();								// This function deallocates any memory that has been dynamically allocated

		// This operator receives an unmodifiable reference to a Product object and replaces the current object with a copy of the object referenced
		Product& operator=(const Product & other);

		// This query receives a reference to an fstream object and an optional bool and returns a reference to the fstream object
		std::fstream& store(std::fstream& file, bool newLine = true) const;

		std::fstream& load(std::fstream& file); // This modifier receives a reference to an fstream object and returns a reference to that fstream object
		
		// This query receives a reference to an ostream object and a bool and returns a reference to the ostream object
		std::ostream& write(std::ostream& os, bool linear) const;

		// This modifier receives a reference to an istream object and returns a reference to the istream object
		std::istream& read(std::istream& is);

		// This query receives the address of an unmodifiable C-style null-terminated string and returns true if the string is identical to the sku of the current object
		bool operator==(const char* address) const;

		// This query that returns the total cost of all items of the product on hand, taxes included
		double total_cost() const;

		// This modifier that receives an integer holding the number of units of the Product that are on hand
		void quantity(int units);

		// This query returns true if the object is in a safe empty state
		bool isEmpty() const;

		// returns the number of units of the product that are needed
		int qtyNeeded() const;

		// returns the number of units of the product that are on hand
		int quantity() const;

		// This query receives the address of a C-style null-terminated string holding a product sku and returns true if the sku of the current object is greater than the string stored at the received address
		bool operator>(const char* address) const;

		// This query receives an unmodifiable reference to a Product object and returns true if the name of the current object is greater than the name of the referenced Product object
		bool operator>(const Product& other) const;

		// This modifier receives an integer identifying the number of units to be added to the Product and returns the updated number of units on hand
		int operator+=(int unitsToBeAdded);

	};
		// This helper receives a reference to an ostream object and an unmodifiable reference to a Product object and returns a reference to the ostream object 
		std::ostream& operator<<(std::ostream& os, const Product& other);

		// This helper receives a reference to an istream object and a reference to a Product object and returns a reference to the istream object
		std::istream& operator>>(std::istream& is, Product& other);

		// This helper receives a reference to a double and an unmodifiable reference to a Product object and returns a double
		double operator+=(double& total, const Product& other);
}

#endif

