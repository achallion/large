namespace NAM
{
    large large::operator=(const large &arg1)
    {
        this->positive[0] = arg1.positive[0];
        this->number = arg1.number;
        return *this;
    }
};