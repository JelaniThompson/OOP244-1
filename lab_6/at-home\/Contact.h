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
	private:
		char m_ContactName[20];
		long long* m_PhoneNumbers;
		int m_NoPhoneNumbers;
	public:
		Contact();
		Contact(char* p_Name, long long* p_PhoneNumbers, int p_NoPhoneNumbers);
		~Contact();
		bool isEmpty() const;
		void display() const;
	private:
		bool isValid(long long p_PhoneNumber) const;
		void saveNumber(const long long p_PhoneNumber);
	public:
		Contact& operator+=(const long long p_PhoneNumber);
	};
}

#endif