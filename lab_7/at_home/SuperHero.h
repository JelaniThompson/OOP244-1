// Name: Lean Junio
// Date: 3/21/2017
// File: SuperHero.h - Header file

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict
{
    class SuperHero : public Hero
    {
    private:
        int m_bonus;
        int m_defend;
    public:
        // Set SuperHero object to safe empty state 
        SuperHero();

        // Check to see if the paramters have valid values
        // If not, set the object to safe empty state
        SuperHero(const char* name, int health, int attack, int bonus, int defend);

        // Query: Returns the attack strength of the current object including its super power bonus
        // If the object is in an empty state, the function returns 0
        int attackStrength() const;

        // Query: Returns the defend strength of the current object
        // If the object is in a safe empty state, the function returns 0
        int defend() const;

    };
        // NON FRIEND:Returns a reference to the winner of the battle after max_rounds rounds
        // The function displays the names of the battle participants as shown in the sample output
        // The function also makes local copies of the participants
        // Determines the damage that each participant inflicts on the other in a single attack
        // Battles until either one of the participants dies or the maximum number of rounds
        const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_SUPERHERO_H
