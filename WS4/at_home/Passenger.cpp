/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: Jun 7th, 2018
 **********************************************************/

#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict{
    Passenger::Passenger(){
        *m_name = '\0';
        *m_destination = '\0';
        m_year = 0;
        m_month = 0;
        m_day = 0;
    }
    
    Passenger::Passenger(const char* name, const char* destination){
        if(name != nullptr && destination != nullptr && name[0] != '\0'
           && destination[0] != '\0'){
            strncpy(m_name, name, 32);
            strncpy(m_destination, destination, 32);
            m_year = 2017;
            m_month = 7;
            m_day = 1;
        }else{
            *this = Passenger();
        }
    }
   
    Passenger::Passenger(const char* name, const char* destination, int y,
                         int m, int d){
          if(y >= 2017 && y <= 2020 && m >= 1 && m <= 12 && d >= 1 && d <= 31){
              *this = Passenger(name, destination);
              if (!isEmpty()){
                  m_year = y;
                  m_month = m;
                  m_day = d;
              }
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
    
    bool Passenger::canTravelWith(const Passenger& pass) const{
        return strcmp(pass.m_destination, m_destination) == 0 &&
        pass.m_year == m_year &&
        pass.m_month == m_month &&
        pass.m_day == m_day ? true : false;
    }
    
    const char* Passenger::name()const{
        return m_name;
    }
    
    void Passenger::display() const {
        if(isEmpty()){
            cout << "No Passenger!"<< endl;
        }
        cout << m_name << " - " << m_destination << " on " << m_year << "/";
        if(m_month < 10){
            cout << "0" << m_month << "/";
            if(m_day < 10){
                cout << "0" << m_day << endl;;
            }else{
                cout << m_day << endl;
            }
        }else{
            cout << m_month << "/" << m_day << endl;
        }
    }
}

