/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 17th, 2018
 **********************************************************/

#include "ChequingAccount.h"

using namespace std;

namespace sict {
    ChequingAccount::ChequingAccount(double balance, double transaction, double monthfee):sict::Account(balance){
        (transaction > 0) ? m_transaction = transaction : m_transaction = 0.0;
        (monthfee > 0) ? m_monthFee = monthfee: m_monthFee =0.0;
    }
    
    bool ChequingAccount::credit(double add){
        Account::debit(m_transaction);
        return Account::credit(add);
    }
    
    bool ChequingAccount::debit(double sub){
        return Account::debit(sub + m_transaction);
    }
    
    void ChequingAccount::monthEnd(){
        Account::debit(m_monthFee + m_transaction);
    }
    
    void ChequingAccount::display(std::ostream& os)const{
 
        os << "Account type: Chequing" << endl;
        os.unsetf(ios::floatfield);
        os.precision(2);
        os.setf(ios::fixed, ios::floatfield);
        os << "Balance: $" << balance() << endl;
        os << "Per Transaction Fee: " << m_transaction << endl;
        os << "Monthly Fee: " << m_monthFee << endl;
    }
}
