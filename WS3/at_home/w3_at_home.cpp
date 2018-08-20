/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: May 31st, 2018
 **********************************************************/

#include <iostream>
#include "CRA_Account.h"
using namespace std;
using namespace sict;
int main(){
    CRA_Account myCRA;
    int sin;
    bool quit = false;
    char familyName[max_name_length + 1];
    char givenName[max_name_length + 1];
    cout << "Canada Revenue Agency Account App" << endl
         << "=================================" << endl << endl;
    do {
        cout << "Please enter your family name: ";
        cin.getline(familyName, max_name_length);
        cout << "Please enter your given name: ";
        cin.getline(givenName, max_name_length);
        cout << "Please enter your social insurance number (0 to quit): ";
        cin >> sin;
        cin.ignore();
        if (sin != 0) {
            myCRA.set(familyName, givenName, sin);
            if (myCRA.isEmpty()) {
                cout << "Invalid input! Try again." << endl; }
            else {
                int year;
                double balance;
                do {
                    cout << "Please enter the year of your tax return (0 to quit): ";
                    cin >> year;
                    cin.ignore();
                    if (year != 0) {
                        cout << "Please enter the balance owing on your tax return (0 to quit): ";
                        cin >> balance;
                        cin.ignore();
                        myCRA.set(year, balance);
                    }
                } while (year != 0);
                quit = true; }
        } else {
            quit = true; }
    } while (!quit);
    cout << "----------------------------------------" << endl;
    cout << "Testing the display function" << endl;
    cout << "----------------------------------------" << endl;
    myCRA.display();
    cout << "----------------------------------------" << endl;
    return 0; }

