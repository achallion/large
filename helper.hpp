
namespace NAM
{
    long long pow(long long num, int p);

}



//**************

long long NAM::pow(long long num, int p)
{
    // base
    if (p == 0)
        return 1;
    if (p == 1)
        return num;

    // rec
    long long part = NAM::pow(num, (p >> 1));
    if (p & 1)
        return part * part * num;
    return part * part;
}
