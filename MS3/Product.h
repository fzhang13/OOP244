/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 23rd, 2018
 **********************************************************/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "ErrorState.h"

namespace AMA {
    const int maxCharSku = 7;
    const int maxCharUnit = 10;
    const int maxCharName = 75;
    const double taxRate = 0.13;
    const int max_sku_length = maxCharSku;
    const int max_name_length = maxCharName;
    const int max_unit_length = maxCharUnit;
    
    class Product{
    private:
        char m_proType;
        char m_proSku[maxCharSku + 1];
        char m_proUnit[maxCharUnit + 1];
        char* m_proName;
        int m_quantityOnHand;
        int m_quantityNeeded;
        double m_priceOfEach;
        bool m_taxable;
        ErrorState m_err;
    protected:
        void name(const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double price() const;
        double cost() const;
        void message(const char*);
        bool isClear() const;
    public:
        Product(char type = 'N');
        Product(const char* sku, const char* pName, const char * unit, int onHand = 0, bool taxable = true, double beforeTax = 0.0, int needed = 0);
        Product(const Product& other);
        Product& operator=(const Product& other);
        ~Product();
        std::fstream& store(std::fstream& file, bool newLine=true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        bool operator>(const Product&) const;
        int operator+=(int);
    };
    std::ostream& operator<<(std::ostream&, const Product&);
    std::istream& operator>>(std::istream& is, Product& other);
    double operator+=(double& total, const Product& other);
}


#endif /* Product_hpp */
