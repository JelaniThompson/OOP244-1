// Author: Lean Junio
// File: Data.h
// Description: Header file from Data
#include <iostream>

namespace sict {

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	int min(const int* data, int n);

	// Returns the largest item in the array passed
	// 
	// Initialize to the first element of the array
	// Loop through each element of the array...
	// If the current element of the array is bigger than 'max'
	// move the current element to the beginning of the array
	// return the 
	template<typename T>
	T max(const T * data, int n)
	{
		// Initialize a max element
		T max = data[0];

		for (int i = 1; i < n; ++i)
		{
			if (max < data[i])
				max = data[i];
		}
		
		return max;
	}

	// Returns the smaller item in the array
	// 
	// Initialize the template element to the first element of the array
	// Loop through the array
	// If the template element is bigger than the current element
	// Let 'min' get the value of the smaller valued element
	// Return the template element
	template<typename T>
	T min(const T * data, int n)
	{
		// Initialize a max element
		T min = data[0];

		for (int i = 1; i < n; ++i)
		{
			if (min > data[i])
				min = data[i];
		}
		
		return min;
	}

	// Returns the sum of all items within the array
	// 
	// Initialize the sum template variable
	// Loop through the elements 
	// Keep adding each array element value to sum
	template<typename T>
	T sum(const T * data, int n)
	{
		T sum = 0;
		
		for (int i = 0; i < n; ++i)
		{
			sum += data[i];
		}

		return sum;
	}

	// Return the average of all the data elements
	// 
	// Sum of data / n
	template<typename T>
	double average(const T * data, int n)
	{
		return sum(data, n)/n;
	}

	// Reads the input into data
	// 
	// Declare a T element that stores the initial element from the array
	template<typename T>
	bool read(std::istream & input, T * data, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			// Ignore 1 character by default
			input.ignore();

			// take the input into the current element of the array data
			input >> data[i];

			// if the input process fails, return false
			if (input.fail())
			{
				return false;
			}
		}
		return true;
	}

	// Displays the name and data
	template<typename T>
	void display(const char * name, const T * data, int n)
	{
		// Set Width and justify to the right
		std::cout.width(20);
		std::cout << std::right << name;
		std::cout.width(20);

		for(int i = 0; i < n; ++i)
		{
			std::cout << data[i] << " ";
			std::cout.width(15);
		}

		std::cout << "\n";
	}

	template<typename T>
	T readRow(std::istream& fileInput, const char* name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !fileInput.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			fileInput.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				fileInput.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(fileInput, data, n);

		// finish the line
		fileInput.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

