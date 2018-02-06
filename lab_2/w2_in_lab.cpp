/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 2.0
// Date 1/30/2018
// Author Lean Junio
// Description
// Main Implementation File
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {

	// the number of kingdoms in the array
	int count = 0;

	// TODO: declare the pKingdom pointer here (don't forget to initialize it)
	Kingdom* pKingdom = nullptr;

	cout << "==========\n"
		 << "Input data\n"
		 << "==========\n"
		 << "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	// TODO: allocate dynamic memory here for the pKingdom pointer
	pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		// TODO: add code to accept user input for Kingdom i
		Kingdom& readKingdom = pKingdom[i];
		read(readKingdom);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// TODO: deallocate the dynamic memory here
	delete [] pKingdom;
	pKingdom = nullptr;

	return 0;
}

// read accepts data for a Kingdom from standard input
void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
