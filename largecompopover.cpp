namespace NAM
{
    bool large::operator<(const large &arg1) const
    {
        // check +ve and -ve
        if (!this->positive[0] && arg1.positive[0])      // a -ve and b +ve
            return true;                                 // then is a < b
        else if (this->positive[0] && !arg1.positive[0]) // a +ve and b -ve
            return false;                                // then is a < b

        // a and b of same sign

        bool answer = false; // store answer for a < b if a and b are unsigned
        if (this->number.size() < arg1.number.size())
            answer = true;
        else if (this->number.size() > arg1.number.size())
            answer = false;
        else
            for (int i = this->number.size() - 1; i >= 0; i--)
            {
                if (this->number[i] < arg1.number[i])
                    answer = true;
                else if (this->number[i] > arg1.number[i])
                    answer = false;
                if (this->number[i] != arg1.number[i])
                    break;
                if (i == 0 && this->number[i] == arg1.number[i])
                    return false;
            }

        if (!this->positive[0]) // if sign is -ve
            return !answer;
        return answer;
    }

    bool large::operator>(const large &arg1) const
    {
        // check +ve and -ve
        if (this->positive[0] && !arg1.positive[0])      // a +ve and b -ve
            return true;                                 // then is a > b
        else if (!this->positive[0] && arg1.positive[0]) // a -ve and b +ve
            return false;                                // then is a > b

        // a and b of same sign

        bool answer = false; // store answer for a > b if a and b are unsigned
        if (this->number.size() > arg1.number.size())
            answer = true;
        else if (this->number.size() < arg1.number.size())
            answer = false;
        else
            for (int i = this->number.size() - 1; i >= 0; i--)
            {
                if (this->number[i] > arg1.number[i])
                    answer = true;
                else if (this->number[i] < arg1.number[i])
                    answer = false;
                if (this->number[i] != arg1.number[i])
                    break;
                if (i == 0 && this->number[i] == arg1.number[i])
                    return false;
            }

        if (!this->positive[0]) // if sign is -ve
            return !answer;
        return answer;
    }



}