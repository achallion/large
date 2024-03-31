
// Default Constructor
SV::large::large()
{
	this->number.clear();
	this->number.push_back(0);
	this->positive[0] = 1;
}

// Parameterized Constructor
SV::large::large(string strl)
{
	this->number.clear();

	// if string is empty
	if (!strl.size())
	{
		this->number.push_back(0);
		this->positive[0] = 1;
	}

	// set the sign
	this->positive[0] = strl[0] == '-' ? 0 : 1;

	// seperate the number
	if (strl[0] == '+' || strl[0] == '-')
		strl = strl.substr(1, strl.size() - 1);

	// trim the strl of 0
	this->trim(strl);

	// Resize the number array
	this->number.resize(((strl.size() - 1) / BLOCK_SZ) + 1);

	// Store string in number array
	int ct = 0;
	for (int i = strl.size() - 1; i >= 0; i -= BLOCK_SZ)
	{
		int ind = i - BLOCK_SZ + 1;
		string str = ind < 0 ? strl.substr(0, BLOCK_SZ + ind) : strl.substr(ind, BLOCK_SZ);
		this->number[ct++] = stoull(str);
	}
}

// Copy Constructor
SV::large::large(const large &arg1)
{
	this->positive[0] = arg1.positive[0];
	this->number = arg1.number;
}
