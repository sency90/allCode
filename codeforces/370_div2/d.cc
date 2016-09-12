#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int MOD = 1000000007;
long long dp[2][1000000];
int lowest;

int h(int v) { return v - lowest; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a,b,k,t;
    cin >> a >> b >> k >> t;
    int lowb = a-b;
    int highb = a-b;

    lowest = lowb - 2*k*(t);
    dp[0][h(lowb)] = 1LL;
    //solve for ti = 0
    int curr = 1;
    for(int p = lowb-2*k; p<=lowb; p++){
        dp[1][h(p)] = curr;
        curr++;
    }
    curr--;
    for(int p = lowb+1; p<= lowb+2*k; p++){
        curr--;
        dp[1][h(p)] = curr;
    }
    lowb -=2*k; highb+=2*k;
    for(int ti = 1; ti <= t-1; ti++){
        int o = ti%2;
        vector<long long> pref;
        pref.push_back(dp[o][h(lowb)]);
        long long su = dp[o][h(lowb)];
        for(int p = lowb+1; p <= highb; p++){
            su = (su+dp[o][h(p)])%MOD;
            pref.push_back(su);
        }
        int pe=2*k, il=0, ir=0, l=lowb, r=lowb, np=lowb-2*k;
        long long sum=0LL;
        //get the prefix first

        while(ir<=2*k){
            //evaluate current
            sum = (sum + pref[ir])%MOD;
            dp[!o][h(np)] = sum;
            //update for the next thing
            ir++; r++; np++;
        }
        pe = 0; ir--; r--; np--;
        while(pe<2*k){
            pe++; ir++; r++; np++;
            //evaluate
            sum = (sum + pref[ir])%MOD;
            sum = (sum - 2*pref[pe-1])%MOD;
            sum = (sum+MOD)%MOD;
            dp[!o][h(np)] = sum;
        }

        //slide into those dm's
        while(r<highb){
            //update
            pe++; r++; l++; ir++; il++; np++;

            long long sum1 = pref[pe-1] - ( (il==1) ? 0 : pref[(il-1)-1]);
            long long sum2 = pref[ir] - pref[pe-1];
            sum = (sum - sum1 + MOD)%MOD;
            sum = (sum + sum2)%MOD;
            dp[!o][h(np)] = sum;
        }
        //finally, suffix
        while(l<highb){
            l++; il++; pe++; np++;
            //subtract [l-1,pe-1]
            long long sum1 = pref[min(pe-1,ir)] - ((il==1) ? 0 : pref[il-1-1]);
            sum = (sum - sum1 + MOD)%MOD;

            if(pe<=ir) {
                long long sum2 = pref[ir]-pref[pe-1];
                sum = (sum + sum2)%MOD;
            }
            dp[!o][h(np)] = sum;
        }
        lowb-=2*k; highb+=2*k;
    }
    long long ans = 0;
    int o = t%2;
    for(int p = 1; p <= highb; p++){
        ans = (ans+dp[o][h(p)])%MOD;
    }
    cout << ans << "\n";
    return 0;
}
