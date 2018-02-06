/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 1/30/2018
// Author Lean Junio
// Description
// Kingdom Implementation File
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

using namespace std;
// TODO: the sict namespace
namespace sict {

	// TODO:definition for display(...) 
	void display(Kingdom& k)
	{
		cout << k.m_name << ", population " << k.m_population << endl;
	}

}