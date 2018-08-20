/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 16th, 2018
 **********************************************************/

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>

namespace sict {
    class iAccount{
    public:
        virtual bool credit(double) = 0;
        virtual bool debit(double) = 0;
        virtual void monthEnd()= 0;
        virtual void display(std::ostream&) const= 0;
	virtual ~iAccount(){}
    };
    iAccount* CreateAccount(const char* type, double balance);
}

#endif /* iAccount_hpp */
