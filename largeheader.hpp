namespace SV
{
	class large
	{
	private:
		vector<unsigned long long> number; // array for storing number
		bitset<1> positive;				   // Number is positive or not

		bool isnull() const;
		void trim(string &str);				   // Remove 0 from front of string
		large unsignedadd(const large &);	   // add numbers as unsigned
		large unsignedsubtract(const large &); // subtract numbers as unsigned ( this being larger )

	public:
		void print();				   // print on console
		large unsignedmultiply(large); // multiply
		large unsigneddivide(large);   // divide

		// *****Constructor*****
		large();			  // default constructor
		large(string);		  // argumented constructor
		large(const large &); // copy constructor

		// *****Destructor*******
		~large(); // deconstructor

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