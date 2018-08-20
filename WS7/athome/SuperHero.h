/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 11th, 2018
 **********************************************************/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
    class SuperHero : public Hero{
        int bonus;
        int defense;
    public:
        SuperHero();
        SuperHero(const char* name, int h, int a, int b, int d);
        int attackStrength() const;
        int defend() const;
    };
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}


#endif
