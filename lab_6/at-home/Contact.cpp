#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict
{
	// Checks if the passed phoneNumber is valid
	bool Contact::isValidPhoneNumber(const long long phoneNumber)
	{
		string phoneNumberString = to_string(phoneNumber);
		bool invalid = phoneNumber <= 0 || phoneNumberString.length() < 11 || phoneNumberString.length() > 12 || phoneNumberString[phoneNumberString.length() - 7] == '0' || phoneNumberString[phoneNumberString.length() - 10] == '0';
		return !invalid;
	}

	bool Contact::isEmpty() const
	{
		return m_name[0] == '\0';
	}

	// Set to safe empty states
	Contact::Contact()
	{
		m_name[0] = '\0';
		m_noOfPhoneNumbers = 0;
		m_phoneNumbers = nullptr;
	}

	// Gets the data when the object is created: name, phoneNumbers, number of phoneNumbers in the array
	Contact::Contact(const char* name, const long long* phoneNumbers, const int noOfPhoneNumbers)
	{
		// Check if the incoming name is null or empty
        bool v_Name = name != nullptr && strlen(name) != 0;

		if (v_Name)
		{
			// Copy the passed data into m_name
			strcpy(m_name, name);

			// Allocate new memory
			m_phoneNumbers = new long long[noOfPhoneNumbers];
			m_noOfPhoneNumbers = 0;

			// Check for valid numbers
			for	(int i = 0; i < noOfPhoneNumbers; i++)
			{
				// If the current phoneNumbers element is valid
				if (isValidPhoneNumber(phoneNumbers[i]))
				{
					// increase the m_noOfPhoneNumbers by 1
					m_noOfPhoneNumbers += 1;

					// Copy the valid phoneNumber into the m_phoneNumbers
					m_phoneNumbers[m_noOfPhoneNumbers - 1] = phoneNumbers[i];
				}
                else
                {
                    m_phoneNumbers[i] = 0;
                }
			}
		}
		else
		{
			*this = Contact();
		}
	}

	void Contact::display() const{
		string countryCode;
		string areaCode;
		string numberCode1;
		string numberCode2;
		string phoneNumberString;
		int phoneNumberStringLength;
		if (!isEmpty()) {
		
			cout << m_name << endl;
			for (int phone = 0; phone < m_noOfPhoneNumbers; phone++) {
				phoneNumberString = to_string(m_phoneNumbers[phone]);
				phoneNumberStringLength = phoneNumberString.length();
				countryCode = phoneNumberString.substr(0, (phoneNumberStringLength - (areaCodeLength + numberLength)));
				areaCode = phoneNumberString.substr(phoneNumberStringLength - (areaCodeLength + numberLength), areaCodeLength);
				numberCode1 = phoneNumberString.substr(phoneNumberStringLength - numberLength, numberCode1Length);
				numberCode2 = phoneNumberString.substr(phoneNumberStringLength - numberCode2Length, numberCode2Length);
				
				cout << "(+" + countryCode + ")" + " " + areaCode + " " + numberCode1 + "-" + numberCode2 << endl;			
			}
		}
		else 
		{
			cout << "Empty contact!" << endl;
		}
    }

	Contact::~Contact()
	{
		// Deallocate the m_phoneNumbers
		if (m_phoneNumbers != nullptr)
		{
			delete[] m_phoneNumbers;
			m_phoneNumbers = nullptr;
		}
	}

    Contact::Contact(const Contact& other)
    {
        m_phoneNumbers = nullptr;
        *this = other;
    }

    Contact& Contact::operator=(const Contact& rhs)
    {
        if (this != &rhs) 
        {
            strcpy(m_name, rhs.m_name);
            m_noOfPhoneNumbers = rhs.m_noOfPhoneNumbers;
            delete[] m_phoneNumbers;

            if (rhs.m_phoneNumbers != nullptr) {
                m_phoneNumbers = new long long[m_noOfPhoneNumbers];
                for (int i = 0; i < m_noOfPhoneNumbers; i++) {
                m_phoneNumbers[i] = rhs.m_phoneNumbers[i];
                }
            }
            else 
            {
                m_phoneNumbers = nullptr;
            }
        }

        return *this;
    }

    Contact& Contact::operator+=(long long phoneNumber)
    {
        bool valid = isValidPhoneNumber(phoneNumber);

        if (valid)
        {
            m_noOfPhoneNumbers++;
            
            long long* t_PhoneNumbers = new long long[m_noOfPhoneNumbers];

            for (int i = 0; i < m_noOfPhoneNumbers - 1; ++i)
            {
                t_PhoneNumbers[i] = m_phoneNumbers[i];
            }

            t_PhoneNumbers[m_noOfPhoneNumbers - 1] = phoneNumber;
            delete[] m_phoneNumbers;
            m_phoneNumbers = t_PhoneNumbers;
        }

        return *this;
    }

}