// Author: Lean Junio
// File" Product.cpp
// Description: Product class header
#include <iostream>
#include <iomanip>
#include "Product.h"
using namespace std;
using namespace AMA;

void Product::name(const char * address)
{
	if (address == nullptr)
	{
		delete[] m_UnitAddress;
		m_UnitAddress = nullptr;
		return;
	}
	else if (m_UnitAddress != nullptr)
	{
		delete[] m_UnitAddress;
	}
	int leng = strlen(address);
	m_UnitAddress = new char [leng + 1];
	snprintf(m_UnitAddress, leng + 1, "%s", address);
}

// 1. Return the address of the string holding the name of the product
// 2. If the product has no name, return nullptr
const char * Product::name() const
{
	return (m_UnitAddress == nullptr) ? nullptr : m_UnitAddress;
}

double Product::cost() const
{
	return (m_Taxable) ? m_PriceBeforeTax + (m_PriceBeforeTax * TAX_RATE) : m_PriceBeforeTax;
}

void Product::message(const char * address)
{
	m_er.message(address);
}

bool Product::isClear() const
{
	return (this->m_er.isClear()) ?  true :  false;
}

Product::Product(char type)
{
	m_ProductType = type;
	m_ProductSKU[0] = '\0';
	m_ProductUnit[0] = '\0';
	m_UnitAddress = nullptr;
	m_ProductQuantity = 0;
	m_ProductNeeded = 0;
	m_PriceBeforeTax = 0.0;
	m_Taxable = true;
	m_er;
}

Product::Product(const char * sku, const char * productName, const char * productUnit, int quantity, bool taxable, double priceBeforeTax, int qtyOfProductNeeded)
{
		snprintf(m_ProductSKU, MAX_SKU, "%s", sku);
		m_UnitAddress = nullptr;
		name(productName);
		snprintf(m_ProductUnit, MAX_UNIT_DESCRIPTOR, "%s", productUnit);
		m_ProductQuantity = quantity;
		m_Taxable = taxable;
		m_PriceBeforeTax = priceBeforeTax;
		m_ProductNeeded = qtyOfProductNeeded;
		m_er.clear();
}

Product::Product(const Product & other)
{
	*this = other;
}

Product & Product::operator=(const Product & other)
{
	if (&other == this) 
		return *this;

	m_ProductType = other.m_ProductType;
	snprintf(m_ProductSKU, MAX_SKU, "%s", other.m_ProductSKU);
	m_UnitAddress = nullptr;
	name(other.m_UnitAddress);
	snprintf(m_ProductUnit, MAX_UNIT_DESCRIPTOR, "%s", other.m_ProductUnit);
	m_ProductQuantity = other.m_ProductQuantity;
	m_ProductNeeded = other.m_ProductNeeded;
	m_PriceBeforeTax = other.m_PriceBeforeTax;
	m_Taxable = other.m_Taxable;
	if (!other.isClear())
	{
		m_er.message(other.m_er.message());
	}
	return *this;
}

Product::~Product()
{
	delete[] m_UnitAddress;
	m_UnitAddress = nullptr;
	m_er.clear();
}

std::fstream & Product::store(std::fstream & file, bool newLine) const
{
	if (file.is_open())
		file << m_ProductType << ',' << m_ProductSKU << ',' << m_UnitAddress << ',' << m_ProductUnit << ',' << m_ProductQuantity << "," << m_ProductNeeded << "," << m_PriceBeforeTax << "," << m_Taxable;
	if (newLine) 
		file << endl;
	return file;
}

std::fstream & Product::load(std::fstream & file)
{
	Product temp;
	temp.m_UnitAddress = new char[MAX_NAME_DESCRIPTOR + 1];
	if (file.is_open())
	{
		file >> temp.m_ProductType >> temp.m_ProductSKU >> temp.m_UnitAddress >> temp.m_ProductUnit >> temp.m_ProductQuantity >> temp.m_ProductNeeded >> temp.m_PriceBeforeTax >> temp.m_Taxable;
		*this = temp;
	}
	delete[] temp.m_UnitAddress;
	return file;
}

std::ostream & Product::write(std::ostream & os, bool linear) const
{
	// TODO: insert return statement here
	if (linear)				
	{
		os << "sku - " << setw(MAX_SKU) << m_ProductSKU << '|'
			<< "name - " << setw(20) << m_UnitAddress << '|'
			<< "cost - " << setw(97) << m_PriceBeforeTax << '|'
			<< "quantity - " << setw(4) << m_ProductQuantity << '|'
			<< "unit - " << setw(10) << m_ProductUnit << '|'
			<< "quantity needed - " << setw(4) << m_ProductNeeded << '|';
	}
	else
	{
		os << "Sku: " << m_ProductSKU << "|" << endl
			<< "Name: " << m_UnitAddress << "|" << endl
			<< "Price: " << m_PriceBeforeTax << "|" << endl;
		if (m_Taxable)
		{
			os << "Price after tax: " << m_PriceBeforeTax * (1 + TAX_RATE) << "|" << endl;
		}
		else os << "N/A" << "|" << endl;
		os << "Quantity On Hand: " <<m_ProductNeeded << "|" << endl
			<< "Quantity Needeed: " << m_ProductNeeded << "|" << endl;
	}
	return os;
}

std::istream & Product::read(std::istream & is)
{
	char sku[MAX_SKU + 1];
	char* productName;
	char unit[MAX_UNIT_DESCRIPTOR + 1];
	int quantity;
	int quantityNeeded;
	double price;
	char taxable[1];

	productName = new char[MAX_NAME_DESCRIPTOR + 1];
	
	cout << "Sku: ";
	is >> sku;
	cout << "Name: ";
	is >> productName;
	cout << "Unit: ";
	is >> unit;
	cout << "Taxed? (Y/N): ";
	is >> taxable;

	if (taxable[0] != 'y' && taxable[0] != 'Y' && taxable[0] != 'n' && taxable[0] != 'N')
	{
		m_er.message("Only(Y)es or (N)o are acceptable");
		is.setstate(std::ios::failbit);
	}

	cout << "Price: ";
	is >> price;

	if (is.fail())
	{
		m_er.message("Invalid Price Entry");
		is.setstate(std::ios::failbit);
	}

	cout << "Quantity on hand: ";
	is >> quantity;

	if (is.fail())
	{
		m_er.message("Invalid Quantity Entry");
		is.setstate(std::ios::failbit);
	}

	cout << "Quantity Needed: ";
	is >> quantityNeeded;

	if (is.fail())
	{
		m_er.message("Invalid Quantity Needed Entry");
	}

	if (m_er.isClear())
	{
		bool tax;
		if (taxable[0] == 'y' || taxable[0] == 'Y') 
			tax = true;
		else if (taxable[0] == 'n' || taxable[0] == 'N') 
			tax = false;
		snprintf(this->m_ProductSKU, MAX_UNIT_DESCRIPTOR, "%s", sku);
		name(productName);
		snprintf(this->m_ProductUnit, MAX_UNIT_DESCRIPTOR, "%s", unit);
		this->m_ProductQuantity = quantity;
		this->m_ProductNeeded = quantityNeeded;
		this->m_PriceBeforeTax = price;
		this->m_Taxable = tax;
	}

	delete[] productName;
	return is;
}

bool Product::operator==(const char * address) const
{
	return (strcmp(this->m_ProductSKU, address) != 0) ? false : true;
}

double Product::total_cost() const
{
	return (m_Taxable) ? static_cast<double>(m_ProductQuantity) * m_PriceBeforeTax * (1 + TAX_RATE) : static_cast<double>(m_ProductQuantity) * m_PriceBeforeTax;
}

void Product::quantity(int qtyProductsOnHand)
{
	this->m_ProductQuantity = qtyProductsOnHand;
}

bool Product::isEmpty() const
{
	return (m_ProductUnit == nullptr) ? true : false;
}

int Product::qtyNeeded() const
{
	return m_ProductNeeded;
}

int Product::quantity() const
{
	return m_ProductQuantity;
}

bool Product::operator>(const char * productSKU) const
{
	return (strcmp(productSKU, m_ProductSKU) > 0) ? true : false;
}

bool Product::operator>(const Product & other) const
{
	return (strcmp(m_UnitAddress, other.name()) > 0) ? true : false;
}

int Product::operator+=(int numUnitsToBeAdded)
{
	if (numUnitsToBeAdded > 0)
	{
		m_ProductQuantity += numUnitsToBeAdded;
		return m_ProductQuantity;
	}
	else return m_ProductQuantity;
}

std::ostream & operator<<(std::ostream & os, const Product & other)
{
	return other.write(os, true);
}

std::istream & operator>>(std::istream & is, Product & other)
{
	other.read(is);
	return is;
}

double operator+=(double & dbl, const Product & other)
{
	return dbl += other.total_cost();
}
