/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 10th, 2018
 **********************************************************/
// v2 .removed getName()-redundant

#include <iostream>
#include <cstring>
#include <string>
#include "Hero.h"

namespace sict{
    Hero::Hero(){
        name[0] = '\0';
        health = 0;
        attack = 0;
    }
    Hero::Hero(const char* n , int h, int a){
        bool validName = n != nullptr && n[0] != '\0';
        bool validHealth = h > 0;
        bool validAttack = a > 0;
        if (validName && validHealth && validAttack){
            strncpy(name, n, 41);
            health = h;
            attack = a;
        }else{
            *this = Hero();
        }
    }
    void Hero::operator-=(int attack){
        if(attack > 0 && health > 0){
            health -= attack;
        }if(health < 0){
            health = 0;
        }
    }
    bool Hero:: isAlive()const{
        return (health > 0) ? true : false;
    }
    int Hero::AttackStrength()const{
        if (attack >0)
            return attack;
        else
            return 0;
    }
    
    std::ostream& operator << (std::ostream& os, const Hero& hero){
        if(hero.name[0] != '\0' && hero.health > -1 && hero.attack > -1)
            os << hero.name;
        else
            os << "No hero";
        return os;
    }
    const Hero& operator*(const Hero& first, const Hero& second){
        using namespace std;
        Hero left = first, right = second, winner;
        int rounds = 0;
        
        for(int i = 0; i < max_rounds && (left.isAlive()) &&
            (right.isAlive()); ++i){
        left -= right.AttackStrength();
        right-= left.AttackStrength();
        rounds++;
        }
        if(left.isAlive() && !right.isAlive()){
            winner = left;
            cout << "Ancient Battle! " << first << " vs "
            << second <<" : Winner is " << winner << " in "
            << rounds << " rounds."<<endl;
            return first;
        }
        else if(!left.isAlive()){
            winner = right;
            cout << "Ancient Battle! " << first << " vs "
            << second <<" : Winner is " << winner<< " in "
            << rounds << " rounds."<<endl;
            return second;
        }
        else if(!right.isAlive()){
            winner = left;
            cout << "Ancient Battle! " << first << " vs "
            << second <<" : Winner is " << winner << " in "
            << rounds << " rounds." <<endl;
            return first;
        }else
            return first;
    }
    
}

