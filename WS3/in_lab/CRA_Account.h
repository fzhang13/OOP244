/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: May 31st, 2018
 **********************************************************/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
    const int max_name_length = 40;
    const int min_sin = 100000000;	    
    const int max_sin = 999999999;

    class CRA_Account{
            char m_familyName[max_name_length + 1];
            char m_givenName[max_name_length + 1];
            int m_sin;
        public:
            CRA_Account();
            void set(const char* familyName, const char* givenName, int sin);
            bool isEmpty() const;
            void display() const;
    };

}

#endif
