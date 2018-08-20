/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 10th, 2018
 **********************************************************/

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {
    const int max_rounds = 100;
    class Hero{
    private:
        char name [41];
        int health;
        int attack;
    public:
        Hero();
        Hero(const char* n , int h, int a);
        void operator-=(int attack);
        bool isAlive()const;
        int AttackStrength()const;
        friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    };
    
    const Hero& operator*(const Hero& first, const Hero& second);
}

//removed getName()-redundant
#endif /* Hero_h */
