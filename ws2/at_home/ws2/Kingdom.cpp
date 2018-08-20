/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: May 25th, 2018
 **********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;

namespace sict
{
    void display(const Kingdom& kingdom)
    {
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }
    void display(Kingdom const *kingdom, int a)
    {
        int totalPop = 0;
        cout << "------------------------------" << endl;
        cout << "Kingdoms of SICT" << endl;
        cout << "------------------------------" << endl;
        for(int i = 0;i < a ; i++){
            cout << i + 1 << ". " << kingdom[i].m_name << ", "
                 << "population " << kingdom[i].m_population <<endl;
                 totalPop += kingdom[i].m_population;
        }
        cout << "------------------------------" << endl;
        cout << "Total population of SICT: " << totalPop << endl;
        cout << "------------------------------" << endl;
    }
}

