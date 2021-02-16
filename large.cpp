#ifndef LARGE_CPP
#define LARGE_CPP

#include "large.hpp"

namespace NAM
{

    long long pow(long long num, int p)
    {
        // base
        if (p == 0)
            return 1;
        if (p == 1)
            return num;

        // rec
        long long part = NAM::pow(num, (p >> 1));
        if (p & 1)
            return part * part * num;
        return part * part;
    }

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
        int size = number.size();
        cout << number[size - 1];
        for (int i = number.size() - 2; i >= 0; i--)
        {
            long long part = number[i];
            string str(blocksize, '0');
            int j = blocksize - 1;
            while (part > 0)
            {
                str[j] = (part % 10) + '0';
                part /= 10;
                j--;
            }
            cout << str;
        }
    }

    large large::unsignedadd(large second)
    {
        large temp;

        // make container size same by adding 0 value blocks
        int allsize = max(this->number.size(), second.number.size());
        if (this->number.size() > second.number.size())
            second.number.resize(allsize, 0);
        else if (this->number.size() < second.number.size())
            this->number.resize(allsize, 0);

        temp.number.resize(allsize, 0);
        bool carry = false;
        long long threshhold = 5 * NAM::pow(10, blocksize - 1);

        for (int i = 0; i < allsize; i++)
        {
            if (!this->number[i] && !second.number[i])
            {
                if (carry)
                {
                    temp.number[i] += carry;
                    carry = false;
                }
                continue;
            }

            long long _first = this->number[i] - threshhold;
            long long _second = second.number[i] - threshhold;
            temp.number[i] = _first + _second + carry;
            if (temp.number[i] < 0)
            {
                temp.number[i] += threshhold;
                temp.number[i] += threshhold;
                carry = false;
            }
            else
                carry = true;
        }
        if (carry)
            temp.number.push_back(1);
        return temp;
    }

    large large::unsignedsubtract(large second)
    {
        large temp;

        // create greater and smaller
        large greaternum, smallernum;
        if (*this > second)
        {
            greaternum = large(this);
            smallernum = large(second);
        }
        else if (second > *this)
        {
            greaternum = large(second);
            smallernum = large(*this);
        }
        else
            return large();

        // make container size same by adding 0 value blocks
        int allsize = max(greaternum.number.size(), smallernum.number.size());
        if (greaternum.number.size() > smallernum.number.size())
            smallernum.number.resize(allsize, 0);

        temp.number.resize(allsize, 0);
        bool carry = false;
        long long threshhold = 5 * NAM::pow(10, blocksize - 1);

        for (int i = 0; i < allsize; i++)
        {
            if (!greaternum.number[i] && smallernum.number[i] == LARGE_MAX && carry)
            {
                temp.number[i] = threshhold - smallernum.number[i];
                temp.number[i] += threshhold - carry;
                continue;
            }

            smallernum.number[i] = ~smallernum.number[i] + 1;
            temp.number[i] = greaternum.number[i] - smallernum.number[i] - carry;
            if (temp.number[i] < 0)
            {
                temp.number[i] += threshhold;
                temp.number[i] += threshhold;
                carry = true;
            }
            else
                carry = false;
        }

        return temp;
    }

}; // namespace NAM

#endif