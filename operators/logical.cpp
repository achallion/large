namespace NAM
{
    bool large::operator&&(const large &arg1) const
    {
        return !this->isnull() && !arg1.isnull();
    }

    bool large::operator||(const large &arg1) const
    {
        return !this->isnull() || !arg1.isnull();
    }

    bool large::operator!() const
    {
        return isnull();
    }

}; // namespace NAM