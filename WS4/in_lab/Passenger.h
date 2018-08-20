/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: Jun 6th, 2018
 **********************************************************/
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H


//declare your namespace here
namespace sict {
    //define the Passenger class here
    class Passenger{
    private:
        char m_name[32];
        char m_destination[32];
    public:
        Passenger();
        Passenger(const char* passengerName, const char* passengerDest);
        bool isEmpty()const;
        void display()const;
    };
}


#endif /* Passenger_hpp */
