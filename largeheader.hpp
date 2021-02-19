namespace NAM
{
    class large
    {
    public:
        vector<long long> number; // array for storing number
        int ldigits;              // how many digits does the last array member have
        bitset<1> positive;       // Number is positive or not

        large();                       // default constructor
        large(string);                 // argumented constructor
        void print();                  // print on console
        large unsignedadd(large);      // add numbers as unsigned
        large unsignedsubtract(large); // subtract
        large unsignedmultiply(large); // multiply
        large unsigneddivide(large);   // divide

        /* 
        large operator=();
       */
        bool operator==(const large &) const;
        bool operator<(const large &) const;
        bool operator>(const large &) const;
        /*
        bool operator!=();
        bool operator<=();
        bool operator>=();

        bool operator&();
        bool operator|();
        bool operator~();

        bool operator&&();
        bool operator||();
        bool operator!();

        bool operator>>();
        bool operator<<();
        bool operator<<=();
        bool operator>>=();

        bool operator+();
        bool operator-();
        bool operator*();
        bool operator/();
        bool operator%();

        bool operator+=();
        bool operator-=();
        bool operator*=();
        bool operator/=();
        bool operator%=();
        bool operator++(); //++a and a++
        bool operator--(); // --a and a--
        */
    };

}; // namespace NAM