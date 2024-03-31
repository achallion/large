#ifndef LARGE_HPP
#define LARGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

namespace SV
{
	const int BLOCK_SZ = 3; // should be 1 <= size <= 16 && !size & 1
							  // const int LARGE_MIN = ~(SV::pow(10, blocksize) - 1) + 1;
							  // const int LARGE_MAX = SV::pow(10, blocksize) - 1;
}

#include "helper.hpp"
#include "largeheader.hpp"
#include "largeheader.cpp"
#include "cons_decons/constructor.cpp"
#include "cons_decons/deconstructor.cpp"
// #include "operators/arithmetic.cpp"
// #include "operators/assignment.cpp"
// #include "operators/relational.cpp"
// #include "operators/logical.cpp"

#endif