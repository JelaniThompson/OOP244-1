// Author: Lean Junio
// Date: 3/19/2018
// Description: Header file for ErrorState module

#ifndef AMA_ERROR_STATE_H
#define AMA_ERROR_STATE_H
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

namespace AMA
{
    class ErrorState
    {
        char* m_MessageAddress;

        // Copies the message
        void copyMessage(const char* p_Message);

    public:
        // Receives the ADDRESS of a null terminated string that holds an error message
        // If the address is NULLPTR, this function puts the object in a safe empty state
        // If the address points to a non-empty message, this function allocates memory for that message
        // Then, copies the message into the allocatd memory
        explicit ErrorState(const char* errorMessage = nullptr);

        // A deleted copy constructor prevents copying of any ErrorState object
        ErrorState(const ErrorState& em) = delete;

        // A deleted assignment (=) operator prevents assignment of any ErrorState object to the current object
        ErrorState& operator=(const ErrorState& em) = delete;

        // This function deallocates any memory that has been dynamically allocated by the current object
        virtual ~ErrorState();

        // This function cleans any messaage stored by the current object and initializes the object to a safe empty state
        void clear();

        // This query report returns true if the object is in a safe empty state
        bool isClear() const;

        // Stores a copy of the string point to by str
        // Deallocates any memory allocated for a previously stored message
        // Allocates the dynamic memory needed to store a copy of str
        // Copies the string at address str to the allocated memory
        void message(const char* str);

        // This query returns the address of the message stored in the current object
        const char* message() const;

        // Return the address of the current object
        string getAddress() const;
    };

    // Sends an ErrorState message
    // If one exists to an ostream object
    // Return a reference to the ostream object
    // If no message exists, the operator shoudld not send anything to ostream
    // Instead, return a reference to the ostream object
    std::ostream& operator<<(std::ostream& os, const ErrorState& em);
}

#endif // !AMA_ERROR_STATE_H