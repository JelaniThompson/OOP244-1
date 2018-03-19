#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict 
{
	const int areaCodeLength = 3;
	const int numberLength = 7;
	const int numberCode1Length = 3;
	const int numberCode2Length = 4;

	class Contact
	{
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
	public:
		Contact();
		Contact(const char*, const long long*, const int);
		~Contact();
		void display() const;
		bool isEmpty() const;
	public:
		Contact(const Contact& other);
		Contact& operator=(const Contact& rhs);
        Contact& operator+=(long long phoneNumber);

	private:
		bool isValidPhoneNumber(const long long);
	};
}
#endif
