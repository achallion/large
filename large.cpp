#ifndef LARGE_CPP
#define LARGE_CPP

#include "large.hpp"

namespace hlhl
{

large::large()
{
    number = NULL;
    size = 0;
    last = 0;
}

large::large(string str)
{
    int strl = str.size();
    size = ceil((float)strl / 18);
    number = new ll[size];
    ll temp = 0;
    int count = 0;
    int containernum = size - 1;
    int i = strl % 18;

    if (i != 0) // copy first part of string
    {
        for (int j = 0; j < i; j++)
        {
            temp *= 10;
            temp += str[j] - '0';
        }
        number[containernum--] = temp;
    }

    temp = 0;
    for (; i < strl; i++) // Save remaining part of string
    {
        count++;
        temp *= 10;
        temp += str[i] - '0';

        if (count == 18)
        {
            // saving temp
            number[containernum--] = temp;
            count = 0;
            temp = 0;
        }
    }

    if (count != 0 || temp != 0 || containernum != -1)
    {
        cout << "\nError : There Is An Error In The Constructor.";
    }
}

void large::print()
{
    for (int i = size - 1; i >= 0; i--)
    {
        cout << number[i];
    }
}

}; // namespace hlhl

#endif