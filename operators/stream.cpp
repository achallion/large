
ostream &SV::operator<<(ostream &out, const large &lnum)
{
	const vector<ull> &number = lnum.number;
	out << (lnum.positive[0] ? "" : "-");
	for (int i = number.size() - 1; i >= 0; i--)
		out << number[i];
	return out;
}

istream &SV::operator>>(istream &in, large &lnum)
{
	string str;
	in >> str;
	lnum = large(str);
	return in;
}