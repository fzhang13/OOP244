/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 11th, 2018
 **********************************************************/

#include <iostream>
#include "SuperHero.h"

namespace sict{
    SuperHero::SuperHero():Hero(){
        bonus = 0;
        defense = 0;
    }
    SuperHero::SuperHero(const char* name, int h, int a, int b, int d):Hero
    (name, h, a){
        bonus = b;
        defense = d;
    }
    int SuperHero::attackStrength() const{
        return Hero::AttackStrength() > -1 ? Hero::AttackStrength()+ bonus : 0;
    }
    int SuperHero::defend()const{
        return SuperHero::defense > -1 ? SuperHero::defense : 0;
    }
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
        using namespace std;
        SuperHero left = first;
        SuperHero right = second;
        SuperHero winner;
        
        int rounds = 0;
        
        for(int i = 0; i < max_rounds && (left.isAlive()) &&
            (right.isAlive()); ++i){
            left -= right.attackStrength() - left.defend();
            right -= left.attackStrength() - right.defend();
            rounds = i;
        }
        rounds ++;
        if(left.isAlive() && !right.isAlive()){
            winner = left;
            cout << "Super Fight! " << first << " vs "
            << second <<" : Winner is " << winner << " in "
            << rounds << " rounds."<<endl;
            return first;
        }
        else if(!left.isAlive()){
            winner = right;
            cout << "Super Fight! " << first << " vs "
            << second <<" : Winner is " << winner<< " in "
            << rounds << " rounds."<<endl;
            return second;
        }
        else if(!right.isAlive()){
            winner = left;
            cout << "Super Fight! " << first << " vs "
            << second <<" : Winner is " << winner << " in "
            << rounds << " rounds." <<endl;
            return first;
        }else
            return first;
    }
    
}
