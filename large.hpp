#ifndef LARGE_HPP
#define LARGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

namespace hlhl
{
typedef long long ll;

class large
{

    ll *number;    // array for storing number
    int size;      // size of array
    int last;      // how many digits does the last array member have
    bool positive; // Number is positive or not

public:
    large();       // default constructor
    large(string); // argumented constructor
    void print();
    large add(large second);
};

}; // namespace hlhl

#endif