/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 18th, 2018
 **********************************************************/

#include <iostream>
#include <cstring>
#include "ErrorState.h"

namespace AMA {
    
    ErrorState::ErrorState(const char* errorMessage){
        if(errorMessage == nullptr){
            err_msg = nullptr;
        }else{
            err_msg = new char [strlen(errorMessage)+1];
            strncpy(err_msg, errorMessage, strlen(errorMessage));
            err_msg[strlen(errorMessage)] = '\0';
        }
    }
    ErrorState::~ErrorState(){
        delete [] err_msg;
        err_msg = nullptr;
    }
    void ErrorState::clear(){
        delete [] this->err_msg;
        err_msg = nullptr;
    }
    bool ErrorState::isClear()const{
        return (err_msg == nullptr) ? true : false;
    }
    void ErrorState::message(const char *str){
        delete [] err_msg;
        err_msg = new char[strlen(str)+1];
        strncpy(err_msg, str, strlen(str));
        err_msg[strlen(str)] = '\0';
    }
    const char* ErrorState::message()const{
        return err_msg;
    }
    std::ostream& operator << (std::ostream& os, const ErrorState& em){
        if (!em.isClear())
            os << em.message();
        return os;
    }
}
