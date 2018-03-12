#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict
{
	// Set to safe empty states
	Contact::Contact()
	{
		m_name[0] = '\0';
		m_noOfPhoneNumbers = 0;
		m_phoneNumbers = nullptr;
	}

	Contact::Contact(const char* name, const long long* phoneNumbers, const int noOfPhoneNumbers)
	{
		bool valid = name && phoneNumbers != nullptr && noOfPhoneNumbers > 0;

		if (valid)
		{
			strcpy(m_name, name);
		}
	}
	Contact::~Contact()
	{
	}
}