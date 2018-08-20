//
//  Account.hpp
//  W8inlab
//
//  Created by Felix Zhang on 2018-07-12.
//  Copyright © 2018 Felix Zhang. All rights reserved.
//

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
