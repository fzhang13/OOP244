/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 16th, 2018
 **********************************************************/

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"

namespace sict {
    class Account: public iAccount{
        double m_balance;
    protected:
        double balance()const;
    public:
        Account(double balance);
        bool credit(double add);
        bool debit(double sub);
    };
    iAccount* CreateAccount(const char* type, double balance);
}

#endif /* Account_hpp */
