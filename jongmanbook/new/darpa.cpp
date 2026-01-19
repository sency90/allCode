#include <bits/stdc++.h>
using namespace std;
int N, M;
int pos[201];
bool Judge(int len) {
    int ins = pos[0];
    int cnt=1;
    for(int i=1; i<M; i++) {
        if(pos[i]-ins >= len) {
            ins = pos[i];
            cnt++;
            if(cnt>=N) return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> N >> M;

        double in;
        for(int i=0; i<M; i++) {
            cin >> in;
            pos[i]=(int)(in*1000.0);
        }
        int lo=0, hi=240000;

        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(Judge(mid)) lo = mid+1;
            else hi = mid-1;
        }
        printf("%.2lf\n", (double)(lo-1)/1000.0);
    }
    return 0;
}