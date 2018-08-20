/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: August 1st, 2018
 **********************************************************/
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include <iostream>
#include "Date.h"
#include "Product.h"

namespace AMA {
    class Perishable : public Product{
    private:
        Date expDate;
    public:
        Perishable();
        std::fstream& store(std::fstream& file, bool newLine=true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        const Date& expiry() const;
        };
    iProduct* CreatePerishable();
}


#endif /* Perishable_hpp */
