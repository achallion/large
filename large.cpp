#ifndef LARGE_CPP
#define LARGE_CPP

#include "large.hpp"

namespace VAT
{

    large::large()
    {
        number.push_back(0);
        ldigits = 1;
        positive = true;
    }

    large::large(string strint)
    {
        // check number is positive or negative
        positive = true;
        while (strint[0] == '-' || strint[0] == '+')
        {
            if (strint[0] == '-')
                positive = ~positive;

            strint = strint.substr(1, strint.size() - 1); // remove + or - sign from 0th position
        }

        // Calculate size of input string and vector size
        int strlen = strint.size();
        int vectsize = ceil((long double)strlen / blocksize);
        number.resize(vectsize, 0);

        // Fill the vector
        int powof10 = 0;
        int value = 1;

        for (int i = 0; i < strlen; i++)
        {
            int strindex = strlen - 1 - i;
            int vectindex = i / blocksize;
            char d = strint[strindex];
            int intd = d - '0';
            if (!isdigit(d))
                return;

            number[vectindex] = (long long)intd * value + number[vectindex];
            if (powof10 == blocksize - 1)
            {
                powof10 = 0;
                value = 1;
            }
            else
            {
                value *= 10;
                powof10++;
            }
        }
    }

    void large::print()
    {
        cout << ((positive == false) ? "-" : "");
        for (int i = number.size() - 1; i >= 0; i--)
        {
            cout << number[i];
        }
    }

}; // namespace VAT

#endif