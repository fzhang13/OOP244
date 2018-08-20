/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: Jun 14th, 2018
 **********************************************************/

#include <iostream>
#include "Fraction.h"

using namespace std;

namespace sict{
    Fraction::Fraction(){
        m_numerator = -1;
        m_denominator = 0;
    }
    
    Fraction::Fraction(int num, int denom){
        if(num > -1 && denom > 0){
            m_numerator = num;
            m_denominator = denom;
            reduce();
        }else{
            *this = Fraction();
        }
    }
    
    int Fraction::max()const{
        if(m_numerator > m_denominator)
            return m_numerator;
        else
            return m_denominator;
    }
    int Fraction::min()const{
        if(m_numerator < m_denominator)
            return m_numerator;
        else
            return m_denominator;
    }
    void Fraction::reduce(){
        int div = gcd();
        m_numerator /= div;
        m_denominator /= div;
    }
    
    int Fraction::gcd()const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;
        
        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }
    
    bool Fraction::isEmpty()const{
        return (m_denominator == 0) ? true : false;
    }
    
    void Fraction::display()const{
        if(isEmpty()){
            cout << "no fraction stored";
        }else{
            if(m_denominator == 1){
                cout << m_numerator;
            }else{
                cout << m_numerator << "/" << m_denominator;
            }
        }
    }
    Fraction Fraction::operator+(const Fraction& n)const{
        Fraction newDiv;
        if(!isEmpty() && !n.isEmpty()){
            newDiv.m_numerator = m_denominator * n.m_numerator + m_numerator *
            n.m_denominator;
            
            newDiv.m_denominator = m_denominator * n.m_denominator;
        }
        return newDiv;
    }
    Fraction Fraction::operator*(const Fraction &n)const{
        Fraction newMult;
        if(!isEmpty()&& !n.isEmpty()){
            newMult.m_numerator= m_numerator * n.m_numerator;
            newMult.m_denominator= m_denominator * n.m_denominator;
        }
        return newMult;
    }
    bool Fraction::operator==(const Fraction &n)const{
        bool Ret= false;
        if(!isEmpty()){
            if((m_numerator*n.m_denominator)==(m_denominator*n.m_denominator)){
                Ret = true;
            }else{
                return false;
            }
        }
        return Ret;
    }
    
    bool Fraction::operator!=(const Fraction& n)const{
        bool Ret= false;
        if(!isEmpty()){
            if((m_numerator*n.m_denominator)!=(m_denominator*n.m_denominator)){
                Ret = true;
            }else{
                return false;
            }
        }
        return Ret;
    }
    Fraction& Fraction::operator+=(const Fraction& n){
        *this = *this + n;
        reduce();
        return *this;
    }
    

}
