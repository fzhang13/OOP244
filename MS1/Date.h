/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 3rd, 2018
 **********************************************************/



#ifndef AMA_DATE_H
#define AMA_DATE_H
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace AMA {
    const int min_year = 2000;
    const int max_year = 2030;
 
    
    class Date {
        int year;
        int month;
        int day;
        int comp;
        int errorState;
        int mdays(int, int)const;
        void errCode(int errorCode);
    public:
        Date();
        Date(int year, int month, int day);
        int value()const;
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        int errCode()const;
        bool bad()const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        
    };
    std::istream& operator >> (std::istream&, Date&);
    std::ostream& operator << (std::ostream&, Date&);
}
#endif
