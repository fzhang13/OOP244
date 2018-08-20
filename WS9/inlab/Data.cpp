/**********************************************************
 * Name: Xin Song Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: July 25th, 2018
 **********************************************************/

#include "Data.h"
using namespace std;

namespace sict {
    

    int min(const int* data, int n) {
        int min = LARGEST_NUMBER;
        for (int i = 0; i < n; ++i) {
            if (data[i] < min)
                min = data[i];
        }
        return min;
    }
    
    
    void answers(const int* year, const int* population, const int* violentCrime,
                 const double* violentCrimeRate, const int* grandTheftAuto,
                 const int n) {
        
        int populationDiff = population[n - 1] - population[0];
        
        
        cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
        cout.precision(2);
        cout.setf(ios::fixed);
        cout << static_cast<double>(populationDiff)/1000000 << " million" << endl;
        
    
        auto violentCrimeStart = violentCrime[0];
        auto violentCrimeEnd = violentCrime[n - 1];
        const char *trend = violentCrimeStart < violentCrimeEnd ? "up" : "down";
        cout << "Violent Crime trend is " << trend << endl;
        
        
        double gtaMillions = 0;
        cout << "There are ";
        gtaMillions = average(grandTheftAuto, n);
        cout.precision(2);
        cout << fixed <<
        gtaMillions / 1.0E6
        << " million Grand Theft Auto incidents on average a year" << endl;
        
       
        cout << "The Minimum Violent Crime rate was " <<
        static_cast<int>(min(violentCrimeRate, n)) << endl;
        cout << "The Maximum Violent Crime rate was "<<
        static_cast<int>(max(violentCrimeRate, n)) << endl;
    }
}
