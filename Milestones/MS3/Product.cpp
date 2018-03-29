// Author: Lean Junio
// File" Product.cpp
// Description: Product class header
#include <iostream>
#include "Product.h"
using namespace std;
using namespace AMA;

void Product::name(const char * address)
{
	// Check if the address aready has something in it
	if (!nullptr) 
	{
		// 1. Stores the name in a dynamically allocated memory
		// 2. Replaces any name previously stored in that address
	} 
	else
	{

		// 3. if nullptr, remove the name of the product (if any exists) from the memory
	}
}

const char * Product::name() const
{
	if (m_UnitAddress[0] != '\0')
	{
		// 1. Return the address of the string holding the name of the product
		return m_UnitAddress;
	}
	else
	{
		// 2. If the product has no name, return nullptr
		return nullptr;
	}
}

double Product::cost() const
{
	return m_PriceBeforeTax + (m_PriceBeforeTax * TAX_RATE);
}

void Product::message(const char * address)
{
	// 1. Isolate the error message that is stored in the address passed
	// 2. Store that message inside an ErrorState object 
}

bool Product::isClear() const
{
	return (this->m_er.isClear()) ?  true :  false;
}

Product::Product(char type)
{
	this->m_ProductType = type;
	m_ProductSKU[0] = '\0';
	m_ProductUnit[0] = '\0';
	m_UnitAddress = nullptr;
	m_ProductQuantity = 0;
	m_ProductNeeded = 0;
	m_PriceBeforeTax = 0.0;
	m_Taxable = true;
	m_er;
}

Product::Product(char * sku, char * productName, char * productUnit, int quantity, bool taxable, double priceBeforeTax, int qtyOfProductNeeded)
{
}

Product::Product(const Product & other)
{
	// 1. Perform a shallow copy on all the non-resource instance variables (values that don't have *ers)

	
}

Product & Product::operator=(const Product & other)
{
	// 1. Check the &other for self assignment
	// 2. Shallow copy all the non-resource variables (variables not using *ers)
	// 3. Deallocate any previously allocated memory
	// 4. Allocate new memory for the resource (variables using *ers) associated with the current object
	// 5. Copy resource data from the source object to the newly allocated memory of the current object
	// TODO: insert return statement here
}

Product::~Product()
{
}

std::fstream & Product::store(std::fstream & file, bool newLine) const
{
	// TODO: insert return statement here
}

std::fstream & Product::load(std::fstream & file)
{
	// TODO: insert return statement here
}

std::ostream & Product::write(std::ostream & os, bool linear) const
{
	// TODO: insert return statement here
}

std::istream & Product::read(std::istream & is)
{
	// TODO: insert return statement here
}

bool Product::operator==(const char * address) const
{
	return false;
}

double Product::total_cost() const
{
	return 0.0;
}

void Product::quantity(int qtyProductsOnHand)
{
}

bool Product::isEmpty() const
{
	return false;
}

int Product::qtyNeeded() const
{
	return 0;
}

int Product::quantity() const
{
	return 0;
}

bool Product::operator>(const char * productSKU) const
{
	return false;
}

bool Product::operator>(const Product & other) const
{
	return false;
}

int Product::operator+=(int numUnitsToBeAdded)
{
	return 0;
}

std::ostream & operator<<(std::ostream & os, const Product & other)
{
	// TODO: insert return statement here
}

std::istream & operator>>(std::istream & is, Product & other)
{
	// TODO: insert return statement here
}

double operator+=(double & dbl, const Product & other)
{
	return 0.0;
}
