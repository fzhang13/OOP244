//
//  SavingsAccount.hpp
//  W8inlab
//
//  Created by Felix Zhang on 2018-07-16.
//  Copyright © 2018 Felix Zhang. All rights reserved.
//

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include <iostream>
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
