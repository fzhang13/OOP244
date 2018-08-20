/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 17th, 2018
 **********************************************************/

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {
    const double interest = 0.05;
    const double transaction = 0.50;
    const double monthly = 2.00;
    
    iAccount* CreateAccount(const char* type, double balance){
        iAccount *p = nullptr;
        if(type[0] == 'S') {
            p = new SavingsAccount(balance, interest);
        }else if(type[0] == 'C') {
            p = new ChequingAccount(balance, transaction, monthly);
        }
        return p;
    }
}
