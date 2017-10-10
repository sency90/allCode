#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;
#define UINTMAX 0xffffffff
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
class BigInteger{
private:
    vector<uint> num;
    bool isPositive;
public:
    virtual ~BigInteger();

    //constructors
    BigInteger();
    BigInteger(int);
    BigInteger(uint);
    BigInteger(ll);
    BigInteger(ull);
    BigInteger(string&);
    BigInteger(const BigInteger&);

    //basic operation
    void stringToBinary(const_iterator&, const_iterator&);
    void switchSign();

    //arithmetic operations
    const BigInteger add(const BigInteger&) const;
    const BigInteger mul(const BigInteger&) const;
    const BigInteger div(const BigInteger&) const;
    const BigInteger mod(const BigInteger&) const;

    //compare operations
    int compare(const BigInteger &other) const;

    //bit operations
    const BigInteger leftShift(uint x) const;
    const BigInteger rightShift(uint x) const;
    const BigInteger or(const BigInteger&) const;
    const BigInteger and(const BigInteger&) const;
    const BigInteger xor(const BigInteger&) const;
    const BigInteger not() cosnt;

    //operator overloading
    //=============================================================

    //sign operations
    const BigInteger operator-() const;
    const BigInteger operator+() const;

    //arithmetic operations
    const BigInteger& operator+(const BigInteger &rhs) const;

    //bit operations
};

const BigInteger abs(const BigInteger&);

//compare operations
bool operator==(const BigInteger &lhs, const BigInteger &rhs) const;
bool operator>=(const BigInteger &lhs, const BigInteger &rhs) const;
bool operator<=(const BigInteger &lhs, const BigInteger &rhs) const;
bool operator>(const BigInteger &lhs, const BigInteger &rhs) const;
bool operator<(const BigInteger &lhs, const BigInteger &rhs) const;
bool operator!=(const BigInteger &lhs, const BigInteger &rhs) const;

//assign operations
BigInteger& operator=(BigInteger &rhs);
BigInteger& operator+=(BigInteger &rhs);
BigInteger& operator-=(BigInteger &rhs);
BigInteger& operator*=(BigInteger &rhs);
BigInteger& operator/=(BigInteger &rhs);
BigInteger& operator%=(BigInteger &rhs);
BigInteger& operator^=(BigInteger &rhs);
BigInteger& operator|=(BigInteger &rhs);

//arithmetic operations
BigInteger& operator+(const BigInteger &lhs, const BigInteger &rhs);
BigInteger& operator-(const BigInteger &lhs, const BigInteger &rhs);
BigInteger& operator*(const BigInteger &lhs, const BigInteger &rhs);
BigInteger& operator/(const BigInteger &lhs, const BigInteger &rhs);
BigInteger& operator%(const BigInteger &lhs, const BigInteger &rhs);

//bit operations
BigInteger& operator&(const BigInteger &lhs, const BigInteger &rhs);
BigInteger& operator|(const BigInteger &lhs, const BigInteger &rhs);
BigInteger& operator^(const BigInteger &lhs, const BigInteger &rhs);
