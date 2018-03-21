// Name: Lean Junio
// Date: 3/21/2017
// File: SuperHero.cpp - Implementation file

#include <iostream>
#include "SuperHero.h"

using namespace std;
using namespace sict;

namespace sict
{   
    // Set the object to empty state by calling the Hero() and manually setting the bonus
    SuperHero::SuperHero() : Hero()
    {
        m_bonus = 0;
        m_defend = 0;
    }

    // Check if the parameters are valid and then call parameter constructor from Hero
    // Apply the bonus right at the beginning
    SuperHero::SuperHero(const char* name, int health, int attack, int bonus, int defend) : Hero(name, health, attack)
    {
        m_bonus = bonus;
        m_defend = defend;
    }

    // If the attack strength is in safe empty state, return 0, else add the bonus
    int SuperHero::attackStrength() const
    {
        return Hero::attackStrength() != -1 ? Hero::attackStrength() + m_bonus : 0;
    }

    // Same logic as the attack strength
    int SuperHero::defend() const
    {
        return (m_defend != -1) ? m_defend : 0;    
    }

    // Add the bonus to the attacks of the superheroes
    // Call the operator from the other class
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
    {
        SuperHero left = first;
        SuperHero right = second;
        SuperHero winner;

        int round = 0;

        for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); ++i)
        {
            left -= right.attackStrength() - left.defend();
            right -= left.attackStrength() - right.defend();
            round = i;
        }

        round++;

        if (!left.isAlive() && !right.isAlive())
        {
            winner = left;
            cout << "Super Fight! " << first.getName() << " vs " << second.getName()
                 << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
            return first;
        }
        else if (!left.isAlive())
        {
            winner = right;
            cout << "Super Fight! " << first.getName() << " vs " << second.getName()
                 << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
            return second;
        }

        else if (!right.isAlive())
        {
            winner = left;
            cout << "Super Fight! " << first.getName() << " vs " << second.getName()
                 << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
            return first;
        }
        else
        {
            return first;
        }
    }
    

}