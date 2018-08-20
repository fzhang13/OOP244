/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: May 31st, 2018
 **********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
    CRA_Account::CRA_Account(){
        m_sin = 0;
        *m_familyName = '\0';
        *m_givenName = '\0';
    }
   
    void CRA_Account::set(const char *familyName, const char *givenName, int sin){
        strcpy(m_familyName, familyName);
        strcpy(m_givenName, givenName);
        m_sin = sin;
        if(isEmpty()){
            *m_givenName = '\0';
            *m_familyName = '\0';
            m_sin = 0;
        }
    }
    
    bool CRA_Account::isEmpty()const{
        bool trueFalse;
        
        if(m_sin >= max_sin || m_sin <= min_sin){
            trueFalse = true;
        }
        else{
            trueFalse = false;
        }
        return trueFalse;
    }
    
    void CRA_Account::display()const{
        if(!isEmpty()){
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
        }
        else{
            cout << "Account object is empty!" << endl;
        }
    }
}
