// Author: Lean Junio
// File: Data.h
// Description: Header file from Data
#include <iostream>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	template<typename T>
	T max(const T * data, int n)
	{
		// Initialize a max element
		T max = data[0];

		for (int i = 1; i < n; ++i)
		{
			if (data[i] > max)
				max = arr[i];
		}
		
		return max;
	}
	template<typename T>
	T min(const T * data, int n)
	{
		// Initialize a max element
		T min = data[0];

		for (int i = 1; i < n; ++i)
		{
			if (data[i] < max)
				min = arr[i];
		}
		
		return min;
	}
	template<typename T>
	T sum(const T * data, int n)
	{
		T sum;
		
		for (int i = 0; i < n; ++i)
		{
			sum += data[i];
		}

		return sum;
	}
	template<typename T>
	double average(const T * data, int n)
	{
		return sum(data, n)/n;
	}
	template<typename T>
	bool read(std::istream & input, T * data, int n)
	{
		// 1. Read from input
		// 2. Split input by comma and store them to data
		return false;
	}
	template<typename T>
	void display(const char * name, const T * data, int n)
	{
	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

