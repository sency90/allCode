#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[201][201];
ll MAX = 2e9;
ll Combi(int n, int r) {
    if(n==r) return 1LL;
    else if(r==0) return 1LL;
    if(dp[n][r]>0) return dp[n][r];
    ll & ret = dp[n][r];
    ret = Combi(n-1,r-1) + Combi(n-1,r);
    if(ret>=MAX) ret=MAX;
    return ret;
}
string ans_str;
void MakeAnswer(int n, int m) {
    for(int i=0; i<n; i++) {
        ans_str.push_back('-');
        //ans_str.push_back('0');
    }
    for(int i=0; i<m; i++) {
        ans_str.push_back('o');
        //ans_str.push_back('1');
    }
}
//n: '-'(0)의 개수
//m: 'o'(1)의 개수
void f(int n, int m, int k) {
    if(k==0) return;
    int lo=0, hi=n;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        ll res = Combi(mid+m,mid);
        if(res>k) hi=mid-1;
        else lo=mid+1;
    }
    int ans=lo-1;
    if(ans>=0) {
        if(k == Combi(ans+m, ans)) {
            MakeAnswer(n-ans,m);
            MakeAnswer(ans,0);
        } else {
            MakeAnswer(n-ans-1, 1);
            f(ans + 1, m - 1, k - Combi(ans + m, ans));
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n,m,k;
        cin >> n >> m >> k;
        ans_str.clear();
        f(n,m,k);
        printf("%s\n", ans_str.c_str());
    }
    return 0;
}