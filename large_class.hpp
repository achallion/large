namespace SV
{
	class large
	{
	private:
		vector<ull> number; // array for storing number
		bitset<1> positive; // Number is positive or not

		bool isnull() const;				   // Check if number is 0
		void trim(string &);				   // Remove 0 from front of string
		void stol(string);					   // String to large
		bool isdigits(const string &);		   // check if string contain all digits
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
		// large operator=(const large &);
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

		// // Bitwise
		// bool operator&();
		// bool operator|();
		// bool operator~();
		// bool operator^();
		// bool operator>>();
		// bool operator<<();

		// Stream
		friend ostream &operator<<(ostream &, const large &);
		friend istream &operator>>(istream &, large &);

		// // Miscellaneous
		// bool operator[]();
	};

	large modulus(const large &);

	ostream &operator<<(ostream &, const large &);
	istream &operator>>(istream &, large &);

}; // namespace SV