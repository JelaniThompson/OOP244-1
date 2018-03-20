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
            copyMessage(errorMessage);
        }
    }

    ErrorState::~ErrorState()
    {
        delete[] m_MessageAddress;
    }

    void ErrorState::clear()
    {
        delete[] m_MessageAddress;
        m_MessageAddress = nullptr;
    }

    bool ErrorState::isClear() const
    {
        return (m_MessageAddress != nullptr) ? true : false;
    }

    void ErrorState::message(const char* str)
    {
        if (m_MessageAddress != nullptr)
            delete[] m_MessageAddress;
        copyMessage(str);
    }

    const char* ErrorState::message() const
    {
        return this->m_MessageAddress;
    }

    std::ostream& operator<<(std::ostream& os, const ErrorState& em)
    {
        if (!em.isClear())
        {
            string copy = em.getAddress();
            string s = "test";
            os << copy;
        }

        return os;
    }

    string ErrorState::getAddress() const
    {
        return m_MessageAddress;
    }

    void ErrorState::copyMessage(const char* p_Message)
    {
        string s = p_Message;
        int size = (int)s.length();

        m_MessageAddress = new char[size];
        strncpy(m_MessageAddress, p_Message, size);
        m_MessageAddress[size] = '\0';
    }


}