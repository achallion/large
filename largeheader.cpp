namespace SV
{

    bool large::isnull() const
    {
        if (number.size() <= 1 && number[0] == 0)
            return true;
        return false;
    }

    void large::trim()
    {
        int i = number.size() - 1;
        while (i > 0 && number[i] == 0)
        {
            i--;
        }
        number.resize(i + 1);
        number.shrink_to_fit();
    }

    large large::unsignedadd(const large &second) // this is larger than second
    {
        large answer;

        // make container size same by adding 0 value blocks
        int maxsize = this->number.size();
        int minsize = second.number.size();
        answer.number.resize(maxsize, 0);
        bool carry = false;

        for (int i = 0; i < maxsize; i++)
        {
            answer.number[i] = this->number[i] + carry + (i < minsize ? second.number[i] : 0);
            carry = false;

            if (answer.number[i] > LARGE_MAX)
            {
                carry = true;
                answer.number[i] -= (LARGE_MAX + 1);
            }
        }

        if (carry)
            answer.number.push_back(1);

        answer.trim();
        return answer;
    }

    large large::unsignedsubtract(const large &second) // this is larger than second
    {
        large answer;
        int maxsize = this->number.size();
        int minsize = second.number.size();
        answer.number.resize(maxsize, 0);
        bool carry = false;

        for (int i = 0; i < maxsize; i++)
        {
            answer.number[i] = this->number[i] - (i < minsize ? second.number[i] : 0) - carry;
            carry = false;
            if (answer.number[i] < 0)
            {
                answer.number[i] += LARGE_MAX + 1;
                carry = true;
            }
        }
        answer.trim();
        return answer;
    }

    large::large()
    {
        number.clear();
        number.push_back(0);
        positive[0] = 1;
    }

    large::large(string strint)
    {
        // check number is positive or negative
        positive[0] = 1;
        while (strint[0] == '-' || strint[0] == '+')
        {
            if (strint[0] == '-')
                positive[0] = ~positive[0];

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
        cout << ((!this->positive[0]) ? "-" : "");
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

    large modulus(const large &arg1)
    {
        if (arg1.positive[0])
            return arg1;
        // else
        large negarg = arg1;
        negarg.positive[0] = 1;
        return negarg;
    }

}; // namespace NAM