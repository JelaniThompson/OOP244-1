// Workshop 6 - Class with a Resource
// Contact.cpp
// Lean Junio
// 2018/03/17

// ignore warning message
#define _CRT_SECURE_NO_WARNINGS


//insert header files
#include <iostream>
#include <cstring>
#include "Contact.h"


//using namespace
using namespace std;


//declare the namespace sict
namespace sict {

	//declare the constructor to initialize members
	Contact::Contact() {
		strncpy(memberName, "", MAX_CHARACTER_LENGTH);
		memberName[MAX_CHARACTER_LENGTH - 1] = '\0';
		phoneNumber = nullptr;
		phoneNumberNumber = 0;
	}

	//overload constructor with 3 parameters
	Contact::Contact(const char* personName, long long* pNumber, int noOfNumber) {

		// Check if the person name is empty
		if (personName != nullptr && strcmp(personName, "") != 0) {
			strncpy(memberName, personName, MAX_CHARACTER_LENGTH);
			memberName[MAX_CHARACTER_LENGTH - 1] = '\0';
			phoneNumberNumber = 0;

			if (pNumber != nullptr) {

				//allocating dynamic memory of array
				phoneNumber = new long long[noOfNumber];

				for (int i = 0; i < noOfNumber; i++) {

					// similar to ipc workshop of finding phone numbers
					int areaCode = (pNumber[i] / 10000000) % 1000;
					if (areaCode == 416) {
						phoneNumber[phoneNumberNumber] = pNumber[i];
						phoneNumberNumber++;
					}
				}
			}
			else {
				phoneNumber = nullptr;
			}
		}

		//if the condition doesn't match, return to the default constructor
		else {
			phoneNumber = nullptr;
			*this = Contact();
		}
	}

	//deallocate of phonnumber array
	Contact::~Contact() {
		delete[] phoneNumber;
	}
	bool Contact::isEmpty() const {
		bool check = false;
		if (strcmp(memberName, "") == 0 && phoneNumber == nullptr && phoneNumberNumber == 0) {
			check = true;
		}
		return check;
	}

	// display function
	void Contact::display() const {

		long long fullPnumber;
		int count = 0;

		//No record, then show this message
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}

		else {
			cout << memberName << endl;

			while (count != phoneNumberNumber) {
				fullPnumber = phoneNumber[count];
				cout << "(+" << (fullPnumber / 10000000000) << ") " << ((fullPnumber / 10000000) % 1000) << " " << ((fullPnumber % 10000000) / 10000) << "-" << (fullPnumber % 10000) << endl;
				count++;
			}
		}
	}


	//  copy constructor 
	Contact::Contact(const Contact& cpyconstructor) {

		phoneNumber = nullptr;

		// Using the same code again for copy assignment operator

		*this = cpyconstructor;
	}


	// cpy assignment operator
	Contact& Contact::operator=(const Contact& tempObject2) {

		// To save the data, I need to check if the object is the same or address
		if (this != &tempObject2) {

			// initialize the instance variables
			strncpy(memberName, tempObject2.memberName, MAX_CHARACTER_LENGTH);
			memberName[MAX_CHARACTER_LENGTH - 1] = '\0';
			phoneNumberNumber = tempObject2.phoneNumberNumber;

			//deallocate the memory of phoneNumber
			delete[] phoneNumber;
			if (tempObject2.phoneNumber != nullptr) {
				phoneNumber = new long long[phoneNumberNumber];

				// Set the object to given object which is tempObject2 
				int i = 0;
				while (i < phoneNumberNumber) {
					phoneNumber[i] = tempObject2.phoneNumber[i];
					i++;
				}
			}

			else {
				phoneNumber = nullptr;
			}
		}

		return *this;
	}

	// +=operator
	Contact& Contact::operator+=(long long longPnumber) {

		// check for phoneNumber is not empty
		if (phoneNumber != nullptr) {

			//increase the size of new array for allocation memory(pointer)
			long long* contact = new long long[phoneNumberNumber + 1];
			for (int i = 0; i < phoneNumberNumber; i++) {
				contact[i] = phoneNumber[i];
			}

			// put one data to new array(ponter)
			contact[phoneNumberNumber] = longPnumber;
			phoneNumberNumber++;

			//dealocate the memory
			delete[] phoneNumber;

			//set the array data into new array
			phoneNumber = contact;
		}
		else {
			//allocating the new dynamic memory if phoneNumber is nullptr with one more increased size of array(pointer)
			phoneNumber = new long long[phoneNumberNumber + 1];
			phoneNumber[phoneNumberNumber] = longPnumber;
			phoneNumberNumber++;
		}

		return *this;
	}

}