/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 17th, 2018
 **********************************************************/


#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sict {
    class ChequingAccount: public Account{
        double m_transaction;
        double m_monthFee;
    public:
        ChequingAccount(double balance, double transaction, double monthfee);
        bool credit(double add);
        bool debit(double sub);
        void monthEnd();
        void display(std::ostream&) const;

	};
}
#endif
