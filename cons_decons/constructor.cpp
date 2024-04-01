
// Default Constructor
SV::large::large()
{
	this->number.clear();
	this->number.push_back(0);
	this->positive[0] = 1;
}

// Parameterized Constructor
/*
	"1234567" -> stored as -> 567 234 1

*/
SV::large::large(string strl)
{
	this->stol(strl);
}

// Copy Constructor
SV::large::large(const large &arg1)
{
	this->positive[0] = arg1.positive[0];
	this->number = arg1.number;
}
