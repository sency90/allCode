#include <stdio.h>
#include <string>
#include <limits.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
long long f(long long x) {
    string s = to_string(x);
    for(int i=0; i<s.size(); i++) {
        s[i] = ('9'-s[i])+'0';
    }
    return stoll(s);
}
long long calc(long long x) {
    string s = to_string(x);
    int len = s.size();
    bool chk = true;
    long long res;
    if(s[0]<'5') {
        res = s[0]-'0';
        chk = false;
    } else {
        res = 5;
        chk = true;
    }
    for(int i=1; i<len; i++) {
        if(chk) res *= 10;
        else res = res*10+(s[i]-'0');
    }
    return res;
}
int main() {
    long long t, n;
    scanf("%lld", &t);
    for(int i=0; i<t; i++) {
        scanf("%lld", &n);
        n=calc(n);
        printf("%lld\n", n*f(n));
    }
    return 0;
}
