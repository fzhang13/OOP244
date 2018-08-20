/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 25th, 2018
 **********************************************************/

#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iostream>
#include <cstring>
using namespace std;

namespace sict {
    const int LARGEST_NUMBER  = 1000000000;
    const int SMALLEST_NUMBER = 0;
    const int COLUMN_WIDTH    = 15;
    
    int min(const int* data, int n);
    
    template<typename T>
    T max(const T* data, int n){
        T max = data[0];
        for(int i = 0; i < n; ++i){
            if(max < data[i])
                max = data[i];
        }
        return max;
    }
    
    template<typename T>
    T min(const T* data, int n){
        T min = data[0];
        for(int i =0; i < n; ++i){
            if (min > data[i])
                min = data[i];
        }
        return min;
    }
    
    template<typename T>
    T sum(const T* data, int n){
        T sum = 0;
        for(int i =0; i < n; ++i){
            sum += data [i];
        }
        return sum;
    }
    
    template<typename T>
    double average(const T* data, int n){
        return static_cast<double>(sum(data, n))/n;
    }
    
    template<typename T>
    bool read(std::istream& input, T* data, int n){
        for(int i=0; i< n; ++i){
            input.ignore();
            input >> data[i];
            if (input.fail()){
                return false;
            }
        }return true;
    }
    
    template<typename T>
    void display(const char* name, const T* data, int n){
        std::cout.width(20);
        std::cout << std::right << name;
        
        for(int i =0; i < n; ++i){
            std::cout.width(15);
            std::cout << data[i];
        }
        std::cout << "\n";
    }
    
    template<typename T>
    T readRow(std::istream& fileInput, const char* name, T* data, int n){
        char row[2000];
        bool ok = !fileInput.bad();
        
        if(ok){
            fileInput.get(row, 2000, ',');
            if(std::strcmp(row, name)!= 0){
                std:: cout << "Cannot parse row for " << name << std::endl;
                fileInput.ignore(2000, '\n');
                ok = false;
            }
        }
        if(ok){
            ok = read(fileInput, data, n);
        }
        fileInput.ignore(2000, '\n');
        return ok;
    }
    
    void answers(const int* year, const int* population, const int* violentCrime,
                 const double* violentCrimeRate, const int* grandTheftAuto,
                 const int n);
    
}

#endif 
