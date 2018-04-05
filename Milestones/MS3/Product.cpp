#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Product.h"
using namespace std;

namespace AMA
{
	void Product::name(const char *nameAddress)
	{
		// If the incoming parameter holds the nullptr address, this function removes the name of the product, if any, from memory
		if (nameAddress == nullptr)
		{
			// Remove the name of the product from the memory
			delete[] mp_Address_Pr_Name;
			mp_Address_Pr_Name = nullptr;
		}
		else
		{
			// Store the name from the passed address into dynamic memory
			// Replaces any name that was previously stored in the address
			mp_Address_Pr_Name = new char[char_traits<char>::length(nameAddress)];
		}
	}
	const char * Product::name() const
	{
		//If the product has no name, this query returns nullptr
		return (mp_Address_Pr_Name[0] == '\0') ? nullptr : mp_Address_Pr_Name;
	}
	const char * Product::sku() const
	{
		return mp_Pr_Sku;
	}
	const char * Product::unit() const
	{
		return mp_Pr_Unit;
	}
	bool Product::taxed() const
	{
		return mp_Pr_Taxable;
	}
	double Product::price() const
	{
		return mp_Price_Pr_SingleBeforeTax;
	}
	double Product::cost() const
	{
		return price() + (price() * TAX_RATE);
	}
	void Product::message(const char* addressError)
	{
		mp_Err.message	(addressError);
	}
	bool Product::isClear() const
	{
		return mp_Err.isClear();
	}
	Product::Product(char type = 'N')
	{
		mp_Pr_Type = type;
		mp_Pr_Sku[0] = '\0';
		mp_Pr_Unit[0] = '\0';
		mp_Address_Pr_Name = nullptr;
		mp_Quantity_Pr_OnHand = 0;
		mp_Quantity_Pr_Needed = 0;
		mp_Price_Pr_SingleBeforeTax = 0.0;
		mp_Pr_Taxable = true;
		mp_Err;
	}
	Product::Product(const char* sku, const char* address, const char * unit, int onHand, int needed, double beforeTax, bool taxable)
	{
		// This constructor allocates enough memory to hold the name of the product.
		name(address);
		strcpy(mp_Pr_Sku, sku);
		strcpy(mp_Pr_Unit, unit);
		mp_Quantity_Pr_OnHand = onHand;
		mp_Quantity_Pr_Needed = needed;
		mp_Price_Pr_SingleBeforeTax = beforeTax;
		mp_Pr_Taxable = taxable;
	}
	Product::Product(const Product & other)
	{
		*this = other;
	}
	Product & Product::operator=(const Product & other)
	{
		if (this != &other)
		{
			mp_Pr_Type = other.mp_Pr_Type;
			strcpy(mp_Pr_Sku, other.mp_Pr_Sku);
			strcpy(mp_Pr_Unit, other.mp_Pr_Unit);
			mp_Quantity_Pr_OnHand = other.mp_Quantity_Pr_OnHand;
			mp_Quantity_Pr_Needed = other.mp_Quantity_Pr_Needed;
			mp_Price_Pr_SingleBeforeTax = other.mp_Price_Pr_SingleBeforeTax;
			mp_Pr_Taxable = other.mp_Pr_Taxable;

			delete[] mp_Address_Pr_Name;
			name(other.mp_Address_Pr_Name);

			if (!other.isClear())
				mp_Err.message(other.mp_Err.message());
		}
		return *this;
	}

	Product::~Product()
	{
		delete[] mp_Address_Pr_Name;
		mp_Address_Pr_Name = nullptr;
		mp_Err.clear();
	}
	std::fstream & Product::store(std::fstream & file, bool newLine) const
	{
		// inserts into the fstream object the character that identifies the product type as the first field in the record
		// inserts into the fstream object the data for the current object in comma separated fields
		if (file.is_open())
			file << mp_Pr_Type << ',' << mp_Pr_Sku << ',' << mp_Pr_Unit << ',' << mp_Address_Pr_Name << ',' << mp_Quantity_Pr_OnHand << "," << mp_Quantity_Pr_Needed << "," << mp_Price_Pr_SingleBeforeTax << "," << mp_Pr_Taxable;
		
		// if the bool parameter is true, inserts a newline at the end of the record
		if (newLine)
			file << endl;
		return file;
	}
	std::fstream & Product::load(std::fstream & file)
	{
		// extracts the fields for a single record from the fstream object
		// creates a temporary object from the extracted field data
		// copy assigns the temporary object to the current object
		Product temp;

		temp.mp_Address_Pr_Name = new char[MAX_CHAR_NAME + 1];

		if (file.is_open())
		{
			file >> temp.mp_Pr_Type >> temp.mp_Pr_Sku >> temp.mp_Pr_Unit >> temp.mp_Address_Pr_Name >> temp.mp_Quantity_Pr_OnHand >> temp.mp_Quantity_Pr_Needed >> temp.mp_Price_Pr_SingleBeforeTax >> temp.mp_Pr_Taxable;
			*this = temp;
		}

		delete[] temp.mp_Address_Pr_Name;
		temp.mp_Address_Pr_Name = nullptr;

		return file;
	}
	std::ostream & Product::write(std::ostream & os, bool linear) const
	{
		// inserts the data fields for the current object into the ostream object in the following order and separates them by a vertical bar character (‘|’)
		// If the bool parameter is true, the output is on a single line with the field widths as shown below in parentheses
		if (linear)
		{
			os << "sku - " << setw(MAX_CHAR_SKU) << mp_Pr_Sku << '|'
				<< "name - " << setw(20) << mp_Address_Pr_Name << '|'
				<< "cost - " << setw(7) << mp_Price_Pr_SingleBeforeTax << '|'
				<< "quantity - " << setw(4) << mp_Quantity_Pr_OnHand << '|'
				<< "unit - " << setw(10) << mp_Pr_Unit << '|'
				<< "quantity needed - " << setw(4) << mp_Quantity_Pr_Needed << '|';
		}
		else
		{
			os << "Sku: " << mp_Pr_Sku << "|" << endl
				<< "Name: " << mp_Address_Pr_Name << "|" << endl
				<< "Price: " << mp_Price_Pr_SingleBeforeTax << "|" << endl;
			if (mp_Pr_Taxable)
			{
				os << "Price after tax: " << mp_Price_Pr_SingleBeforeTax * (1 + TAX_RATE) << "|" << endl;
			}
			else
			{
				os << "N/A" << "|" << endl;
			}

			os << "Quantity On Hand: " << mp_Quantity_Pr_OnHand << "|" << endl
				<< "Quantity Needeed: " << mp_Quantity_Pr_Needed << "|" << endl;
		}
		return os;
	}
	std::istream & Product::read(std::istream & is)
	{
		Product temp;

		char sku[MAX_CHAR_SKU + 1];
		char* productName = new char[MAX_CHAR_NAME + 1];
		char unit[MAX_CHAR_UNIT + 1];
		int quantity;
		int quantityNeeded;
		double price;
		char taxable[1];

		// This function extracts the data fields for the current object in the following order, line by line
		cout << "Sku: ";
		is >> sku;
		cout << "Name: ";
		is >> productName;
		cout << "Unit: ";
		is >> unit;
		cout << "Taxed? (Y/N): ";
		is >> taxable;

		// Check if the user input is acceptable
		if (taxable[0] != 'y' && taxable[0] != 'Y' && taxable[0] != 'n' && taxable[0] != 'N')
		{
			// sets the error object to the error message noted in brackets
			mp_Err.message("Only(Y)es or (N)o are acceptable");

			// sets the failure bit of the istream object(calling istream::setstate(std::ios::failbit))
			is.setstate(std::ios::failbit);
		}

		cout << "Price: ";
		is >> price;

		// If the istream object is not in a failed state and this function encounters an error on accepting Price input
		if (is.fail())
		{
			// sets the error object to the error message noted in brackets
			mp_Err.message("Invalid Price Entry");
			is.setstate(std::ios::failbit);
		}

		cout << "Quantity on hand: ";
		is >> quantity;

		if (is.fail())
		{
			mp_Err.message("Invalid Quantity Entry");
			is.setstate(std::ios::failbit);
		}

		cout << "Quantity Needed: ";
		is >> quantityNeeded;

		if (is.fail())
		{
			mp_Err.message("Invalid Quantity Needed Entry");
		}

		// Check if there are no error messages - If the istream object has accepted all input successfully
		// stores the input values accepted in a temporary object and copy assigns it to the current object
		if (mp_Err.isClear())
		{
			bool tax;
			if (taxable[0] == 'y' || taxable[0] == 'Y')
				tax = true;
			else if (taxable[0] == 'n' || taxable[0] == 'N')
				tax = false;

			// copy everything to the temp object
			strcpy(temp.mp_Pr_Sku, sku);
			strcpy(temp.mp_Address_Pr_Name, productName);
			strcpy(temp.mp_Pr_Unit, unit);
			temp.mp_Quantity_Pr_OnHand = quantity;
			temp.mp_Quantity_Pr_Needed = quantityNeeded;
			temp.mp_Price_Pr_SingleBeforeTax = price;
			temp.mp_Pr_Taxable = tax;

			// copy from the temp
			*this = temp;
		}
		// This function stops extracting data once it has encountered an error. The error messages are shown in brackets
		delete[] productName;
		return is;
	}

	// Checks if the parameter == the sku of the current object
	bool Product::operator==(const char * address) const
	{
		bool compare = strcmp(address, this->mp_Pr_Sku);
		return compare;
	}
	double Product::total_cost() const
	{
		double total;
		double taxed = mp_Price_Pr_SingleBeforeTax * TAX_RATE;
		double withTax = mp_Price_Pr_SingleBeforeTax + taxed;
		
		return static_cast<double>(mp_Quantity_Pr_OnHand * withTax);
	}
	void Product::quantity(int units)
	{
		// This function resets the number of units that are on hand to the number received
		mp_Quantity_Pr_OnHand = units;
	}
	bool Product::isEmpty() const
	{
		return (mp_Address_Pr_Name == nullptr) ? true : false;
	}
	int Product::qtyNeeded() const
	{
		return mp_Quantity_Pr_Needed;
	}
	int Product::quantity() const
	{
		return mp_Quantity_Pr_OnHand;
	}
	bool Product::operator>(const char * address) const
	{
		return (strcmp(mp_Pr_Sku, address) > 0) ? true : false;
	}
	bool Product::operator>(const Product &other) const
	{
		return (strcmp(mp_Address_Pr_Name, other.mp_Address_Pr_Name) > 0) ? true : false;
	}
	int Product::operator+=(int unitsToBeAdded)
	{
		if (unitsToBeAdded > 0)
		{
			mp_Quantity_Pr_OnHand += unitsToBeAdded;
			return mp_Quantity_Pr_OnHand;
		}
		else return mp_Quantity_Pr_OnHand;
	}
	std::ostream & operator<<(std::ostream & os, const Product & other)
	{
		// insert a Product record into the ostream
		return other.write(os, true);

	}
	std::istream & operator>>(std::istream & is, Product & other)
	{
		other.read(is);
		return is;
	}
	double operator+=(double & total, const Product & other)
	{
		return total + other.total_cost();
	}
}

