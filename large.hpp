#ifndef LARGE_HPP
#define LARGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <bitset>

using namespace std;

#include "helper.hpp"

const int blocksize = 16; // should be 1 <= size <= 16 && !size & 1
const int LARGE_MIN = ~(NAM::pow(10, blocksize) - 1) + 1;
const int LARGE_MAX = NAM::pow(10, blocksize) - 1;

#include "largeheader.hpp"
#include "largeheader.cpp"
#include "operators/arithmetic.cpp"
#include "operators/relational.cpp"
#include "operators/logical.cpp"

#endif