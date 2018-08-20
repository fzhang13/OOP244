/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: May 22nd, 2018
 **********************************************************/


#include <iostream>
#include "Kingdom.h"
using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array
    Kingdom* pKingdom = nullptr; // declare the pKingdom pointer
    cout << "==========\n"
   	 << "Input data\n"
   	 << "==========\n"
   	 << "Enter the number of Kingdoms: ";
    cin >> count;
    cin.ignore();
  
    if (count < 1) return 1;
    pKingdom = new Kingdom[count]; //allocate dynamic memory for the pKingdom pointer
  
    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
        read(pKingdom[i]);  //accept user input for Kingdom i
    }
    cout << "==========" << endl << endl;
    // testing that "display(...)" works
    cout << "------------------------------" << endl
	 << "The 1st kingdom entered is" << endl
   	 << "------------------------------" << endl;
    sict::display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;
    
    delete[] pKingdom; //deallocate the dynamic memory
    pKingdom = nullptr;
    return 0;
}

// read accepts data for a Kingdom from standard input //
void read(sict::Kingdom& kingdom) {
    cout << "Enter the name of the Kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number of people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}
