/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: May 25th, 2018
 **********************************************************/


// Workshop 2: Dynamic Memory
// File w2_at_home.cpp
// Version 2.0
#include <iostream>
#include <cstring>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array
    Kingdom* pKingdom = nullptr;
    // declare the pKingdom pointer here
    cout << "==========\n"
         << "Input data\n"
         << "==========\n"
         << "Enter the number of Kingdoms: ";
    cin >> count;
    cin.ignore();
    if (count < 1) return 1;
    
    pKingdom = new Kingdom[count];
    // allocate dynamic memory here for the pKingdom pointer
    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
        read(pKingdom[i]);
    //code to accept user input for Kingdom i
    }
    cout << "==========" << endl << endl;
    // testing that "display(...)" works
    cout << "------------------------------" << endl
         <<"The 1st Kingdom entered is" << endl
         << "------------------------------" << endl;
         display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;
    // expand the array of Kingdoms by 1 element
    // allocate dynamic memory for count + 1 Kingdoms
    Kingdom* qKingdoms = nullptr;
    qKingdoms = new Kingdom[count + 1];
    
    for(int i = 0; i < count; i++){
        qKingdoms[i].m_population = pKingdom[i].m_population;
        strcpy(qKingdoms[i].m_name, pKingdom[i].m_name);
        // copy elements from original array into this newly allocated array
        // copy the address of the newly allocated array into pKingdom pointer
	// add the new Kingdom
    }
    delete [] pKingdom;
    pKingdom = qKingdoms;
    // deallocate the dynamic memory for the original array
    cout << "==========\n"
         << "Input data\n"
         << "==========\n"
         << "Kingdom #" << count + 1 << ": " << endl;
    read(pKingdom[count]);
    count++;
    // accept input for the new element in the array
    cout << "==========\n" << endl;
    // testing that the overload of "display(...)" works
    display(pKingdom, count);
    cout << endl;
    delete [] qKingdoms;
    qKingdoms = nullptr;
    // deallocate the dynamic memory
    
    return 0;
    
}
// read accepts data for a Kingdom from standard input //
void read(Kingdom& kingdom) {
    cout << "Enter the name of the Kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number of people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}
