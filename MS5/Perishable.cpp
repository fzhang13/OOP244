/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: August 1st, 2018
 **********************************************************/

#include <iostream>
#include "Perishable.h"

using namespace std;

namespace AMA {
    Perishable::Perishable():Product('P'){
        m_err.clear();
    }
    
    std::fstream & Perishable::store(std::fstream & file, bool newLine) const{
        Product::store(file, false);
        file << ',';
        expDate.write(file);
        file << endl;
        return file;
    }
    
    std::fstream& Perishable::load(std::fstream& file){
        Product::load(file);
        expDate.read(file);
        file.ignore();
        return file;
    }
    
    std::ostream& Perishable::write(std::ostream& os, bool linear)const{
        Product::write(os, linear);
        if(isClear()&& !isEmpty()){
            if(linear)
                expDate.write(os);
            else{
                os << "\n Expiry date: ";
                expDate.write(os);
            }
        }
        return os;
    }
    
    std::istream& Perishable::read(std::istream& is){
        is.clear();
        Product::read(is);
        m_proType = 'P';
        if(!is.fail()){
            m_err.clear();
            cout << " Expiry date (YYYY/MM/DD): ";
            expDate.read(is);
        }
        if(expDate.errCode()== CIN_FAILED){
            
            m_err.message("Invalid Date Entry");
        }
        if(expDate.errCode()== YEAR_ERROR){
            
            m_err.message("Invalid Year in Date Entry");
        }
        if(expDate.errCode()== MON_ERROR){
            
            m_err.message("Invalid Month in Date Entry");
        }
        if(expDate.errCode()== DAY_ERROR){
            
            m_err.message("Invalid Day in Date Entry");
        }
        if(expDate.errCode())
            is.setstate(std::ios::failbit);
        return is;
    }
    
    const Date& Perishable::expiry()const{
        return expDate;
    }
    
}
