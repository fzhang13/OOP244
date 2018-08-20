/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 16th, 2018
 **********************************************************/

#include "Account.h"

namespace sict {
    Account::Account(double balance){
        (balance) ? m_balance = balance : m_balance = 0.0;
    }
    bool Account:: credit(double add){
        if (add > 0){
            m_balance += add;
            return true;
        }else{
            return false;
        }
    }
    bool Account::debit(double sub){
        if (sub > 0){
            m_balance -= sub;
            return true;
        }else{
            return false;
        }
    }
    double Account::balance()const{
        return m_balance;
    }
}
