#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
char s[16];
int d[16],sum[16],zsum[16],nsum[16];
int up[16],down[16],zero[16],nine[16];
int cnt[10] = {6,2,5,5,4,5,6,3,7,5};
ll dp[16][106]; //dp[length][sum] = number of cases
void goup(int S, int (*arr)[16], int ss);
void godown(int S, int (*arr)[16], int ss);
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

    ll ret = 0x3f3f3f3f3f3f3f3fLL;
    if(xd-yd<0) ret = min(ret, xd+power(10,len)-yd);
    else ret = min(ret, xd-yd);
    if(yd-xd<0) ret = min(ret, yd+power(10,len)-xd);
    return ret = min(ret, yd-xd);
    return ret;
}
int main() {
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0; i<len; i++) {
        d[i+1] = s[i]-'0';
    }
    reverse(d+1,d+1+len);
    for(int i=1; i<=len; i++) {
        printf("%d", d[i]);
    }
    puts("");

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
        if(dp[i][sum[i]]>=2LL) {
            S=i;
            break;
        }
    }

    printf("S:%d\n", S);
    if(S<0) return 0&printf("%lld\n", power(10, len));

    ll mndiff = 0x3f3f3f3f3f3f3f3fLL;
    for(int i=d[S]+1; i<=9; i++) {
        if( sum[S]-cnt[i]>0 && dp[S-1][sum[S]-cnt[i]]>=1) {
            memcpy(up, d, len+1);
            up[S] = i;
            goup(S-1, &up, sum[S]-cnt[i]);

            //printf("up: "); for(int i=len; i>=1; i--) printf("%d", up[i]); puts("");
            mndiff = min(mndiff, calc(d, up, len));
            break;
        }
    }
    printf("mndiff: %lld\n", mndiff);


    for(int i=d[S]-1; i>=0; i--) {
        if( sum[S]-cnt[i]>0 && dp[S-1][sum[S]-cnt[i]]>=1) {
            memcpy(down, d, len+1);
            down[S] = i;
            godown(S-1, &down, sum[S]-cnt[i]);

            //printf("down: "); for(int i=len; i>=1; i--) printf("%d", down[i]); puts("");
            mndiff = min(mndiff, calc(d, down, len));
            break;
        }
    }
    printf("mndiff: %lld\n", mndiff);





    for(int i=1; i<=len; i++) {
        zero[i] = 0;
        nine[i] = 9;
    }

#if 1 //zero
    for(int i=1; i<=len; i++) {
        zsum[i] += zsum[i-1]+cnt[zero[i]];
    }

    //find S (start index)
    S=-1;
    for(int i=1; i<=len; i++) {
        if(sum[len]-(zsum[len]-zsum[i])>0 && dp[i][sum[len]-(zsum[len]-zsum[i])]>=1LL) {
            S=i;
            break;
        }
    }

    if(S>0) {
        printf("zero-S: %d\n", S);
        int ss = sum[len]-(zsum[len]-zsum[S]);
        for(int i=zero[S]+1; i<=9; i++) {
            if( ss-cnt[i]>0 && dp[S-1][ss-cnt[i]]>=1) {
                zero[S] = i;
                goup(S-1, &zero, ss-cnt[i]);

                ll res = calc(d,zero,len);
                printf("zero-res: %lld\n", res);
                if(res!=0) mndiff = min(mndiff, res);
                break;
            }
        }
    }
#endif


#if 1 //nine
    for(int i=1; i<=len; i++) {
        nsum[i] += nsum[i-1]+cnt[nine[i]];
    }
    //find S (start index)
    S=-1;
    for(int i=1; i<=len; i++) {
        if(sum[len]-(nsum[len]-nsum[i])>0 && dp[i][sum[len]-(nsum[len]-nsum[i])]>=1LL) {
            S=i;
            break;
        }
    }

    if(S>0) {
        printf("nine-S: %d\n", S);
        int ss = sum[len]-(nsum[len]-nsum[S]);
        for(int i=nine[S]-1; i>=0; i--) {
            if( ss-cnt[i]>0 && dp[S-1][ss-cnt[i]]>=1) {
                nine[S] = i;
                godown(S-1, &nine, ss-cnt[i]);

                ll res = calc(d,nine,len);
                printf("nine-res: %lld\n", res);
                if(res!=0) mndiff = min(mndiff, res);
                break;
            }
        }
    }
#endif

    printf("%lld\n", mndiff);
    return 0;
}

void goup(int S, int (*arr)[16], int ss) {
    if(S>1) {
        for(int i=0; i<=9; i++) {
            if(ss-cnt[i]>0) {
                if(dp[S-1][ss-cnt[i]]>=1) {
                    (*arr)[S] = i;
                    goup(S-1, arr, ss-cnt[i]);
                    return;
                }
            }
        }
    } else {
        for(int i=0; i<=9; i++) {
            if(ss == cnt[i]) {
                (*arr)[S] = i;
                return;
            }
        }
    }
}

void godown(int S, int (*arr)[16], int ss) {
    if(S>1) {
        for(int i=9; i>=0; i--) {
            if(ss-cnt[i]>0) {
                if(dp[S-1][ss-cnt[i]]>=1) {
                    (*arr)[S] = i;
                    godown(S-1, arr, ss-cnt[i]);
                    return;
                }
            }
        }
    }
    else {
        for(int i=9; i>=0; i--) {
            if(ss == cnt[i]) {
                (*arr)[S] = i;
                return;
            }
        }
    }
}
