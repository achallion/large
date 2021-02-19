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

const int blocksize = 18; // should be 1 <= size <= 18
const int LARGE_MIN = ~(NAM::pow(10, blocksize) - 1) + 1;
const int LARGE_MAX = NAM::pow(10, blocksize) - 1;

#include "largeheader.hpp"
#include "largeheader.cpp"
#include "largecompopover.cpp"

#endif