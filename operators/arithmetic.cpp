namespace NAM
{
    large large::operator+(const large &arg1)
    {

        large answer, greater, smaller;
        large mod1 = modulus(*this);
        large mod2 = modulus(arg1);
        if (this->positive[0] == arg1.positive[0]) // same sign , so add and sign remains same
        {
            greater = max<large>(mod1, mod2);
            smaller = min<large>(mod1, mod2);
            answer = greater.unsignedadd(smaller);
            answer.positive[0] = this->positive[0];
        }
        else // different sign so subtraction is done
        {
            if (mod1 > mod2) // |*this| is greater
            {
                answer = mod1.unsignedsubtract(mod2);
                answer.positive[0] = this->positive[0];
            }
            else if (mod2 != mod1) // |arg1| is greater
            {
                answer = mod2.unsignedsubtract(mod1);
                answer.positive[0] = arg1.positive[0];
            }
            // else both are equal , answer is 0
        }
        return answer;
    }

    large large::operator-(const large &arg1)
    {

        large answer, greater, smaller;
        large mod1 = modulus(*this);
        large mod2 = modulus(arg1);
        if (this->positive[0] != arg1.positive[0]) // different sign , so add and sign remains same as this
        {

            greater = max<large>(mod2, mod1);
            smaller = min<large>(mod2, mod1);
            answer = greater.unsignedadd(smaller);
            answer.positive[0] = this->positive[0];
        }
        else // same sign so subtraction is done
        {

            if (mod1 > mod2) // |*this| is greater
            {
                answer = mod1.unsignedsubtract(mod2);
                answer.positive[0] = this->positive[0];
            }
            else if (mod2 != mod1) // |arg1| is greater
            {
                answer = mod2.unsignedsubtract(mod1);
                answer.positive[0] = !arg1.positive[0];
            }
            // else both are equal , answer is 0
        }
        return answer;
    }

}; // namespace NAM