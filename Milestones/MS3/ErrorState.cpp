// Author: Lean Junio
// Date: 3/19/2018
// Description: Implmentation file for ErrorState module

#include <iostream>
#include <cstring>
#include <string>
#include "ErrorState.h"
using namespace std;

namespace AMA
{
    // receives the address of a C-style null terminated string that holds an error message
    ErrorState::ErrorState(const char* errorMessage)
    {
        if (errorMessage == nullptr)
        {
            m_MessageAddress = nullptr;
        }
        else
        {
            m_MessageAddress = new char[strlen(errorMessage) + 1];
            strcpy(m_MessageAddress, errorMessage);
        }
    }

    // de-allocates any memory that has been dynamically allocated by the current object
    ErrorState::~ErrorState()
    {
        delete[] m_MessageAddress;
        m_MessageAddress = nullptr;
    }

    // clears any message stored by the current object and initializes the object to a safe empty state
    void ErrorState::clear()
    {
        delete[] this->m_MessageAddress;
        m_MessageAddress = nullptr;
    }

    // returns true if the current object is in a safe empty state
    bool ErrorState::isClear() const
    {
        return (this->m_MessageAddress == nullptr) ? true : false;
    }

    // stores a copy of the C-style string pointed to by str
    void ErrorState::message(const char* str)
    {
        int strLength = strlen(str);
        m_MessageAddress = new char[strLength + 1];
        strncpy(m_MessageAddress, str, strLength);
        m_MessageAddress[0] = '\0';
    }

    // returns the address of the message stored in the current object.
    const char* ErrorState::message() const
    {
        return this->m_MessageAddress;
    }

    std::ostream& operator<<(std::ostream& os, const ErrorState& em)
    {
        if (!em.isClear())
        {
            os << em.message();
        }
        return os;
    }
}