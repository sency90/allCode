#include <bits/stdc++.h>
using namespace std;
int gcd(int b, int s) {
    if(s==0) return b;
    else return gcd(s,b%s);
}
int main() {
    int b=1428, s=732;
    printf("gcd(%d,%d) = %d\n",b,s,gcd(b,s));
    return 0;
}