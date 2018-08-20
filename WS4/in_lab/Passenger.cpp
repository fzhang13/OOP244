/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: Jun 6th, 2018
 **********************************************************/
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict{
    Passenger::Passenger(){
        *m_name = '\0';
        *m_destination = '\0';
    }
    
    Passenger::Passenger(const char* name, const char* destination){
        if(name != nullptr && destination != nullptr && name[0] != '\0'
           && destination[0] != '\0'){
            strncpy(m_name, name, 32);
            strncpy(m_destination, destination, 32);
        }else{
           *this = Passenger();
        }
    }
    
    bool Passenger::isEmpty()const{
        if(*m_name && *m_destination){
            return false;
        }
        return true;
    }
    
    void Passenger::display() const {
        if(isEmpty())
            cout << "No passenger!"<< endl;
        else
            cout << m_name << " - " << m_destination << endl;
    }
}

