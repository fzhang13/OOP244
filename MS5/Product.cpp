/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 23rd, 2018
 * Edited Aug 1st, 2018
 **********************************************************/

#include <iostream>
#include "Product.h"
#include <iomanip>
#include <cstring>
#include <fstream>
#include <istream>
#include "ErrorState.h"

using namespace std;

namespace AMA {
    Product::Product(char type){
        m_proType = type;
        m_proSku[0] = '\0';
        m_proUnit[0] = '\0';
        m_proName = nullptr;
        m_quantityOnHand = 0;
        m_quantityNeeded = 0;
        m_priceOfEach = 0.0;
        m_taxable = false;
    }
    
    Product::Product(const char* sku, const char* pName, const char * unit, int onHand, bool taxable, double beforeTax, int needed):Product(){
        name(pName);
        strncpy(m_proSku, sku, max_sku_length);
        m_proSku[max_sku_length] = '\0';
        strncpy(m_proUnit, unit, max_unit_length);
        m_proUnit[max_unit_length] = '\0';
        m_quantityOnHand = onHand;
        m_quantityNeeded = needed;
        m_priceOfEach = beforeTax;
        m_taxable = taxable;
    }
    
    Product::~Product(){
        delete [] m_proName;
    }
    
    Product::Product(const Product& other){
        //reduced redundant code on the copy constructor.
        *this = other;
    }
    
    Product& Product::operator=(const Product& other){
        if(this != &other){
            //simplified name copy
            name(other.m_proName);
            m_proType = other.m_proType;
            strncpy(m_proSku, other.sku(), max_sku_length);
            strncpy(m_proUnit, other.unit(), max_unit_length);
            m_quantityOnHand = other.m_quantityOnHand;
            m_quantityNeeded = other.m_quantityNeeded;
            m_priceOfEach = other.m_priceOfEach;
            m_taxable = other.m_taxable;
        }
        return *this;
    }
    
    void Product::name(const char* productName){
        if(productName != nullptr){
            int length = (int)strlen(productName);
            m_proName = new char[length+1];
            for (int i =0; i < length; ++i){
                m_proName[i] = productName[i];
            }
            m_proName[length]='\0';
            
            // added condition check
        }else if(productName == nullptr){
            delete [] m_proName;
            m_proName = nullptr;
        }
    }
    
    const char* Product::name()const{
        return (m_proName == nullptr) ? nullptr : m_proName;
    }
    const char* Product::sku()const{
        return m_proSku;
    }
    const char* Product::unit()const{
        return m_proUnit;
    }
    bool Product::taxed()const{
        return m_taxable;
    }
    double Product::price()const{
        return m_priceOfEach;
    }
    double Product::cost()const{
        return (m_taxable)? price() * (taxRate + 1) : price();
    }
    void Product::message(const char* errorMessage){
        m_err.message(errorMessage);
    }
    bool Product::isClear()const{
        return m_err.isClear();
    }
    std::fstream& Product::store(std::fstream& file, bool newLine) const{
        
        file << m_proType << ',' << m_proSku << ',' << m_proName << ',' <<
        m_proUnit << ',' << m_taxable << ',' <<m_priceOfEach << ','
        << m_quantityOnHand << ',' << m_quantityNeeded;
        if(newLine)
            file << endl;
        return file;
    }
    std::fstream& Product::load(std::fstream& file){
        char sku[maxCharSku];
        char name[maxCharName];
        char unit[maxCharUnit];
        bool taxable = false;
        char tax;
        int onHand;
        int needed;
        double price;
    
        
        if(file.is_open()){
            
//            file >> temp.m_proType >> temp.m_proSku >> temp.m_proUnit >>
//            temp.m_proName >> temp.m_quantityOnHand >> temp.m_taxable >>
//            temp.m_priceOfEach >> temp.m_quantityNeeded;
            file.getline(sku, maxCharSku, ',');
            sku[strlen(sku)] = '\0';
            
            file.getline(name,maxCharName, ',');
            name[strlen(name)]='\0';
            
            file.getline(unit,maxCharUnit, ',');
            unit[strlen(unit)]='\0';
            
            file >> tax;
            if(tax == '1')
                taxable = true;
            if(tax == '0')
                taxable = false;
            
            file.ignore();
            
            file >> price;
            file.ignore();
            
            file >> onHand;
            file.ignore();
            
            file >> needed;
            file.ignore();
    
            *this = Product(sku,name,unit,onHand,taxable,price,needed);
        }

        return file;
    }
    std::ostream& Product::write(std::ostream& os, bool linear) const{
        if(!m_err.isClear()){
            os << m_err.message();
        }
        else if(linear){
            os << setw(maxCharSku) << left << m_proSku << '|'
            << setw(20) << left << m_proName << '|'
            << setw(7) << right << fixed << setprecision(2) << cost() << '|'
            << setw(4) << right << m_quantityOnHand << '|'
            << setw(10) << left << m_proUnit << '|'
            << setw(4) << right << m_quantityNeeded << '|';
        }else{
            os << " Sku: " << m_proSku << endl
            << " Name (no spaces): " << m_proName << endl
            << " Price: " << m_priceOfEach << endl;
            if(m_taxable){
                os << " Price after tax: " << cost()  << endl;
            }else{
                os << " Price after tax: N/A" <<  endl;
            }
            os << " Quantity on Hand: " << m_quantityOnHand << " "
            << m_proUnit<< endl
            << " Quantity needed: " << m_quantityNeeded;
        }

        return os;
    }
    std::istream &Product::read(std::istream &is){
        char sku[maxCharSku + 1];
        char* name = new char[maxCharName +1];
        char unit[maxCharUnit+1];
        bool taxable= true;
        char yN;
        int onHand = 0;
        int needed = 0;
        double beforeTax= 0;
        ErrorState error;
        
        
        cout << " Sku: ";
        is >> sku;
        
        cout << " Name (no spaces): ";
        is >> name;
        
        cout << " Unit: ";
        is >> unit;
        
        cout << " Taxed? (y/n): ";
        is >> yN;
        
        if (yN == 'Y' || yN == 'y')
            taxable = true;
        else if(yN == 'N' || yN == 'n')
            taxable = false;
        else{
            is.setstate(std::ios::failbit);
            error.message("Only (Y)es or (N)o are acceptable");
            
        }
        if(!is.fail()){
            m_err.clear();
            cout << " Price: ";
            is >> beforeTax;
            if(is.fail())
                error.message("Invalid Price Entry");
        }
        if(!is.fail()){
            m_err.clear();
            cout << " Quantity on hand: ";
            is >> onHand;
            if(is.fail())
                error.message("Invalid Quantity Entry");
        }
        if(!is.fail()){
            m_err.clear();
            cout << " Quantity needed: ";
            is >> needed;
            cin.ignore();
            if(is.fail())
                error.message("Invalid Quantity Needed Entry");
        }
        if(!is.fail()){
            m_err.clear();
            Product temp = Product(sku, name, unit, onHand, taxable,beforeTax,needed);
            *this = temp;
        }
        if(is.fail()){
            m_err.message(error.message());
        }
        delete [] name;
        name = nullptr;
        return is;
    }
    bool Product::operator==(const char* address)const{
        return strcmp(address, this->m_proSku) == 0;
    }
    double Product::total_cost()const{
        double tax = m_priceOfEach * taxRate;
        double afterTax = m_priceOfEach + tax;
        return static_cast<double>(m_quantityOnHand* afterTax);
    }
    void Product::quantity(int units){
        m_quantityOnHand = units;
    }
    bool Product::isEmpty()const{
        return (m_proName == nullptr)? true : false;
    }
    int Product::qtyNeeded()const {
        return m_quantityNeeded;
    }
    int Product::quantity()const{
        return m_quantityOnHand;
    }
    bool Product::operator>(const char* name) const{
        return (strcmp(m_proSku, name)> 0)? true: false;
    }
    bool Product::operator>(const iProduct& other)const{
        return (strcmp(m_proName, other.name())> 0) ? true: false;
    }
    int Product::operator+=(int add){
        if(add > 0){
            m_quantityOnHand+= add;
            return m_quantityOnHand;
        }else
            return m_quantityOnHand;
    }
    std::ostream &operator<<(std::ostream &os, const iProduct& other){
        return other.write(os, true);
    }
    std::istream &operator>>(std::istream &is, iProduct& other){
        other.read(is);
        return is;
    }
    double operator+=(double& total, const iProduct& other){
        return total + other.total_cost();
    }
}

