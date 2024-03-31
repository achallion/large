
// namespace SV
// {
// 	long long pow(long long num, int p);

// }

// //**************

// long long SV::pow(long long num, int p)
// {
// 	// base
// 	if (p == 0)
// 		return 1;
// 	if (p == 1)
// 		return num;

// 	// rec
// 	long long part = SV::pow(num, (p >> 1));
// 	if (p & 1)
// 		return part * part * num;
// 	return part * part;
// }
