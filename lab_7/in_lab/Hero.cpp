// Workshop 7 - Derived Classes
// File Hero.cpp
// Version 2.0
// Date 2018/03/19
// Author       Lean Junio
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <string>
#include "Hero.h"
using namespace std;

namespace sict 
{
    Hero::Hero()
    {
        m_Name[0] = '\0';
        m_Health = 0;
        m_Attack = 0;
    }

    Hero::Hero(const char* p_Name, int p_Health, int p_Attack)
    {
        bool v_Name = p_Name != nullptr && p_Name[0] != '\0';
        bool v_Health = p_Health > 0;
        bool v_Attack = p_Attack > 0;

        if (v_Name && v_Health && v_Attack)
        {
            strcpy(m_Name, p_Name);
            m_Health = p_Health;
            m_Attack = p_Attack;            
        }
        else
        {
            *this = Hero();
        }
    }

    // Receives an attack strength
    // if p_Attack > 0
    // m_Health -= p_Attack
    // else, do nothing
    // If m_Attack is 0 or -, set m_Health to 0
    void Hero::operator-=(int p_Attack)
    {
        if (p_Attack > 0 && m_Health > 0)
        {
            m_Health -= p_Attack;

            if (m_Health < 0)
            {
                m_Health = 0;
            }            
        }
    }

    // Returns true if the object is health
    bool Hero::isAlive() const
    {
        return (m_Health > 0) ? true : false;
    }

    // return the attack strength of current object
    int Hero::attackStrength() const
    {
        if (m_Attack > 0)
            return m_Attack;
        else
            return 0;
    }

    const char* Hero::getName() const
    {
        return m_Name;
    }

    int Hero::getHealth() const
    {
        return m_Health;
    }
    
    // inserts the hero.m_Name into os
    // Return a reference to the stream
    // if hero.m_Name[0] = '\0'
    // display "No hero"
    std::ostream& operator<<(std::ostream& os, const Hero& hero)
    {
        if (hero.m_Name[0] != '\n' && hero.m_Health != -1 && hero.m_Attack != -1)
			os << hero.m_Name;
		else
			os << "No hero";
		return os;
    }

    // Returns a reference to the winner of the battle between the heroes
    // Display the names of the battle participants
    // Makes local copies of the participants
    // Determine the damage that each inflicts on the other in a single attack
    // Battle until one of them dies
    // Display the name of the winner
    // if draw, the first is the winner
    const Hero& operator*(const Hero& first, const Hero& second)
    {
        Hero left = first, right = second, winner;
        int round = 0;

        for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); ++i)
        {
            left -= right.attackStrength();
            right -= left.attackStrength();
            round = i;
        }

        round++;

        if (!left.isAlive() && !right.isAlive())
        {
            winner = left;
            cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
                 << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
            return first;
        }
        else if (!left.isAlive())
        {
            winner = right;
            cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
                 << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
            return second;
        }

        else if (!right.isAlive())
        {
            winner = left;
            cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
                 << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
            return first;
        }
        else
        {
            return first;
        }
    }
}