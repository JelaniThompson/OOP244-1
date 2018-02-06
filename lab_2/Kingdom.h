/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 1/30/2018
// Author Lean Junio
// Description
// Kingdom Header File
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef HEADER_KINGDOM_H
#define HEADER_KINGDOM_H

// TODO: sict namespace
namespace sict {
// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};

	// TODO: declare the function display(...) also in the sict namespace
	void display(Kingdom& k);
}


#endif // !HEADER_KINGDOM_H





