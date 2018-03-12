#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	class Contact
	{
		// Stores the name of the contact
		char m_name[20];

		// Pointer to dynamically alocated array of numbers
		long long* m_phoneNumbers;

		// Number of phone numbers currently stored in the array
		int m_noOfPhoneNumbers;
	public:
		Contact();
		Contact(const char*, const long long*, const int);
		~Contact();
		void display() const;
		bool isEmpty() const;
		Contact(const Contact& other) = delete;
		Contact& operator=(const Contact& other) = delete;

	private:
		bool isValidPhoneNumber(const long long);
	};
}
#endif
