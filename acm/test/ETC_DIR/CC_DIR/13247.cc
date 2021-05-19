#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <bitset>
using namespace std;
typedef bitset<17> b17;
typedef long long ll;
string s;
int prv[18],nprv[18],rabbit[18],prabbit[18],n;
bool chk[18];
void oneMove(b17& bit, b17& pbit, int sz) {
    b17 nbit(0);
    memset(rabbit,-1,sizeof(rabbit));
    memset(chk,false,sizeof(chk));
    for(int i=0; i<sz; i++) {
        if(bit[i]) {
            if(i==0) {
                nbit.set(i+1);
                rabbit[i+1]=i;
            } else if(i==sz-1||i==sz-2) {
                if(nbit[i-1]) chk[i-1]=true;
                else {
                    nbit.set(i-1);
                    rabbit[i-1]=i;
                }
            } else {
                if(s[i]=='W') {
                    if(nbit[i-1]) chk[i-1]=true;
                    else {
                        nbit.set(i-1);
                        rabbit[i-1]=i;
                    }
                } else if(s[i]=='B') {
                    nbit.set(i+1);
                    rabbit[i+1]=i;
                } else {
                    if(prabbit[i]==-1) {
                        if(nbit[i-1]) chk[i-1]=true;
                        else {
                            nbit.set(i-1);
                            rabbit[i-1]=i;
                        }
                    } else {
                        if(nbit[prabbit[i]]) chk[prabbit[i]]=true;
                        else {
                            nbit.set(prabbit[i]);
                            rabbit[prabbit[i]]=i;
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<sz; i++) {
        if(chk[i]) {
            nbit.reset(i);
            rabbit[i]=-1;
        }
    }
    memcpy(prabbit,rabbit,sizeof(rabbit));
    nbit.reset(sz-1);
    pbit.reset();
    pbit=bit;
    bit.reset();
    bit=nbit;
}
ll dp[18][18];
ll combi(int n, int r) {
    if(n==r||r==0) return 1LL;
    ll &ret = dp[n][r];
    if(ret) return ret;
    return ret = combi(n-1,r-1)+combi(n-1,r);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    int r; cin >> r;
    n=s.size();
    memset(prv,0,sizeof(prv));

    int de=0;
    int lim = 1<<n, sum=0;
    for(int i=1; i<lim; i++) {
        memset(prabbit,-1,sizeof(prabbit));
        b17 bit(i), pbit;
        if(bit.count()==r) {
            for(int j=n; j>2; j--) {
                oneMove(bit,pbit,j);
            }
            sum+=bit.count();
            de++;
        }
    }
    printf("%.10lf\n", (double)sum/de);
    return 0;
}
