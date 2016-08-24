#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
struct Bint{
    string s;
    Bint(){s="0";}
    Bint(int x) { s.resize(x); }
    void push(int x) {
        s = to_string(x);
    }
    Bint operator+(const Bint &rhs) const {
        int l=s.size()-1, r=rhs.s.size()-1;
        int lim = min(l,r), mx=max(l,r);
        int carry = 0;
        Bint ret(max(l,r)+1);
        int i, sum;
        for(i=0; i<=lim; i++) {
            sum = s[l-i]-'0'+rhs.s[r-i]-'0'+carry;
            if(sum >= 10) {
                carry=1;
                sum-=10;
            } else carry=0;
            ret.s[mx-i] = sum+'0';
        }

        if(mx==l) {
            for(; i<=mx; i++) {
                int sum = s[l-i]-'0'+carry;
                if(sum >= 10) {
                    carry=1;
                    sum-=10;
                } else carry=0;
                ret.s[mx-i] = sum+'0';
            }
        } else {
            for(; i<=mx; i++) {
                int sum = rhs.s[r-i]-'0'+carry;
                if(sum >= 10) {
                    carry=1;
                    sum-=10;
                } else carry=0;
                ret.s[mx-i] = sum+'0';
            }
        }
        if(carry>0) ret.s = "1"+ret.s;
        return ret;
    }
};
void println(const Bint &x) {
    printf("%s\n", x.s.c_str());
}
Bint ans[10001];
int main() {
    int n;
    ans[1].push(1);
    ans[2].push(3);
    for(int i=3; i<=10000; i++) {
        ans[i]=ans[i-1]+ans[i-2];
    }
    while(~scanf("%d",&n)) println(ans[n]);
    return 0;
}
