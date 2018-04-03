// Author: Lean Junio
// File" Product.h
// Description: Product class header
#include <fstream>
#include "ErrorState.h"

namespace AMA
{
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;

	// Concrete class that encapsulates the general information for an AMA product
	// Uses the ErrorState object
	const int MAX_SKU = 7;
	const int MAX_UNIT_DESCRIPTOR = 10;
	const int MAX_NAME_DESCRIPTOR = 75;
	const double TAX_RATE = 0.13;

	class Product
	{
	private:
		// A character that indicates the type of the product - for use in the file record
		char m_ProductType;

		// A character array that holds the product's SKU
		char m_ProductSKU[MAX_SKU];

		// A character array that describes the product's unit
		char m_ProductUnit[MAX_UNIT_DESCRIPTOR];

		// A pointer that holds the address of a string in dynamic memory containing the name of the product
		char* m_UnitAddress;

		// Product quantity currently on hand
		int m_ProductQuantity;

		// Quantity of the product needed
		int m_ProductNeeded;
		
		// Holds the price of a single unit before tax is applied
		double m_PriceBeforeTax;

		// Says if the product is taxable
		bool m_Taxable;

		// Holds the error state of the Product object
		ErrorState m_er;
		
	protected:
		// Receives the address that holds the name of the product
		// 
		// 1. Stores the name in a dynamically allocated memory
		// 2. Replaces any name previously stored in that address
		// 3. if nullptr, remove the name of the product (if any exists) from the memory
		void name(const char* address);

		// Returns the ADDRESS of the string holding the name of the product
		// 
		// 1. Return the address of the string holding the name of the product
		// 2. If the product has no name, return nullptr
		const char* name() const;

		// Returns the price of a single item of the product plus any tax that applies to the product
		// 
		// 1. Return price of the item + tax
		double cost() const;

		// Receives the address of a string holding an error message
		// Stores that message in the ErrorState object
		// 
		// 1. Isolate the error message that is stored in the address passed
		// 2. Store that message inside an ErrorState object
		void message(const char* address);

		// Return true if the ErrorState object is clear, else, false
		// 
		bool isClear() const;
	
	public:
		// Receives an optional character that identifies the product type, the default value is = 'N'
		// 
		// 1. Store the character in an instance variable
		// 2. Set object to empty state
		Product(char type = 'N');

		// Declares everything into EmptyState
		// 
		// Allocates enough memory to hold the name of the product
		// A protected function has been declared to perform this task
		Product(const char* sku, const char* productName, const char* productUnit, int quantity = 0, bool taxable = true, double priceBeforeTax = 0.0, int qtyOfProductNeeded = 0);

		// Receives a reference to a Product obect 
		// Copies the object referenced to the current object
		// 
		// 1. Perform a shallow copy on all the non-resource instance variables (values that don't have *ers)
		// 2. Allocate dynamic memories for the variables that uses *ers
		Product(const Product& other);

		// Receives a reference to a Product object
		// Replaces the current object with a copy of the object referenced
		// Copy Assignment = contains logic for copying data from an existing object to an existing object
		// 
		// 1. Check the &other for self assignment
		// 2. Shallow copy all the non-resource variables (variables not using *ers)
		// 3. Deallocate any previously allocated memory
		// 4. Allocate new memory for the resource (variables using *ers) associated with the current object
		// 5. Copy resource data from the source object to the newly allocated memory of the current object
		Product& operator=(const Product& other);

		// Deallocate memory that has been dynmically allocated
		~Product();
		
		// Receives a reference to an fstream object and an optional bool and returns a reference to the fstream object
		// 
		// 1. Insert m_ProductType to the file as the first field in the record
		// 2. Insert the data for the current object in comma separated fields
		// 3. if bool == true, insert an endl at the end of the record 
		std::fstream& store(std::fstream& file, bool newLine=true) const;

		// Receives a reference to an fstream object
		// 
		// 1. Extract the fields for a single record from the fstream object
		// 2. Create a temporary object containing the extracted data
		// 3. Copy assign (=) the temporary object to the current object
		std::fstream& load(std::fstream& file);

		// Inserts the data fields for the current object, into the ostream object in the order shown on the pdf and separate
		// the data fields by a '|'
		// 
		// 1. If linear == true/false, the output should be on a single line as referred to in the pdf
		std::ostream& write(std::ostream& os, bool linear) const;

		// Extracts the field in the order provided in the pdf
		std::istream& read(std::istream& is);

		// Receives the address of a string
		//
		// 1. Check if the passed string == current object's SKU
		// 2. Return the boolean
		bool operator==(const char* address) const;

		// Return the total cost of all items of the product on hand w/ taxes included
		// 
		// 1. Add up all of the costs += taxes
		// 2. Return the sum
		double total_cost() const;

		// Resets m_ProductQuantity to qtyProductsOnHand
		void quantity(int qtyProductsOnHand);

		// Return true if the object is in a safe empty state
		bool isEmpty() const;

		// Return the number of units of the product needed
		int qtyNeeded() const;

		// return the number of units of the product on hand
		int quantity() const;

		// Return true if this.SKU > the string stored in the address
		bool operator>(const char* productSKU) const;

		// Return true if the name of the object > other.name
		bool operator>(const Product& other) const;
		
		// Return the updated number of units on hand
		// 
		// 1. If the param is +ve, add to the number of units on hand
		// 2. If the param is -ve, do nothing and return the quantity on hand
		int operator+=(int numUnitsToBeAdded);
	};

	// Returns a reference to the ostream object
	// 
	// 1. Insert a Product record into ostream
	std::ostream& operator<<(std::ostream& os, const Product& other); 

	// Returns a reference to an istream object
	// 
	// 1. Extracts the Product record from the istream
	std::istream& operator>>(std::istream& is, Product& other);

	// Returns the sum (updated) of dbl + other
	double operator+=(double& dbl, const Product& other);
}