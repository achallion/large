#ifndef LARGE_HPP
#define LARGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <bitset>

using namespace std;

int blocksize = 10;

namespace VAT
{
    class large
    {
    public:
        vector<long long> number; // array for storing number
        int ldigits;              // how many digits does the last array member have
        bitset<1> positive;       // Number is positive or not

        large();                      // default constructor
        large(string);                // argumented constructor
        void print();                 // print on console
        large add(large second);      // add
        large subtract(large second); // subtract
        large multiply(large second); // multiply
        large divide(large second);   // divide
    };

}; // namespace VAT

#endif