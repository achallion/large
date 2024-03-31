namespace SV
{
    class large
    {
    private:
        bool isnull() const;
        void trim();                           // Remove 0 blocks from front
        large unsignedadd(const large &);      // add numbers as unsigned
        large unsignedsubtract(const large &); // subtract numbers as unsigned ( this being larger )

    public:
        vector<long long> number; // array for storing number
                                  //  int ldigits;              // how many digits does the last array member have
        bitset<1> positive;       // Number is positive or not

        void print();                  // print on console
        large unsignedmultiply(large); // multiply
        large unsigneddivide(large);   // divide

        // *****Constructor*****
        large();       // default constructor
        large(string); // argumented constructor
        large(const large &); // copy constructor

        // *****Destructor*******

        //*****Operators****

        // Arithmatic
        large operator+(const large &);
        large operator-(const large &);
        /* 
        bool operator*();
        bool operator/();
        bool operator%();

        // Increment/Decrement
        bool operator++();
        bool operator--();
        */
        // Assignment
        large operator=(const large &);
        /*
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

    large modulus(const large &);

}; // namespace SV