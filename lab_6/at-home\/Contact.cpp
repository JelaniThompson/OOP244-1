#include <iostream>
#include <string>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sict
{
	Contact::Contact()
	{
		m_ContactName[0] = '\0';
		m_PhoneNumbers = nullptr;
		m_NoPhoneNumbers = 0;
	}

	Contact::Contact(char* p_Name, long long* p_PhoneNumbers, int p_NoPhoneNumbers)
	{
		bool v_Name = p_Name != 0 && p_Name != nullptr;
		bool v_NoPhoneNumbers = p_NoPhoneNumbers >= 0;
		bool v_PhoneNumbers = p_PhoneNumbers != nullptr;
		
		// Check parameters
		if (v_Name && v_NoPhoneNumbers && v_PhoneNumbers)
		{
			// Copy the passed name
			strcpy(m_ContactName, p_Name);

			// Work on the numbers
			m_PhoneNumbers = new long long[p_NoPhoneNumbers];
			m_NoPhoneNumbers = 0;

			for (int i = 0; i < p_NoPhoneNumbers; ++i)
			{
				if (isValid(p_PhoneNumbers[i]))
				{
					m_NoPhoneNumbers += 1;
					m_PhoneNumbers[m_NoPhoneNumbers - 1] = p_PhoneNumbers[i];
				}
			}
		}
		else
		{
			*this = Contact();
		}
	}

	Contact::~Contact()
	{
		delete[] m_PhoneNumbers;
		m_PhoneNumbers = nullptr;
	}

	bool Contact::isEmpty() const
	{
		return m_ContactName[0] == '\0' && m_PhoneNumbers == nullptr && m_NoPhoneNumbers == 0;
	}

	void Contact::display() const
	{
		if (!this->isEmpty())
		{
			// Parse the phone numbers
			for (int i = 0; i < m_NoPhoneNumbers; ++i)
			{
				string c_PhoneString = to_string(m_PhoneNumbers[i]);
				int c_PhoneStringLength = c_PhoneString.length();

				string c_CountryCode = c_PhoneString.substr(0, (c_PhoneStringLength - (areaCodeLength + numberLength)));
				string c_AreaCode = c_PhoneString.substr(c_PhoneStringLength - (areaCodeLength + numberLength), areaCodeLength);
				string c_NumberCode1 = c_PhoneString.substr(c_PhoneStringLength - numberLength, numberCode1Length);
				string c_NumberCode2 = c_PhoneString.substr(c_PhoneStringLength - numberCode2Length, numberCode2Length);

				cout << "(+" + c_CountryCode + ")" + " " + c_AreaCode + " " + c_NumberCode1 + "-" + c_NumberCode2 << endl;
			}
		}
	}

	Contact& Contact::operator+=(const long long p_PhoneNumber)
	{
		long long* temp = new long long[m_NoPhoneNumbers];
		
		for (int i = 0; i < m_NoPhoneNumbers; ++i)
		{
			temp[i] = m_PhoneNumbers[i];
		}

		m_NoPhoneNumbers++;

		if (m_PhoneNumbers != nullptr)
		{
			delete[] m_PhoneNumbers;
			m_PhoneNumbers = nullptr;
		}

		m_PhoneNumbers = new long long[m_NoPhoneNumbers];
		for (int i = 0; i < m_NoPhoneNumbers; ++i)
		{
			m_PhoneNumbers[i] = temp[i];
		}

		m_PhoneNumbers[m_NoPhoneNumbers - 1] = p_PhoneNumber;
		delete[] temp;
		temp = nullptr;
		return *this;
	}

	void Contact::saveNumber(const long long p_PhoneNumber)
	{
		m_PhoneNumbers = new long long[m_NoPhoneNumbers + 1];

		for (int i = 0; i < m_NoPhoneNumbers; ++i)
		{
			m_PhoneNumbers[m_NoPhoneNumbers - 1] = p_PhoneNumber;
			m_NoPhoneNumbers++;
		}

	}

	// Check if a phone number is valid
	/*
	 - 1 - 2 Digits for country code (they can't be 0)
	 - exactly 3 digits for the area code which can't start with 0
	 - exactly 7 digits for the number (can't start with 0)
	*/
	bool Contact::isValid(long long p_PhoneNumber) const
	{
		string phoneString = to_string(p_PhoneNumber);
		int length = phoneString.length();
		bool v_PhoneString = p_PhoneNumber <= 0 && (length == 11 || length == 12 || phoneString[length - numberLength] != '0' || phoneString[length - 10] != '0');

		return v_PhoneString;
	}
}