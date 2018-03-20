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

    ErrorState::~ErrorState()
    {
        delete[] m_MessageAddress;
        m_MessageAddress = nullptr;
    }

    void ErrorState::clear()
    {
        delete[] this->m_MessageAddress;
        m_MessageAddress = nullptr;
    }

    bool ErrorState::isClear() const
    {
        return (m_MessageAddress == nullptr) ? true : false;
    }

    void ErrorState::message(const char* str)
    {
        delete[] m_MessageAddress;
        m_MessageAddress = new char[strlen(str) + 1];
        strcpy(m_MessageAddress, str);
    }

    const char* ErrorState::message() const
    {
        return m_MessageAddress;
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