/**********************************************************
 * Name: Xin Song (Felix) Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: Jun 14th, 2018
 **********************************************************/

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
    class Fraction{
    private:
        int m_numerator;
        int m_denominator;
        int max()const;
        int min()const;
        int gcd() const;
    public:
        Fraction();
        Fraction(int num, int denom);
        void reduce();
        bool isEmpty()const;
        void display()const;
        Fraction operator+(const Fraction& rhs)const;
        Fraction operator*(const Fraction& rhs)const;
        bool operator==(const Fraction& rhs)const;
        bool operator!=(const Fraction& rhs)const;
        Fraction& operator+=(const Fraction& rhs);
        
    };
}


#endif /* Fractions_hpp */
