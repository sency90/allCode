#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
string s[51];
const ll mod = 1e9+7LL;
ll ans, d[501][51];
ll f(int x, int a) {
    if(a<=1) return a;
    ll &ret = d[x][a];
    if(ret) return ret;
    for(int i=1; i<=x; i++) {
        ret+=f(x-i,a-1);
        ret%=mod;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i];
        s[i]+=s[i];
    }
    ll sum=0;
    int ansi=-1, lim=2*n;
    for(int i=0; i<n; i++) {
        sum=0;
        bool good=true;
        for(int j=0; j<n; j++) {
            printf("(%d,%d) ", i,j);
            if(isdigit(s[j][i+j])) sum+=int(s[j][i+j]-'0');
            else { good=false; break; }
        }
        puts("");
        if(good) { ansi=i; break; }
    }

    printf("ansi: %d, sum:%lld\n", ansi, sum);
    if(ansi<0) {
        for(int i=n; i<lim; i++) {
            sum=0;
            bool good=true;
            for(int j=n-1, k=0; j>=0; j--, k++) {
                if(isdigit(s[j][i+k])) sum+=int(s[j][i+k]-'0');
                else { good=false; break; }
            }
            printf("sum:%lld\n", sum);
            if(good) { ansi=i; break; }
        }
    } else {
        puts("test");
        for(int i=0; i<n; i++) {
            int tsum=0, tcnt=0;
            for(int j=0; j<n; j++) {
                if(isdigit(s[j][i+j])) {
                    tsum+=int(s[j][i+j]-'0');
                    tcnt++;
                }
            }
            printf("%lld %d %d\n", sum,tsum,n-tcnt);
            ans+=f(sum-tsum,n-tcnt);
            ans%=mod;
        }
        printf("%lld", ans);
        return 0;
    }
    printf("ansi: %d, sum:%lld\n", ansi, sum);
    for(int i=n; i<lim; i++) {
        int tsum=0, tcnt=0;
        for(int j=n-1, k=0; j>=0; j--, k++) {
            if(isdigit(s[j][i+j])) {
                tsum+=int(s[j][i+j]-'0');
                tcnt++;
            }
        }
        printf("%lld %d %d\n", sum,tsum,n-tcnt);
        ans+=f(sum-tsum,n-tcnt);
        ans%=mod;
    }
    printf("%lld", ans);
    return 0;
}
