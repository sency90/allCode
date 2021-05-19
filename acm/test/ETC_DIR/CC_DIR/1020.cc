#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
char s[16];
int d[16],sum[16],zsum[16];
int up[16],zero[16];
int cnt[10] = {6,2,5,5,4,5,6,3,7,5};
ll dp[16][106]; //dp[length][sum] = number of cases

void goup(int S, int (*arr)[16], int ss) {
    if(S==1) {
        for(int i=0; i<=9; i++) {
            if(ss == cnt[i]) {
                (*arr)[S] = i;
                return;
            }
        }
        return;
    }

    for(int i=0; i<=9; i++) {
        if(ss-cnt[i]>0) {
            if(dp[S-1][ss-cnt[i]]>=1) {
                (*arr)[S] = i;
                goup(S-1, arr, ss-cnt[i]);
                return;
            }
        }
    }
}
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

ll power(int x, int y) {
    if(y==0) return 1LL;

    ll ret = power(x,y/2);
    if(y%2==0) return ret*ret;
    else return ret*ret*x;
}

ll calc(int *x, int *y, int len) {
    string xs, ys;
    for(int i=len; i>=1; i--) {
        xs += (char)(x[i]+'0');
        ys += (char)(y[i]+'0');
    }
    ll xd,yd;
    sscanf(xs.c_str(), "%lld", &xd);
    sscanf(ys.c_str(), "%lld", &yd);

    ll ret = inf;

    if(yd-xd<0) ret = min(ret, power(10,len)-xd+yd);
    else ret = min(ret, yd-xd);
    return ret;
}

int main() {
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0; i<len; i++) d[i+1] = s[i]-'0';
    reverse(d+1,d+1+len);

    //make subsum
    for(int i=1; i<=len; i++) {
        sum[i] = sum[i-1] + cnt[d[i]];
    }

    for(int i=0; i<10; i++) dp[1][cnt[i]]++;
    for(int i=2; i<=15; i++) {
        for(int j=i*2; j<=i*7; j++) {
            for(int k=2; k<=7; k++) {
                if(j-k<2) continue;
                dp[i][j] += dp[i-1][j-k] * dp[1][k];
            }
        }
    }

    //find S (start index)
    int S=-1;
    for(int i=1; i<=len; i++) {
        if(dp[i][sum[i]]>=2LL) { S=i; break; }
    }
    if(S<0) return 0&printf("%lld\n", power(10, len));

    ll mndiff = inf;
    for(int S=1; S<=len; S++) {
        for(int i=d[S]+1; i<=9; i++) {
            if(S>1 && sum[S]-cnt[i]>0 && dp[S-1][sum[S]-cnt[i]]>=1) {
                memcpy(up, d, (len+1)*sizeof(int));
                up[S] = i;
                goup(S-1, &up, sum[S]-cnt[i]);

                mndiff = min(mndiff, calc(d, up, len));
                break;
            }
            else if(S==1 && sum[S]==cnt[i] && d[S]!=i) {
                memcpy(up, d, (len+1)*sizeof(int));
                up[S] = i;
                mndiff = min(mndiff, calc(d,up,len));
                break;
            }
        }
    }

#if 1 //zero
    for(int i=1; i<=len; i++) zsum[i] += zsum[i-1]+cnt[0];
    for(int S=1; S<=len; S++) {
        memset(zero,0,sizeof(zero));
        int ss = sum[len]-(zsum[len]-zsum[S]);
        for(int i=0; i<=9; i++) {
            if(S>1 && ss-cnt[i]>0 && dp[S-1][ss-cnt[i]]>=1) {
                zero[S] = i;
                goup(S-1, &zero, ss-cnt[i]);

                ll res = calc(d,zero,len);
                if(res!=0) mndiff = min(mndiff, res);
                break;
            }
            else if(S==1 && ss==cnt[i]) {
                zero[S] = i;
                ll res = calc(d,zero,len);
                if(res!=0) mndiff= min(mndiff, res);
                break;
            }
        }
    }
#endif

    printf("%lld\n", mndiff);
    return 0;
}

