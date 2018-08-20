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
        *m_year = '\0';
        *m_balance = '\0';
        n_years = 0;
    }

    void CRA_Account::set(const char *familyName, const char *givenName, int sin)
    {
        strcpy(m_familyName, familyName);
        strcpy(m_givenName, givenName);
        m_sin = sin;
        if(isEmpty()){
            *m_givenName = '\0';
            *m_familyName = '\0';
            m_sin = 0;
            *m_year = '\0';
            *m_balance = '\0';
            n_years = 0;
        }
        int newSin = m_sin;
        int altNum[4];
        int sumOfDigit1[4];
        int sumOfDigit2[4];
        int lessThan10 = 0;
        int greaterThan10 = 0;
        int total1 = 0;
        int total2 = 0;
        int sinArr[9];
        for(int i = 0; i <= 9; ++i){
            sinArr[i] = newSin % 10;
            newSin /= 10;
        }
        
        altNum[0] = sinArr[7] * 2;
        altNum[1] = sinArr[5] * 2;
        altNum[2] = sinArr[3] * 2;
        altNum[3] = sinArr[1] * 2;
        
        
        for(int j = 0; j < 4; ++j){
            if(altNum[j] > 10){
                sumOfDigit1[j] = altNum[j] % 10 + 1;
                greaterThan10 += sumOfDigit1[j];
            }else if (altNum[j] == 10){
                sumOfDigit2[j] = 1;
                lessThan10 += sumOfDigit2[j];
            }else if (altNum[j] < 10){
                sumOfDigit2[j] = altNum[j];
                lessThan10 += sumOfDigit2[j];
            }
        }
        total1 = sinArr[8]+ sinArr[6]+ sinArr[4]+ sinArr[2];
        total2 = (greaterThan10 + lessThan10) + total1;
        
        int checkNumber = ((total2 /10 + 1) * 10) - total2;
        if (checkNumber != sinArr[0])
            m_sin = 0;
    
    }

    void CRA_Account::set(int year, double balance){
        if(!isEmpty()){
            m_year[n_years]= year;
            m_balance[n_years] = balance;
            n_years++;
        
        }
    }

    bool CRA_Account::isEmpty()const{
        bool trueFalse = true;
        if(m_sin >= max_sin || m_sin <= min_sin || *m_givenName == '\0' || *m_familyName == '\0'){
            trueFalse = true;
        }else{
            trueFalse = false;
        }
        return trueFalse;
    }

    void CRA_Account::display()const{
        if(!isEmpty()){
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
            if(*m_year != '\0' && *m_balance != '\0'){
                for(int i = 0; i < n_years; i++){
                    if(m_balance[i] > 2){
                        printf("Year (%d) balance owing: %.2lf\n",m_year[i], m_balance[i]) ;
                    }else if(m_balance[i] < -2){
                        printf("Year (%d) refund due: %.2lf\n", m_year[i], -(m_balance[i]));
                    }else{
                        cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;
                    }
                }
            }else{
                cout << "Account object is empty!" << endl;
            }
   	 }else{
            cout << "Account object is empty!" << endl;
         }
    }
}

