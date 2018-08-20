/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: Jun 7th, 2018
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
        int m_year;
        int m_month;
        int m_day;
    public:
        Passenger();
        Passenger(const char* passengerName, const char* passengerDest);
        Passenger(const char* passengerName, const char* passengerDest, int y,
                  int m, int d);
        bool isEmpty()const;
        void display()const;
        const char* name()const;
        bool canTravelWith(const Passenger&) const;
    };
}


#endif /* Passenger_hpp */
