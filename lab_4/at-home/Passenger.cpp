// * Lean Junio
// * 2/12/2018
// * OOP244

// TODO: add file header comments here
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;
// TODO: add your headers here

namespace sict
{
    // * Sets the object to a safe empty state
    Passenger::Passenger()
    {
        m_name[0] = '\0';
        m_dest[0] = '\0';
        m_year = 0;
        m_month = 0;
        m_day = 0;
    }

    // * If the data is valid - set departure date to july 1 2017
    Passenger::Passenger(const char* name, const char* destination)
    {
        bool nameInvalid = name == nullptr;
        bool destInvalid = destination == nullptr; 
        bool invalid = nameInvalid && destInvalid;

        if(!invalid)
        {
            m_year = 2017;
            m_month = 7;
            m_day = 1;
        }
    }

    // * Check if data is valid - copy data if true
    Passenger::Passenger(const char* name, const char* destination, int year, int month, int day)
    {
        bool yearValid = year >= 2017 && year <= 2020;
        bool monthValid = month >= 1 && month <= 12;
        bool dayValid = day >= 1 && day <= 31;

        if(name == nullptr || destination == nullptr || !yearValid || !monthValid || !dayValid)
        {
            *this = Passenger();
        }
        else
        {
            strcpy(m_name, name);
            strcpy(m_dest, destination);
            m_year = year;
            m_month = month;
            m_day = day;
        }
    }

    // * Check if current object is empty
    bool Passenger::isEmpty(void) const
    {
        bool valid = strlen(m_name) > 0 && strlen(m_dest) > 0 && m_day != 0 && m_month != 0 && m_year != 0;
        return !valid;
    }

    void Passenger::display(void) const
    {        
        // * If either name or dest is empty
        if(m_name[0] == '\0' || m_dest == '\0' || m_year == 0 || m_month == 0 || m_day  == 0)
        {
            cout << "No passenger!" << endl;
        }
        else
        {
	    if(m_month > 0 && m_month < 10)
            {
 		
            	cout << m_name << " - " << m_dest << " on " << m_year << "/0" << m_month << "/" << m_day << endl;
            }
	    else 
	    {
            	cout << m_name << " - " << m_dest << " on " << m_year << "/" << m_month << "/" << m_day << endl;
	    }
        }
    }

    // TODO: Create .name() method
    const char* Passenger::name(void) const
    {
        return m_name;
    }
    
    bool Passenger::canTravelWith(const Passenger& p) const
    {
        bool day = (*this).m_day == p.m_day;
        bool month = (*this).m_month == p.m_month;
        bool year = (*this).m_year == p.m_year;
        
        bool match = day && month && year;

        return match;
    }
}
