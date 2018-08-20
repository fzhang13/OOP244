/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: June 21st, 2018
 **********************************************************/


#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict{
    class Contact{
    private:
        char m_name[20];
        long long* m_pNumber;
        int m_nTelNumber;
    public:
        Contact();
        Contact(const char* name, long long* number, int n);
        ~Contact();
        bool isEmpty()const;
        void display()const;
    };
}

#endif
