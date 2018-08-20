/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 3rd, 2018
 **********************************************************/

#include <iostream>
#include <iomanip>
#include "Date.h"

namespace AMA {
    Date::Date(){
        year = NO_ERROR;
        month = NO_ERROR;
        day = NO_ERROR;
        comp = NO_ERROR;
        errorState = NO_ERROR;
    }
    Date::Date(int y, int m, int d){
        int getValidDay = mdays(m, y);
        if(m > 0 && m < 13 && d <= getValidDay && y >= min_year &&
           y <= max_year){
        year = y;
        month = m;
        day = d;
        errorState = NO_ERROR;
        comp = value();
        }else{
            *this = Date();
        }
        
    }
    int Date::value()const{
        return year * 372 + month * 13 +day;
    }
    int Date::errCode()const{
        return errorState;
    }
    int Date::mdays(int mon, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) &&
               (year % 100 != 0)) || (year % 400 == 0));
    }
    bool Date::operator==(const Date& rhs) const{
        return (this->value()== rhs.value());
    }
    bool Date::operator!=(const Date& rhs)const{
        return (this->value()!= rhs.value());
    }
    bool Date::operator<(const Date& rhs)const{
        return (this->value()< rhs.value());
    }
    bool Date::operator>(const Date& rhs)const{
        return (this->value()> rhs.value());
    }
    bool Date::operator<=(const Date& rhs)const{
        return (this->value()<= rhs.value());
    }
    bool Date:: operator >=(const Date& rhs)const{
        return (this-> value()>= rhs.value());
    }
    void Date::errCode(int errCode){
        errorState = errCode;
    }
    bool Date::bad()const{
        if (errorState != NO_ERROR)
            return true;
        else
            return false;
    }
    std::istream& Date::read(std::istream& istr){
        char dateA;
        errorState = 0;
        istr.clear();
        istr >> year >> dateA >> month >> dateA >> day;
        if (istr.fail()){
            *this = Date();
            errCode(CIN_FAILED);
        }
        else if (min_year > year || year > max_year){
            *this = Date();
            errCode(YEAR_ERROR);
        }
        else if (1 > month || month > 12){
            *this = Date();
            errCode(MON_ERROR);
        }
        else if(day > mdays(month, year)){
            *this = Date();
            errCode(DAY_ERROR);
        }
        istr.clear();
        return istr;
    }
    std::ostream& Date::write(std::ostream& ostr)const{
        char dateA = '/';
        ostr << year << dateA;
        if(month < 10){
            ostr << 0;
        }
        ostr <<  month << dateA;
        if(day < 10){
            ostr << 0;
        }
        ostr << day;
        return ostr;
    }
    std::istream& operator >> (std::istream& istr, Date& r){
        return r.read(istr);
    }
    std::ostream& operator << (std::ostream& ostr, Date& w){
        return w.write(ostr);
    }
}
