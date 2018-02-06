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
namespace sict
{

// TODO:definition for display(...)
void display(Kingdom &k)
{
	cout << k.m_name << ", population " << k.m_population << endl;
}

void display(const Kingdom kArr[], int size)
{
	int totalPopulation = 0;

	for (int i = 0; i < size; i++)
	{
		totalPopulation += kArr[i].m_population;
	}

	cout << "------------------------------" << endl;
	cout << "Kingdoms are" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << kArr[i].m_name << ", population " << kArr[i].m_population << endl;
	}
	cout << "------------------------------" << endl;
	cout << "Total population of all Kingdoms: " << totalPopulation << endl;
	cout << "------------------------------" << endl;
}
}
