#include <iostream>
#include <cstring>
#include "Data.h"
using namespace std;

namespace sict {
	
	// A custom function for reading ints on min
	int min(const int* data, int n) {
		int min = LARGEST_NUMBER;
		for (int i = 0; i < n; ++i) {
			if (data[i] < min)
				min = data[i];
		}
		return min;
	}
	
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//
	// bool readRow(std::istream& input, const char* name, double* data, int n) {
	// 	char rowname[2000];
	// 	bool ok = !input.bad();

	// 	// row format is 
	// 	// name,1,2,3,4,5,6

	// 	if (ok) {
	// 		// read the name  first

	// 		input.get(rowname, 2000, ',');
	// 		// note: get will read a string upto the , character
	// 		// it will leave the , character in the input buffer 

	// 		// check that the caller is reading the correct row (name)
	// 		// - if the user is reading the wrong row, return an error
	// 		if (std::strcmp(rowname, name) != 0) {
	// 			// wrong row
	// 			std::cout << "Cannot parse row for " << name << std::endl;
	// 			input.ignore(2000, '\n');
	// 			ok = false;
	// 		}
	// 	}

	// 	if (ok)
	// 		// read the data array
	// 		ok = read(input, data, n);

	// 	// finish the line
	// 	input.ignore(2000, '\n');
	// 	return ok;
	// }

	// bool readRow(std::istream& input, const char* name, int* data, int n) {
	// 	char rowname[2000];
	// 	bool ok = !input.bad();

	// 	// row format is 
	// 	// name,1,2,3,4,5,6

	// 	if (ok) {
	// 		// read the name  first

	// 		input.get(rowname, 2000, ',');
	// 		// note: get will read a string upto the , character
	// 		// it will leave the , character in the input buffer 

	// 		// check that the caller is reading the correct row (name)
	// 		// - if the user is reading the wrong row, return an error
	// 		if (std::strcmp(rowname, name) != 0) {
	// 			// wrong row
	// 			std::cout << "Cannot parse row for " << name << std::endl;
	// 			input.ignore(2000, '\n');
	// 			ok = false;
	// 		}
	// 	}

	// 	if (ok)
	// 		// read the data array
	// 		ok = read(input, data, n);

	// 	// finish the line
	// 	input.ignore(2000, '\n');
	// 	return ok;
	// }

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime, const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int populationDiff = population[n - 1] - population[0];

		// Output for the population
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << static_cast<double>(populationDiff)/1000000 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		auto violentCrimeStart = violentCrime[0];
		auto violentCrimeEnd = violentCrime[n - 1];
		const char *trend = violentCrimeStart < violentCrimeEnd ? "up" : "down";
		cout << "Violent Crime trend is " << trend << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		double gtaMillions = 0; // tyour code goes here
		cout << "There are ";
		gtaMillions = average(grandTheftAuto, n);
		cout.precision(2);
		cout << fixed <<
			gtaMillions / 1.0E6
			<< " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;
	}
}