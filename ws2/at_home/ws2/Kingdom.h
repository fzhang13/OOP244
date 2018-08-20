/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: May 25th, 2018
 **********************************************************/

#ifndef _SICT_KINGDOM_H
#define _SICT_KINGDOM_H

namespace sict {
    
    struct Kingdom{
        char m_name[32];
        int m_population;
    };
    
    // declare the function display(...),
    void display(const Kingdom& kingdom);
    void display(Kingdom const *kingdom, int a);
    
}

#endif
