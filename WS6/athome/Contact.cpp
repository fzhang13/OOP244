/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 1st, 2018
 **********************************************************/


#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict{
    Contact::Contact(){
        m_name[0] = '\0';
        m_pNumber= nullptr;
        m_nTelNumber = 0;
    }
    
    Contact::Contact(const char* name, long long* number, int n){
        if(name!= nullptr){
            if(*name){
                strncpy(m_name, name, 19);
                m_nTelNumber = n;
                if(m_nTelNumber > 0){
                    long long* num = new long long[m_nTelNumber];
                    for(int i= 0;i<m_nTelNumber; ++i){
                        num[i] = number[i];
                    }
                    m_pNumber = num;
                }else{
                    m_pNumber = nullptr;
                }
            }else{
                *this = Contact();
            }
        }else{
            *this = Contact();
        }
    }
    Contact::~Contact(){
        delete [] m_pNumber;
        m_pNumber = nullptr;
    }
    bool Contact::isEmpty()const{
        bool res = false;
        if (m_name[0]=='\0'){
            res = true;
        }
        else{
            res = false;
        }
        return res;
    }
    
    void Contact::display()const{
        if(isEmpty()){
            cout << "Empty contact!" << endl;
        }else{
            cout << m_name << endl;
            for(int i = 0; i < m_nTelNumber ; ++i){
                long long a = m_pNumber[i];
                long long validNumber;
                int last;
                int b= 10000000;
                int c = int(a/b);
                int d,e;
                if(c>1001 && c< 99999){
                    cout.fill('0');
                    e = c % 1000;
                    d = c / 1000;
                    validNumber = a % 1000000;
                    int temp = (int)(a/10000);
                    int first = temp %1000;
                    last = (int)(validNumber % 10000);
                    cout << "(+" << d << ")" << " " << e << " " << setw(3)<<first
                    << "-" << setw(4) << last << endl;
                }
            }
        }
    }
    Contact::Contact(const Contact& C){
        if(!isEmpty()){
            strncpy(m_name, C.m_name, 19);
            m_nTelNumber = C.m_nTelNumber;
            if(m_nTelNumber > 0){
                long long *p = new long long[m_nTelNumber];
                for(int i = 0; i < m_nTelNumber; ++i){
                    p[i] = C.m_pNumber[i];
                }
                m_pNumber = p;
            }else{
                m_pNumber = nullptr;
            }
        }else{
            *this = Contact();
        }
    }
    
    Contact& Contact::operator=(const Contact &C){
        if(this != &C){
            if(m_pNumber != nullptr){
                m_pNumber = nullptr;
                delete [] m_pNumber;
            }
            m_nTelNumber = C.m_nTelNumber;
            strncpy(m_name, C.m_name, 19);
            m_pNumber = new long long[m_nTelNumber];
            for(int i=0; i < m_nTelNumber; ++i){
                m_pNumber[i] = C.m_pNumber[i];
            }
        }
        return *this;
    }
    Contact& Contact::operator+=(const long long pNumber){
        long long *tmp = new long long[m_nTelNumber+1];
        for(int i =0; i < m_nTelNumber; ++i){
            tmp[i] = m_pNumber[i];
        }
        m_nTelNumber++;
        if(m_pNumber != nullptr){
            delete [] m_pNumber;
        }
        m_pNumber = new long long[m_nTelNumber];
        for(int j =0; j < m_nTelNumber; ++j){
            m_pNumber[j] = tmp[j];
        }
        m_pNumber[m_nTelNumber - 1] = pNumber;
        delete [] tmp;
        return *this;
    }
}
