#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int CHKVAL;
int chk[51][101];
double dp[51][101];
int p;
double f(int x, int d) {
    if(d==0) {
        if(x==p) return 1;
        else return 0;
    }
    if(chk[x][d] == CHKVAL) return dp[x][d];
    chk[x][d] = CHKVAL;
    double & ret = dp[x][d];
    ret=0;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        ret += f(y,d-1)/v[y].size();
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n,d,x; cin >> n >> d >> p;

        v.clear(); v.resize(n, vector<int>());

        CHKVAL++;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> x;
                if(x) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int t; cin >> t;
        for(int i=0; i<t; i++) {
            cin >> x;
            printf("%.8lf ", f(x,d));
        }
        puts("");
    }
    return 0;
}