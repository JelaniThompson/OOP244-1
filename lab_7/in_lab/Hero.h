// Workshop 7 - Derived Classes
// File Hero.h
// Version 2.0
// Date 2018/03/19
// Author       Lean Junio
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////

#ifndef SICT_HERO_H
#define SICT_HERO_H 

namespace sict
{
    const int max_rounds = 100;

    class Hero
    {
    private:
        char m_Name[41];
        int m_Health;
        int m_Attack;
    public:
        Hero();
        Hero(const char* p_Name, int p_Health, int p_Attack);
        void operator-=(int p_Attack);
        bool isAlive() const;
        int attackStrength() const;
        const char* getName() const;
        int getHealth() const;
        friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    };
        const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !SICT_HERO_H 