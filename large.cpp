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

large::large(string strint)
{
    string str;
    positive = true;
    if (strint[0] == '-' || strint[0] == '+')
    {
        if (strint[0] == '-')
        {
            positive = false;
        }

        for (int i = 1; i < strint.size(); i++)
        {
            if (strint[i] <= 48 && strint[i] >= 57)
            {
                cout << "Error : Number Must Be an Integer Value .";
                return;
            }
            str[i - 1] = strint[i];
        }
    }
    else
    {
        for (int i = 0; i < strint.size(); i++)
        {
            if (strint[i] <= 48 && strint[i] >= 57)
            {
                cout << "Error : Number Must Be an Integer Value .";
                return;
            }
            str[i] = strint[i];
        }
    }

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

large large::add(large second)
{
}

}; // namespace hlhl

#endif