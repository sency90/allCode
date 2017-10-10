#include "BigInteger.h"
#define UINTMAX 0xffffffff
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

BigInteger::BigInteger():isPositive(true){}
BigInteger::BigInteger(int x):isPositive(x>=0){ num.emplace_back(x); }
BigInteger::BigInteger(uint x):isPositive(true){ num.emplace_back(x); }
BigInteger::BigInteger(ll x):isPositive(x>=0LL){
    num.emplace_back(x & UINTMAX);
    num.emplace_back((x>>32) & UINTMAX);
}
BigInteger::BigInteger(ull x):isPositive(true){
    num.emplace_back(x & UINTMAX);
    num.emplace_back((x>>32) & UINTMAX);
}
BigInteger::BigInteger(string &x){
    isPositive = true;
    if(x.empty()) num.emplace_back(0);
    else {
        if(x[0]=='+') {
            stringToBinary(x.begin()+1, x.end());
        } else if(x[0]=='-') {
            stringToBinary(x.begin()+1, x.end());
            switchSign();
        } else {
            stringToBinary(x.begin(), x.end());
        }
    }
}
BigInteger::BigInteger(const BigInteger &x):num(x.num),isPositive(x.isPositive){}



void stringToBinary(const_iterator &b, const_iterator &e) {
    for(auto &digit=b; digit!=e; digit++) 
}

void switchSign() {
    for(int i=0; i<num.size(); i++) num[i]=~num[i];
    isPositive^=1;
    this->add(1);
}

