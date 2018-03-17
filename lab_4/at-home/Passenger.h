// * Lean Junio
// * 2/12/2018
// * OOP244

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict
{

	class Passenger
	{
	private:
		char m_name[32];
		char m_dest[32];
		int m_year;
		int m_month;
		int m_day;

	public:
		Passenger(void);
		Passenger(const char *, const char*);
		Passenger(const char *, const char *, int, int, int);
		bool isEmpty(void) const;
		void display(void) const;
		const char* name(void) const;
		bool canTravelWith(const Passenger&) const;
	};
}

#endif
