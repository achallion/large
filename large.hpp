#ifndef LARGE_HPP
#define LARGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <bitset>

using namespace std;

const int blocksize = 18; // should be 1 <= size <= 18
const int LARGE_MIN = ~(NAM::pow(10, blocksize) - 1) + 1;
const int LARGE_MAX = NAM::pow(10, blocksize) - 1;

namespace NAM
{

    long long pow(long long num, int p);

    class large
    {
    public:
        vector<long long> number; // array for storing number
        int ldigits;              // how many digits does the last array member have
        bitset<1> positive;       // Number is positive or not

        large();                              // default constructor
        large(string);                        // argumented constructor
        void print();                         // print on console
        large unsignedadd(large second);      // add numbers as unsigned
        large unsignedsubtract(large second); // subtract
        large unsignedmultiply(large second); // multiply
        large unsigneddivide(large second);   // divide
    };

}; // namespace NAM

#endif