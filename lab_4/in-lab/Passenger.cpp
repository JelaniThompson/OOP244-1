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
    }

    // * Check if data is valid - copy data if true
    Passenger::Passenger(const char* name, const char* destination)
    {
        if(name == nullptr || destination == nullptr)
        {
            *this = Passenger();
        }
        else
        {
            strcpy(m_name, name);
            strcpy(m_dest, destination);            
        }
    }

    // * Check if current object is empty
    bool Passenger::isEmpty(void) const
    {
        bool valid = strlen(m_name) > 0 && strlen(m_dest) > 0;
        return !valid;
    }

    void Passenger::display(void) const
    {        
        // * If either name or dest is empty
        if(m_name[0] == '\0' || m_dest == '\0')
        {
            cout << "No passenger!" << endl;
        }
        else
        {
            cout << m_name << " - " << m_dest << endl;
        }
    }
}
