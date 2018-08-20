/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 16th, 2018
 **********************************************************/

#include "SavingsAccount.h"

namespace sict {
    SavingsAccount::SavingsAccount(double balance, double interest):
    Account(balance){
        (interest > 0) ? m_interest = interest : m_interest = 0;
    }
    void SavingsAccount::monthEnd(){
        double interest = (balance()* m_interest);
        credit(interest);
    }
    void SavingsAccount::display(std::ostream&os) const{
        using namespace std;
        os << "Account type: Savings" << endl;
        os.unsetf(ios::floatfield);
        os.precision(2);
        os.setf(ios::fixed,ios::floatfield);
            os << "Balance: $" << balance() << endl;
            os << "Interest Rate (%): " << m_interest * 100 << endl;
    }
}
