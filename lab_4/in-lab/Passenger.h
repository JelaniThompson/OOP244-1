// TODO: add file header comments here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict
{

	class Passenger
	{
	private:
		char m_name[32];
		char m_dest[32];

	public:
		Passenger(void);
		Passenger(const char *, const char *);
		bool isEmpty(void) const;
		void display(void) const;
	};
}

#endif
