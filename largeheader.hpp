namespace NAM
{
    class large
    {
    private:
        large unsignedadd(large);      // add numbers as unsigned
        large unsignedsubtract(large); // subtract numbers as unsigned

    public:
        vector<long long> number; // array for storing number
                                  //  int ldigits;              // how many digits does the last array member have
        bitset<1> positive;       // Number is positive or not

        bool isnull() const;

        large();                       // default constructor
        large(string);                 // argumented constructor
        void print();                  // print on console
        large unsignedmultiply(large); // multiply
        large unsigneddivide(large);   // divide

        //*****Operators****
        /* 

        // Arithmatic 
        bool operator+();
        bool operator-();
        bool operator*();
        bool operator/();
        bool operator%();

        // Increment/Decrement
        bool operator++();
        bool operator--();
        
        // Assignment
        large operator=();
        bool operator+=();
        bool operator-=();
        bool operator*=();
        bool operator/=();
        bool operator%=();
        bool operator<<=();
        bool operator>>=();
       */

        // Relational
        bool operator==(const large &) const;
        bool operator!=(const large &) const;
        bool operator<(const large &) const;
        bool operator>(const large &) const;
        bool operator<=(const large &) const;
        bool operator>=(const large &) const;

        // Logical
        bool operator&&(const large &) const;
        bool operator||(const large &) const;
        bool operator!() const;
        /*

        // Bitwise
        bool operator&();
        bool operator|();
        bool operator~();
        bool operator^();
        bool operator>>();
        bool operator<<();

        // Miscellaneous
        bool operator[]();

        */
    };

}; // namespace NAM