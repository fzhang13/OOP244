/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 16th, 2018
 **********************************************************/

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include "Account.h"

namespace sict {
    class SavingsAccount: public Account{
        double m_interest;
    public:
        SavingsAccount(double balance, double interest);
        void monthEnd();
        void display(std::ostream& os) const;
    };
}

#endif 
