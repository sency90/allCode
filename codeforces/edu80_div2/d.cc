#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
vector<vector<int>> a;
map<int,vector<int>> dic;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    a.clear(); a.resize(n, vector<int>(m));
    int mn=0x3f3f3f3f, mx=-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
            mn = min(mn, a[i][j]);
            mx = max(mx, a[i][j]);
        }
    }

    unsigned char mask = ((1<<m)-1);
    int lo=mn, hi=mx;
    int ansl, ansr;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        dic.clear();
        for(int i=0; i<n; i++) {
            int bit = 0;
            for(int j=0; j<m; j++) {
                if(a[i][j]>=mid) bit|=(1<<j);
            }
            dic[bit].push_back(i);
        }

        bool good =false;
        for(map<int,vector<int>>::iterator it = dic.begin(); it!=dic.end(); it++) {
            for(auto jt = it; jt!=dic.end(); jt++) {
                if((it->first | jt->first) == mask) {
                    good = true;
                    ansl = it->second[0];
                    ansr = jt->second[0];
                    break;
                }
            }
            if(good) break;
        }

        if(good) lo = mid+1;
        else hi = mid-1;
    }
    printf("%d %d\n", ansl+1, ansr+1);
    return 0;
}
